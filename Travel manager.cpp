#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;
void menu();
class ManageMenu
{
protected:
    string userName;//hide admin name

public:
    ManageMenu()
    {
        system("color 0A"); //change terminal colour
        cout<<"\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin:";
        cin>>userName;
        system("CLS");
        menu();
    }
    ~ManageMenu(){}

};

class Customer
{
public:
    string name,gender,address;
    int age,mobileno,menuBack;
    static int cusID;
    char all[999];

    void getDetails()
    {
        ofstream out("old-customer.txt",ios::app);
        {
            cout<<"\n enter customer ID:"<<endl;
            cin>>cusID;
            cout<<"\n enter name:"<<endl;
            cin>>name;
            cout<<"\n enter age:"<<endl;
            cin>>age;
            cout<<"\n enter mobile no:"<<endl;
            cin>>mobileno;
            cout<<"\n enter gender:"<<endl;
            cin>>gender;
            cout<<"\n enter address:"<<endl;
            cin>>address;
        }
        out<<"\n customer id:"<<cusID<<"\n name:"<<name<<"\n age:"<<age<<"\n mobile no"<<mobileno<<"\n gender"<<gender<<"\n address"<<address<<endl;
        out.close();
        cout<<"\n SAVED  \n NOTE : we saved your details record for future purpose \n"<<endl;

    }
    void showDetails()
    {
        ifstream in("old-customer.txt");
        {
            if(!in)
            {
                cout<<"file error"<<endl;

            }
            while(!(in.eof()))
            {
                in.getline(all,999);
                cout<<all<<endl;
            }
            in.close();
        }
    }
};
int Customer:: cusID;
class Cabs
{
public:
    int cabChoice;
    int kilometers;
    float cabCost,cabCost1;
    static float lastCabCost,lastCabCost1;

    void cabDetails()
    {
        cout<<"we collaborate with fastest,safest and smartest cab service arround the country"<<endl;
        cout<<"----------------------ABC cabs----------------------\n"<<endl;
        cout<<"1. Rent a standard Cab - Rs 15 for 1KM"<<endl;
        cout<<"2. Rent a luxury Cab- Rs 25 for 1KM"<<endl;

        cout<<"\nTo calculate the cost of your journey"<<endl;
        cout<<"Enter which kind of cab do you want"<<endl;
        cin>>cabChoice;
        cout<<"Enter kilometers do you want to travel"<<endl;
        cin>>kilometers;

        int hireCab;

        if(cabChoice==1)
        {
            cabCost= kilometers*15;
            cout<<"\n your tour cost " <<cabCost<< " for a standard cab"<<endl;
            cout<<"press 1 to hire this cab"<<endl;
            cout<<"press 2 to hire another cab"<<endl;
            cin>>hireCab;

            system("CLS");

            if(hireCab==1)
            {
                lastCabCost=cabCost;
                cout<<"\n You have successfully hired standard cab:"<<endl;
                cout<<"Goto menu and take the receipt"<<endl;
            }
            else if(hireCab==2)
            {
                cabDetails();
            }
            else
            {
                cout<<"invalid input! Redirecting to previous menu \n Please wait"<<endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else if(cabChoice==2)
        {
            cabCost1=kilometers*25;
            cout<<"\nYour tour will cost " <<cabCost1<< " rupees for a luxury cab"<<endl;
            cout<<"Press 1 to hire this cab:or";

            cout<<"Press 2 to select another cab:";
            cin>>hireCab;
            if(hireCab==1)
            {
                lastCabCost1==cabCost1;
                cout<<"\nYou have successfully hired luxury cab"<<endl;
                cout<<"Goto Menu to take the receipt"<<endl;
            }
            else if(hireCab==2)
            {

                cabDetails();
            }
            else
            {
                cout<<"Invalid Input! Redirecting to Previous menu \nPlease wait!"<<endl;
                Sleep(1100);
                system("CLS");
                cabDetails();

            }


        }
        else
        {
            cout<<"Invalid input! Redirecting to Main Menu \n Please wait"<<endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout<<"\nPress 1 to redirect main menu:"<<endl;
        cin>>hireCab;
        system("CLS");
        if(hireCab==2)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
};
float Cabs::lastCabCost;

class Booking
{
public:
    int choiceHotel;
    int packChoice;
    int gotoMenu;
    static float hotelCost;

    void hotels()
    {
        string hotelNo[] = {"Avendra","ChoiceYou","ElephantBay"};
        for (int i=0;i<3;i++)
        {
            cout<<(i+1)<<" .Hotel"<<hotelNo[i]<<endl;
        }
        cout<<"\n currently we are collaborated with above Hotels"<<endl;

        cout<<"Press any key to back or \n Press number of hotel you want to book:"<<endl;
        cin>>choiceHotel;
        system("CLS");

        if(choiceHotel==1)
        {
            cout<<" --------WELCOME TO HOTEL AVENDRA-------\n"<<endl;

            cout<<"The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun."<<endl;

            cout<<"Packages offered by Avendra:\n"<<endl;

            cout<<"1. Standard Pack"<<endl;
            cout<<"\t ALL basic facilities you need just for: Rs. 5000.00"<<endl;
            cout<<"2. Premium Pack"<<endl;
            cout<<"\t Enjoy Premium: Rs.10000.00"<<endl;
            cout<<"3. Luxury Pack"<<endl;
            cout<<"\t Live a Luxury at Avendra: Rs.15000.00"<<endl;

            cout<<"\n Press another key to back or \n Enter package number you want to book:"<<endl;
            cin>>packChoice;


            if (packChoice==1)
            {
                hotelCost==5000.00;
                cout<<"\nYou have successfully booked Standard Pack at Avendra"<<endl;
                cout<<"Goto Menu and take the receipt"<<endl;
            }
            else if(packChoice==2)
            {
                hotelCost==10000.00;
                cout<<"\nYou have successfully booked Premium Pack at Avendra"<<endl;
                cout<<"Goto Menu and take the receipt"<<endl;
            }
            else if(packChoice==3)
            {
                hotelCost==15000.00;
                cout<<"\nYou have successfully booked Luxury Pack at Avendra"<<endl;
                cout<<"Goto Menu to take the receipt"<<endl;
            }
            else
            {
                cout<<"Invalid Input! Redirecting to Previous Menu \n Please wait!"<<endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout<<"\nPress 1 to redirect main menu:";
            cin>>gotomenu;
            system("CLS");
            if(gotomenu==1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if(choiceHotel==2)
        {
            cout<<" --------WELCOME TO HOTEL CHOICE YOU-------\n"<<endl;

            cout<<"The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun."<<endl;

            cout<<"Packages offered by ChoiceYou:\n"<<endl;

            cout<<"1. Family Pack"<<endl;
            cout<<"\t ALL basic facilities you need just for: Rs. 15000.00"<<endl;
            cout<<"2. Couple Pack"<<endl;
            cout<<"\t Couple Pack: Rs.10000.00"<<endl;
            cout<<"3. Single Pack"<<endl;
            cout<<"\t Single pack: Rs.5000.00"<<endl;

            cout<<"\n Press another key to back or \n Enter package number you want to book:"<<endl;
            cin>>packChoice;

            if (packChoice==1)
            {
                hotelCost==15000.00;
                cout<<"\n You have successfully booked Family Pack at ChoiceYou"<<endl;
                cout<<"Goto Menu and take the receipt"<<endl;
            }
            else if(packChoice==2)
            {
                hotelCost==10000.00;
                cout<<"\nYou have successfully booked Couple Pack at ChoiceYou"<<endl;
                cout<<"Goto Menu and take the receipt"<<endl;
            }
            else if(packChoice==3)
            {
                hotelCost==5000.00;
                cout<<"\nYou have successfully booked Single Pack at ChoiceYou"<<endl;
                cout<<"Goto Menu to take the receipt"<<endl;
            }
            else
            {
                cout<<"Invalid Input! Redirecting to Previous Menu \n Please wait!"<<endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotoMenu;
            cout<<"\nPress 1 to redirect main menu:";
            cin>>gotoMenu;
            system("CLS");
            if(gotoMenu==1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if(choiceHotel==3)
        {
            cout<<"------WELCOME TO HOTEL ELEPHANTBAY------"<<endl;
            cout<<"Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants"<<endl;
            cout<<"Amazing offer in this summer: Rs.5000.00 for a one day!!!"<<endl;

            cout<<"\nPress another key to back or\n Press 1 to book this special package:";
            cin>>packChoice;

            if(packChoice==1)
            {
                hotelCost=5000.00;
                cout<<"You have successfully booked ElephantBay Special Pack"<<endl;
                cout<<"Goto Menu and take the receipt"<<endl;

            }
            else
            {
                cout<<"Invalid Input!Redirecting to Previous Menu \nPlease wait!"<<endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout<<"\nPress 1 to Redirect Main Menu:";
            cin>>gotoMenu;
            system("CLS");
            if(gotoMenu==1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            cout<<"Invalid Input! Redirecting to Previous Menu \nPlease wait!"<<endl;
            Sleep(1100);
            system("CLS");
            menu();

        }
    }
};
float Booking::hotelCost;
class Charges : public Booking, Cabs, Customer
{


public:
    void printBill()
    {

        ofstream outf("receipt.txt");
        {

            outf<<"----------ABC Travel Agency---------"<<endl;
            outf<<"-------------Receipt----------------"<<endl;
            outf<<"____________________________________"<<endl;

            outf<<"Customer ID: "<<Customer::cusID<<endl<<endl;
            outf<<"Description\t\t Total"<<endl;
            outf<<"Hotel cost:\t\t "<<fixed<<setprecision(2)<<Booking::hotelCost<<endl;
            outf<<"Travel (cab) cost:\t "<<fixed <<setprecision(2)<<Cabs::lastCabCost<<endl;

            outf<<"____________________________________"<<endl;
            outf<<"Total Charge:\t\t "<<fixed <<setprecision(2)<<Booking::hotelCost+Cabs::lastCabCost<<endl;
            outf<<"____________________________________"<<endl;
            outf<<"-------------THANK YOU--------------"<<endl;

        }
        outf.close();
    }
    void showBill()
    {

        ifstream inf("receipt.txt");
        {

            if(!inf)
            {
                cout<<"file opening error!"<<endl;
            }
            while(!(inf.eof()))
            {
                inf.getline(all,999);
                cout<<all<<endl;
            }
        }
        inf.close();
    }
};
void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;


    cout<<"\t\t         *ABC Travels  *\n"<<endl;
    cout<<"-----------------Main Menu-------------------"<<endl;

    cout<<"\t _____________________________________"<<endl;
    cout<<"\t|\t\t\t\t\t"<<endl;
    cout<<"\t|\tCustomer Management  ->1\t|"<<endl;
    cout<<"\t|\tCabs Management      ->2\t|"<<endl;
    cout<<"\t|\tbookings Management  ->3\t|"<<endl;
    cout<<"\t|\tCharges & Bill       ->4\t|"<<endl;
    cout<<"\t|\tExit                 ->5\t|"<<endl;
    cout<<"\t|\t\t\t\t\t"<<endl;
    cout<<"\t|_____________________________________"<<endl;

    cout<<"\nEnter Your Choice:";
    cin>>mainChoice;
    system("cls");
    Customer s2;
    Cabs s3;
    Booking s4;
    Charges s5;

    if(mainChoice==1)
    {
        cout<<"-------Customers------\n"<<endl;
        cout<<"1. Enter New Customer"<<endl;
        cout<<"2. See Old Customers"<<endl;

        cout<<"\tEnter Choice";
        cin>>inChoice;
        system("CLS");
        if(inChoice==1)
        {
            s2.getDetails();

        }
        else if(inChoice==2)
        {
            s2.showDetails();
        }
        else
        {
            cout<<"Invalid Input! Redirecting to Previous Menu \n Please wait!"<<endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout<<"\n Press 1 to Redirect main menu:";
        cin>>gotoMenu;
        system("CLS");
        if(gotoMenu==1)
        {

            menu();
        }
        else
        {
            menu();

        }

    }
    else if(mainChoice==2)
    {
        s3.cabDetails();

    }
    else if(mainChoice==3)
    {
        cout<<"--> Book luxury Hotel using the system<--"<<endl;
        s4.hotels();

    }
    else if(mainChoice==4)
    {
        cout<<"-->Get your receipt<--"<<endl;
        s5.printBill();

        cout<<"Your receipt is already printed you can get it from file path\n"<<endl;
        cout<<"To display the your receipt in the screen Enter 1: or Enter another key to back main menu:";

        cin>>gotoMenu;
        if(gotoMenu==1)
        {
            system("CLS");
            s5.showBill();
            cout<<"\nPress 1 to redirect main menu:";
            cin>>gotoMenu;
            system("CLS");
            if(gotoMenu==1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if(mainChoice==5)
    {
        cout<<"---GOOOD--BYE---"<<endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else
    {
        cout<<"Invalid Input! Redirecting to Previous Menu \n Please WAit!"<<endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}
int main()
{
    ManageMenu startObj;


    return(0);
}
