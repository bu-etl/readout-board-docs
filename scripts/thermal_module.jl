using Printf
using PrettyTables

aln_thickness = 2E-3                     # 2mm
pad_size      = 1.3E-3                   # 1.3mm
num_bumps     = 16*16                    # number of bumps
etroc_power   = 1                        # 1W
lgad_area     = (pad_size)^2*num_bumps*2 # area of an LGAD sensor
bump_r        = 0.5*90E-6                # 90um diameter

function conductance(; name, Q, k, t, A)
    c = k*A/t
    Δt = Q/c
    c_name  = @sprintf "%s Conductance" name
    Δt_name = @sprintf "%s Δt" name
    cs      = @sprintf "%0.3F W/K" c
    Δts     = @sprintf "%0.4F K" Δt
    return [c_name, cs, Δt_name, Δts]
end

function calcs(;bump_k, bump_t, etroc_q, si_k, si_t, epoxy_k, epoxy_t, aln_k)
    arr=[]
    append!(arr,conductance(name="Single Bump",          Q=etroc_q/num_bumps,      k=bump_k,  t=bump_t,        A=pi*bump_r^2))
    append!(arr,conductance(name="All bumps",            Q=etroc_q,                k=bump_k,  t=bump_t,        A=num_bumps*pi*bump_r^2))
    append!(arr,conductance(name="Sensor",               Q=2*etroc_q,              k=si_k,    t=si_t,          A=lgad_area))
    append!(arr,conductance(name="Epoxy",                Q=2*etroc_q,              k=epoxy_k, t=epoxy_t,       A=lgad_area))
    append!(arr,conductance(name="AlN",                  Q=2*etroc_q,              k=aln_k,   t=aln_thickness, A=lgad_area))
    append!(arr,conductance(name="Silicon (horizontal)", Q=0.25*etroc_q/num_bumps, k=si_k,    t=pad_size/2,    A=pad_size/2*si_t))
    return arr
end

frank  = calcs(bump_k=70, bump_t=100E-6, etroc_q=1.0, si_k=150, si_t=300E-6, epoxy_k=0.22, epoxy_t= 500E-6, aln_k=160)
david  = calcs(bump_k=60, bump_t=150E-6, etroc_q=1.0, si_k=191, si_t=200E-6, epoxy_k=1.33, epoxy_t=1000E-6, aln_k=200)
test   = calcs(bump_k=60, bump_t=150E-6, etroc_q=1.0, si_k=191, si_t=200E-6, epoxy_k=7.90, epoxy_t=1000E-6, aln_k=200)

headings=["Parameter","Frank","David","Test"]
table=vcat(frank[1:2:end], frank[2:2:end], david[2:2:end], test[2:2:end])
x=length(headings)
y=Int(length(table)/x)
q=reshape(table,(y,x))
pretty_table(q,headings,alignment=:l)
pretty_table(q,headings,backend=:latex,alignment=:l)
