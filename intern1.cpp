#include <iostream>
using namespace std;

int main()
{
    float t;
    char temp;
    float c,f,k;
    cout<<"Enter temperature: ";
    cin>>t;
    cout<<"Enter scale: ";
    cin>>temp;
    switch(temp)
    {
        case 'F':
        {
           c=((t-32)*5)/9;
           k=c+273.15;
           cout<<"Celsius: "<<c<<endl;
           cout<<"Kelvin: "<<k<<endl;
           break;
        }
        case 'C':
        {
           f=(9*t)/5+32;
           k=t+273.15;
           cout<<"Farenheit: "<<f<<endl;
           cout<<"Kelvin: "<<k<<endl;
           break;
        }
        case 'K':
        {
           c=t-273.15;
           f=(9*c)/5+32;
           cout<<"Celsius: "<<c<<endl;
           cout<<"Farnheit: "<<f<<endl;
           break;
        }

        default:
        {
            cout<<"Enter valid temperature unit"<<endl;
        }
    }
}