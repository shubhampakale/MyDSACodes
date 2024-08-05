#include <bits/stdc++.h>
using namespace std;

void pointer()
{
    int x = 20;
    cout<<x<<endl;

    cout<< &x <<endl;     //address of x where 20 is stored 

    int *ptr = &x;
    cout<< ptr <<endl;    //address of x

    cout<< *ptr <<endl;   // stored value 
    cout<< &ptr <<endl;   // address of ptr

    int **ptr1 = &ptr;
    cout<< ptr1 <<endl;   //address of ptr
    cout<< *ptr1 <<endl;  //value of ptr1 i.e address of x
    cout<< **ptr1 <<endl; // value stored 
}

struct student
{
    string name;
    int roll;
    float percent;

    void showDetails()
    {
        cout<<"Name is "<<name<<endl;
        cout<<"Roll is "<<roll<<endl;
        cout<<"Percent is "<<percent<<endl;
    }
};


int main()
{
    //pointer();
    
    student shubh = {"shubh",156,98.0};

    shubh.showDetails();

    return 0;
}