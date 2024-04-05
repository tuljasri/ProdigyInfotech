#include <iostream>
#include <random>
using namespace std;

int main()
{
    int x;
    int count=0;
    srand(time(0));
    x=rand()%200;
    bool guess=false;
    int num;
    while(guess==false)
    {
        cout<<"Guess a number: ";
        cin>>num;
        if(x<num)
        {
            cout<<"Guess is too high";
        }
        else if(x>num)
        {
            cout<<"Guess is too low";
        }
        else
        {
            guess=true;
        }
        count++;
    }
    cout<<"You guessed correctly!"<<endl;
    cout<<"Number of attempts: "<<count;
}
