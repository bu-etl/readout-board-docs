import numpy as np

##
## Default values for Sn bump bonds
##
k_Sn = 70 ## W/m/K
h = 100*10**(-6) ## 100 um bump bond height
A = 0.25*np.pi*(90*10**(-6))**2 ## assume contact area is roughly circular with 90 um diameter
Nb = 16*16 ## number of bump bonds per ETROC
Q = 1 ## heat dissipated by a single ETROC, in W

## thermal conductance of bumps on a single ETROC
c_bump  = k_Sn*A/h
c_etroc = c_bump*Nb
print('Thermal conductance of bump bonds on a single ETROC: {:.2f} W/K'.format(c_etroc))

## thermal conductance of bumps on a single LGAD
c_lgad = 2*c_etroc
print('Thermal conductance of bump bonds on an LGAD sensor: {:.2f} W/K'.format(c_lgad))

## temperature difference between ETROC and LGAD
dT = Q/c_etroc
print('Temperature difference between LGAD and ETROC (across bumps): {:.2f} K'.format(dT))

## calculate temperature difference across Si
k_Si = 150 ## W/m/K
t_Si = 300*10**(-6) ## assume 300 um thick sensor
A_lgad = (1.3*10**(-3))**2 * Nb * 2 ## area of one LGAD sensor with 256*2 = 512 pads, 1.3 x 1.3 mm^2 in size
c_Si = k_Si*A_lgad/t_Si
print('Thermal conductance of LGAD sensor: {:.2f} W/K'.format(c_Si))

dT_Si = 2*Q/c_Si
print('Temperature difference across LGAD sensor: {:.2f} K'.format(dT_Si))

## calculate temperature difference across Araldite
## from here: https://www.intertronics.co.uk/wp-content/uploads/2015/12/ara2011.pdf
k_epoxy = 0.22 ## W/m/K for Araldite
t_epoxy = 500*10**(-6) ## assume 500 um thick epoxy layer
c_epoxy = k_epoxy*A_lgad/t_epoxy
print('Thermal conductance of epoxy: {:.2f} W/K'.format(c_epoxy))

dT_epoxy = 2*Q/c_epoxy
print('Temperature difference across epoxy layer: {:.2f} K'.format(dT_epoxy))

# now calculate the temperature difference across the AlN
k_AlN = 160 ## W/m/K
t_AlN = 2*10**(-3) ## 2 mm thickness
c_AlN = k_AlN*A_lgad/t_AlN
print('Thermal conductance of AlN: {:.2f} W/K'.format(c_AlN))

## temperature difference across AlN
dT_AlN = 2*Q/c_AlN
print('Temperature difference across AlN: {:.2f} K'.format(dT_AlN))

## calculate tenperature gradient within Si
d_Si = 1.3*10**(-3) * 0.5
A_Si = t_Si*d_Si
c_withinSi = k_Si*A_Si/t_Si
print('Thermal conductance between bumps within Si: {:.2f} W/K'.format(c_withinSi))

dT_withinSi = 1./Nb/c_withinSi ## this is a conservative estimate as the heat has multiple (4) paths to go
print('Temperature difference between bumps within Si: {:.2f} K'.format(dT_withinSi))
