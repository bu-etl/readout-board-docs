{
    float pi = 3.14; // close enough for govt. work

    // Calculate the heat flow through the bump bonds

    float r_bump = 0.5*90.E-6; // Radius of a bump bond [m]
    float area_bump = pi*r_bump*r_bump;
    float h_bump = 150.E-6; // Height of a bump [m]
    float k_bump = 60.; // Thermal conductivity of a bump [W/mK]
    float c_bump = (k_bump/h_bump)*area_bump; // Thermal conductance of a single bump [W/K]
    int n_bumps = 16*16; // Number of bumps per ETROC
    float q_ETROC = 1.; // Power of a single ETROC
    float Tdiff_bumps = (q_ETROC/n_bumps)/c_bump; // Temperature difference due to ETROC heat flow

    cout << "Thermal conductance of a single bump = " << c_bump << " [W/K]\n";
    cout << "Thermal conductance of all bumps on an ETROC = " << c_bump*n_bumps << " [W/K]\n";
    cout << "Thermal conductance of all bumps on an LGAD = " << c_bump*n_bumps*2 << " [W/K]\n";
    cout << "Temperature difference between ETROC and LGAD = " << Tdiff_bumps << "\n";

    // Repeat the bump bond calculation with Roberta's assumptions
    area_bump = 4*r_bump*r_bump;
    h_bump = 70.E-6;
    k_bump = 66;
    c_bump = (k_bump/h_bump)*area_bump; // Thermal conductance of a single bump [W/K]
    Tdiff_bumps = (q_ETROC/n_bumps)/c_bump; // Temperature difference due to ETROC heat flow
    cout << "RA: Thermal conductance of a single bump = " << c_bump << " [W/K]\n";
    cout << "RA: Thermal conductance of all bumps on an ETROC = " << c_bump*n_bumps << " [W/K]\n";
    cout << "RA: Thermal conductance of all bumps on an LGAD = " << c_bump*n_bumps*2 << " [W/K]\n";
    cout << "RA: Temperature difference between ETROC and LGAD = " << Tdiff_bumps << "\n";

    // Calculate the heat flow through the AlN, epoxy, and silicon thickness to the Al cooling plate

    float k_AlN = 200; // AlN thermal conductivity. Probably conservative [W/mK]
    float t_AlN = 2.E-3; // AlN thickness [m]
    float area_AlN = n_bumps*2*1.3*1.3*1.E-6; 
    float c_AlN = (k_AlN/t_AlN)*area_AlN; // Thermal conductance of the AlN cover [W/K]
    float Tdiff_AlN = (q_ETROC*2)/c_AlN; // Temperature difference due to ETROC heat flow
    cout << "Thermal conductance of AlN = " << c_AlN << " [W/K]\n";
    cout << "Temperature difference across AlN = " << Tdiff_AlN << "\n";

    float k_epoxy = 1.3; // epoxy thermal conductivity. Probably conservative [W/mK]
    float t_epoxy = 1.E-3; // epoxy thickness [m]
    float area_epoxy = area_AlN;
    float c_epoxy = (k_epoxy/t_epoxy)*area_epoxy; // Thermal conductance of the epoxy layer [W/K]
    float Tdiff_epoxy = (q_ETROC*2)/c_epoxy; // Temperature difference due to ETROC heat flow
    cout << "Thermal conductance of epoxy = " << c_epoxy << " [W/K]\n";
    cout << "Temperature difference across epoxy = " << Tdiff_epoxy << "\n";

    float k_silicon = 191.; // silicon thermal conductivity. [W/mK]
    float t_silicon = 200.E-6; // silicon thickness [m]
    float area_silicon = area_AlN;
    float c_silicon = (k_silicon/t_silicon)*area_silicon; // Thermal conductance of the silicon [W/K]
    float Tdiff_silicon = (q_ETROC*2)/c_silicon; // Temperature difference due to ETROC heat flow
    cout << "Thermal conductance of silicon thickness = " << c_silicon << " [W/K]\n";
    cout << "Temperature difference across silicon thickness = " << Tdiff_silicon << "\n";

    // Calculate the heat flow horizontally through the silicon to understand temperature gradients across the LGAD
    float t_siliconHoriz = (1.3E-3)/2;
    float area_siliconHoriz = t_silicon*(1.3E-3)/2;
    float c_siliconHoriz = (k_silicon/t_siliconHoriz)*area_siliconHoriz; // Thermal conductance of the silicon [W/K]
    float Tdiff_siliconHoriz = (0.25*q_ETROC/n_bumps)/c_siliconHoriz; // Temperature difference due to ETROC heat flow
    cout << "Thermal conductance of silicon horizontally = " << c_siliconHoriz << " [W/K]\n";
    cout << "Temperature difference across silicon horizontally = " << Tdiff_siliconHoriz << "\n";


    // Calculate the heat flow through FR4
    float k_FR4 = 0.25; // FR4 thermal conductivity. [W/mK]
    float t_FR4 = 400.E-6; // FR4 thickness [m]
    float area_FR4 = area_AlN;
    float c_FR4 = (k_FR4/t_FR4)*area_FR4; // Thermal conductance of the FR4 [W/K]
    float Tdiff_FR4 = (q_ETROC*2)/c_FR4; // Temperature difference due to ETROC heat flow
    cout << "Thermal conductance of FR4 = " << c_FR4 << " [W/K]\n";
    cout << "Temperature difference across FR4 = " << Tdiff_FR4 << "\n";

    // Calculate the heat flow through FR4 vias
    float k_vias = 300; // via's copper thermal conductivity. [W/mK]
    float t_vias = 400.E-6; // via thickness [m]
    float area_vias = 2*n_bumps*2*pi*(0.5*100.E-6)*(0.5*100.E-6);
    float c_vias = (k_vias/t_vias)*area_vias; // Thermal conductance of the vias [W/K]
    float Tdiff_vias = (q_ETROC*2)/c_vias; // Temperature difference due to ETROC heat flow
    cout << "Thermal conductance of vias = " << c_vias << " [W/K]\n";
    cout << "Temperature difference across vias = " << Tdiff_vias << "\n";

}
