#include <iostream>
#include <cassert>

using namespace std;

const double l_m3 = 0.001;
const double q_m3 = 0.000946353;
const double in3_m3 = .0000163871;
const double m3_oz = 33810;
const double oz_m3 = .0000295735;
const double m3_in3 = 61023.7;
const double lb_kg = 0.453592;
const double iceDensity = 916.8; //kg/m^3
const double waterDensity = 1; //L/kg
const double canDensity = 1000; //kg/m^3
const double airDensity = 1.135; //at 100F, kg/m^3
const double iceHeatCapacity = 2100; //J/(kg K)
const double waterHeatCapacity = 4184; //J/(kg K)
const double fusionIceToWater = 333550; // J/kg
const double airHeatCapacity = 1005; //J(kg K)

double quarts_to_m3(double quarts) //Measurement of cooler volume
{
    double m3 = quarts * q_m3;

    return m3;
}
double liters_to_m3(double liters) //Measurement of cooler volume
{
    double m3 = liters * l_m3;

    return m3;
}
double in3_to_m3(double in3) //Measurement of cooler volume
{
    double m3 = in3 * in3_m3;

    return m3;
}

double m3_to_12ozcans(double m3) //Measurement of cans in cooler
{
    double cans = (m3 * m3_oz) / 12;

    return cans;
}
double ozcans_to_m3(double cans) //Measurement of volume of cans
{
    double m3cans = (cans * 12) * oz_m3;

    return m3cans;
}
double m3cans_to_kg (double m3cans)
{
    double kgOfCans = m3cans * canDensity;

    return kgOfCans;
}
double m3_to_in3(double m3) //Measurement of cooler volume
{
    double in3 = m3 * m3_in3;

    return in3;
}


double degF_to_degC(double degF) //Temperature
{
    double degC = (degF - 32) * (5.0 / 9.0);

    return degC;
}
double degC_to_degF(double degC) // Temperature
{
    double degF = (degC * (9.0 / 5.0)) + 32;

    return degF;
}


double m3ice_to_kg(double m3ice) //Measurement of ice volume to weight
{
    double icekg = m3ice * iceDensity;

    return icekg;
}
 double kgice_to_m3(double icekg) //Measurement of ice weight to volume
{
    double m3ice = icekg / iceDensity;

    return m3ice;
}
double lbsice_to_kg(double poundsOfIce) //Conversion of pounds to kilos
{
    double icekg =  poundsOfIce * lb_kg;

    return icekg;
}

double m3H2O_to_kg(double m3H2O) //Measurement of water volume to weight
{
    double H2Okg = m3H2O * waterDensity;

    return H2Okg;
}
double m3air_to_kg(double m3air) //Measurement of air volume to weight
{
    double airkg = m3air * airDensity;
    
    return airkg;
}
double iceHeatEnergywarm(double kgOfIce, double degC)
{
    double HEicewarm = kgOfIce * iceHeatCapacity * (0 - degC);

    return HEicewarm;
}
double iceHeatEnergymelt(double kgOfIce)
{
    double HEicemelt = kgOfIce * fusionIceToWater;

    return HEicemelt;
}
double iceHeatEnergyTo0(double HEicemelt, double HEicewarm)
{
    double HEiceto0 = HEicewarm + HEicemelt;

    return HEiceto0;
}
double HEContents (double airkg, double kgofcan, double tempOfCans)
{
    double HEcontents = airkg * airHeatCapacity * (degF_to_degC(100) - 0) + kgofcan * waterHeatCapacity * (tempOfCans - 0);

    return HEcontents;
}

double HETotal(double HEcontents, double HEicemelt)
{
    double HEtotal = HEcontents - HEicemelt;

    return HEtotal;
}

double tempFinal (double kgOfIce, double degC, double kgOfCans, double tempOfCans, double airkg)
{
    double tempfinal = (kgOfIce * waterHeatCapacity * degC + kgOfCans * airHeatCapacity * 100) / (kgOfice * waterHeatCapacity + kgOfCans * waterHeatCapacity + airkg * airHeatCapacity);

    return tempfinal;
}


int main()
{
    string measurement, tempUnit, canUnit;
    double quarts, liters, in3, poundsOfIce, degF, degC, m3, m3ice, kgOfIce, airkg, HEicewarm, HEicemelt, HEiceto0, HEcontents, kgOfCans, tempOfCans, HEtotal, tempfinal;
    bool valid = false; 
    bool iceValid = false;
    bool tempValid = false;
    bool cansValid = false;
    bool tempOfCansValid = false;
    int cans;
    do
    {
        cout << "Enter the desired measurement, quarts (q), liters(l), or cubic inches (in3):"; 
        cin >> measurement;

        if(measurement == "q")
        {
            cout << "Enter the volume of cooler in quarts:";
            cin >> quarts;
            
            cout << "The volume of the cooler in meters cubed is:" << quarts_to_m3(quarts) << endl;
            m3 = quarts_to_m3(quarts);
            valid = true;
        }
        else if(measurement == "l")
        {
            cout << "Enter the volume of cooler in liters:";
            cin >> liters;

            cout << "The volume of the cooler in meters cubed is:" << liters_to_m3(liters) << endl;
            m3 = liters_to_m3(liters);
            valid = true;
        }
        else if(measurement == "in3")
        {
            cout << "Enter the volume of cooler in inches cubed:";
            cin >> in3;

            cout << "The volume of the cooler in meters cubed is:" << in3_to_m3(in3) << endl;
            m3 = in3_to_m3(in3);
            valid = true;
        }
        else
        {
            cout << "Invalid measurement type." << endl;
        }
    } while (valid == false);

    do
    {
        cout << "Please select Fahrenheit (F) or Celsuis (C):";
        cin >> tempUnit;

        if(tempUnit == "F" || tempUnit == "f")
        {
            cout << "Enter starting temperature of ice:";
            cin >> degF;

            degC = degF_to_degC(degF);

            tempValid = true;
        }
        else if(tempUnit == "C" || tempUnit == "c")
        {
            cout << "Enter starting temperature of ice:";
            cin >> degC;
            
            
            tempValid = true;
        }
        else
        {
            cout << "Invalid measurement type." << endl;
        }
    } while (tempValid == false);

    do
    {
        cout << "Input ice amount in pounds:";
        cin >> poundsOfIce;

        if(poundsOfIce > 0)
        {
            iceValid = true;
            kgOfIce = lbsice_to_kg(poundsOfIce);

            cout << kgOfIce << endl;
        }
        else
        {
            cout << "Invalid input" << endl;
    
        }
    } while(iceValid == false);
    
    m3ice = kgice_to_m3(kgOfIce);
    cout << m3ice << endl;

    do
    {
        cout << "Input number of cans you wish to cool:";
        cin >> cans;

        if(cans > 0)
        {
            cansValid = true;
        }
        else
        {
            cout << "Invalid input." << endl;
        }
    } while(cansValid == false);

    do
    {
        cout << "Do you wish to enter can temperature if Fahrenheit (F) or Celsiuis (C)?";
        cin >> canUnit;
        cout << "Enter temperature of cans";
        cin >> tempOfCans;

        if(canUnit == "F" || canUnit == "f")
        {
            tempOfCans = degF_to_degC(tempOfCans);
            
            tempOfCansValid = true;
        }
        else if (canUnit == "C" || canUnit == "c")
        {

            tempOfCansValid = true;
        }
        else
        {
            cout << "Invalid Input." << endl;
        }
    } while(tempOfCansValid == false);
    


    // HEAT CONVERSION CALCULATIONS

    
    /* Compute the volume of the cooler remaining Total Volume - (volume of ice + volume of cans)
    if total volume <= 0 tell user, exit
    else continue */
    double remainingVolume = m3 - kgice_to_m3(kgOfIce) - ozcans_to_m3(cans);
    
    if (remainingVolume = 0)
    {
        cout << "There is no space left in the cooler. Goodbye!" << endl;
        exit();
    }
    else if (remainingVolume < 0)
    {
        cout << "There is not enough space in the cooler for all contents. Goodbye!" << endl;
        exit();
    }

    /* Compute mass of air in kg */
    airkg = m3air_to_kg(remainingVolume);
    cout << airkg << endl;

    /* Compute the change in heat energy to warm the ice to 0 C.
    Change in heat energy to warm ice = mass of icee * heat capacity of ice (0 C - Temperature of Ice)*/
    HEicewarm = iceHeatEnergywarm(kgOfIce, degC);

    /* Compute the change in heat energy to melt the ice.
    Change in heat energy to melt ice = mass of ice * Heat of fusion of ice-to-water*/
    HEicemelt = iceHeatEnergymelt(kgOfIce);

    /* Compute change in heat energy ice to water.
    Change in heat energy to warm ice to 0 C + Change in heat energy to melt the ice*/
    HEiceto0 = iceHeatEnergyTo0(HEicemelt, HEicewarm);

    /*Compute the sum of the change in heat to cool the air and water to 0 C.
    Change in heat energy of contents = massair * heat capacity of air *(Temp of air - 0C) + massdrinks * heat capacity of water *(Temperature of drinks - 0C)*/
    HEcontents = HEContents(airkg, kgOfCans, tempOfCans);

    /*Compute the total
    Change in heat energy total = change in heat energy of contents - heat energy ice to water*/
    HEtotal = HETotal(HEcontents, HEicemelt);

    if (HEtotal < 0)
    {
        cout << "You have extra cooling power." << endl;
    }
    else
    {
        tempfinal = tempFinal(kgOfIce, degC, kgOfCans, tempOfCans, airkg);

        cout << "The ice has melted, the final temperature is " << tempfinal << "." << endl;
    }


    

}