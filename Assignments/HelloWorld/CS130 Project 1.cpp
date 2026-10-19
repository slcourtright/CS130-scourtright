#include <iostream>
#include <cassert>

using namespace std;

const double l_m3 = 0.001;
const double q_m3 = 0.000946353;
const double iceDensity = 916.8; //kg/m^3
const double waterDensity = 1; //L/kg
const double airDensity = 1.135; //at 100F, kg/m^3
const double iceHeatCapacity = 2100; //J/(kg K)
const double waterHeatCapacity = 4184; //J/(kg K)
const double fusionIceToWater = 333550; // J/kg
const double airHeatCapacity = 1005; //J(kg K)

double quarts_to_m3(double quarts)
{
    double m3 = quarts * q_m3;

    return m3;
}
double liters_to_m3(double liters)
{
    
}
double in3_to_m3(double in3);

double m3_to_12ozcans(double m3);
double m3_to_in3(double m3);

double degf_to_degC(double degF);
double degc_to_degf(double degC);

double m3ice_to_kg(double m3ice);
double m3H2O_to_kg(double m3H2O);
double m3air_to_kg(double m3air);


int main()
{
    string measurement, tempUnit;
    double quarts, liters, in3, poundsOfIce, degF, degC, m3;
    bool valid = false; 
    bool iceValid = false;
    bool tempValid = false;
    do
    {
        cout << "Enter the desired measurement, quarts (q), liters(l), or cubic inches (in3):"; 
        cin >> measurement;

        if(measurement == "q")
        {
            cout << "Enter the volume of cooler in quarts:";
            cin >> quarts;
            
            cout << "The volume of the cooler in meters cubed is:" << quarts_to_m3(quarts) << endl;
            valid = true;
        }
        else if(measurement == "l")
        {
            cout << "Enter the volume of cooler in liters:";
            cin >> liters;

            //cout << "The volume of the cooler in meters cubed is:" << liters_to_m3(liters) << endl;
            valid = true;
        }
        else if(measurement == "in3")
        {
            cout << "Enter the volume of cooler in inches cubed:";
            cin >> in3;

            //cout << "The volume of the cooler in meters cubed is:" << in3_to_m3(in3) << endl;
            valid = true;
        }
        else
        {
            cout << "Invalid measurement type." << endl;
        }
    } while (valid == false);

    do
    {
        cout << "Input ice amount in pounds:"; //move this to after asking for starting temp of ice.
        cin >> poundsOfIce;

        if(poundsOfIce > 0)
        {
            iceValid = true;
        }
        else
        {
            cout << "Invalid input" << endl;
    
        }
    } while(iceValid == false);
    do
    {
        cout << "Please select Fahrenheit (F) or Celsuis (C):";
        cin >> tempUnit;

        if(tempUnit == "F" || tempUnit == "f")
        {
            cout << "Enter starting temperature of ice:";
            cin >> degF;

            //degC = degF_to_degC(degF);
            tempValid = true;
        }
        else if(tempUnit == "C" || tempUnit == "c")
        {
            tempValid = true;
        }
        else
        {
            cout << "Invalid measurement type." << endl;
        }
    } while (tempValid == false);
    /* cout << "Volume of ice in meter cubed is:" << kg_to_m3(kgOfIce) << endl;
    cout << "Weight of ice in kilograms is:" << pounds_tokg(poundsOfIce) << endl;
    cout << "Temperature of ice in celisus is:" << degC << endl; */


    // HEAT CONVERSION CALCULATIONS

    /* Compute the volume of the cooler remaining Total Volume - (volume of ice + volume of cans)
    if total volume <= 0 tell user, exit
    else continue */

    /* Compute mass of air in kg */

    /* Compute the change in heat energy to warm the ice to 0 C.
    Change in heat energy to warm ice = mass of icee * heat capacity of ice (0 C - Temperature of Ice)*/

    /* Compute the change in heat energy to melt the ice.
    Change in heat energy to melt ice = mass of ice * Heat of fusion of ice-to-water*/

    /* Compute change in heat energy ice to water.
    Change in heat energy to warm ice to 0 C + Change in heat energy to melt the ice*/

    

}