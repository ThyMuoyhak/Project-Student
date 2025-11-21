#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string>
#include<windows.h>
#include <algorithm>
#include <chrono>
#include <thread> 

using namespace std;
//start Daro
class Hospital{
    protected:
        int age, pin, room = 0,floor = 0;
        string id, name, address, contact, position,dob;
        char gender, building = '0';
    public: 
        void hospital_management_staff();
        void input();
        void output();
        void search();
        void del();
        void update();
        void File_Input();
        void Menu();
        void menu_update();
        void Add();
        void list_room();
};
void Hospital::Menu(){
    system("Color 0A"); 
    cout<<"\n==========>> Management System <<=========="<<endl<<endl;
    cout<<"\t#################################"<<endl;
    cout<<"\t#\t[1]. Input Option       #"<<endl;
    cout<<"\t#################################"<<endl;
    cout<<"\t#\t[2]. Output Option      #"<<endl;
    cout<<"\t#################################"<<endl;
    cout<<"\t#\t[3]. Search Option      #"<<endl;
    cout<<"\t#################################"<<endl;
    cout<<"\t#\t[4]. Delete Option      #"<<endl;
    cout<<"\t#################################"<<endl;
    cout<<"\t#\t[5]. update Option      #"<<endl;
    cout<<"\t#################################"<<endl;
    cout<<"\t#\t[6]. Go Back            #"<<endl;
    cout<<"\t#################################"<<endl;
}
void Hospital::hospital_management_staff(){
    p:
    system("CLS");
    int choice;
    Menu();
    cout<<"\tEnter your choice: "; cin>>choice;
    switch(choice){
        case 1:
            input();
            break;
        case 2:
            output();
            break;
        case 3:
            search();
            break;
        case 4:
            del();
            break;
        case 5:
            update();
            break;
        case 6:
            break;
        default:
        cout << "\033[1;31m"; 
            cout<<"\tInvalid Value...Please Try Again...";
    }
    getch();
}
void Hospital::File_Input(){
    fstream file;
    int p,a,r,r1,f;
    float b;
    string n,g,add,po,i,c,d;
    char bu;
    file.open("Staff_A.txt", ios::in);
    if(!file){
        file.open("Staff_A.txt", ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
        file.close();
    }else{
        file>>i>>n>>g>>a>>add>>d>>c>>po>>bu>>r>>f;
        while(!file.eof()){
            if(i==id && r == room){
                Again:
                cout << "\033[1;31m"; 
                cout<<"ID and Room is Already Exist..."<<endl;
                cout<<"\tInput ID: "; cin>>id;
                list_room();
                if(i == id && r == room){
                    goto Again;
                }
            }else if(r == room){
                ROOM:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                list_room();
                if(r==room){
                    goto ROOM;
                }
            }else if(i==id){
                ID:
                cout << "\033[1;31m"; 
                cout<<"\tUser ID is Already Exist..."<<endl;
                cout<<"\tInput ID: "; cin>>id;
                if(i == id){
                    goto ID;
                }
            }
            //read file
            file>>i>>n>>g>>a>>add>>d>>c>>po>>bu>>r>>f;
        }
        file.close();
        file.open("Staff_A.txt", ios::app|ios::out);
        //write date file
        file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
        file.close();
    }
}
void Hospital::Add(){
    cout<<"\tEnter ID: "; cin>>id;
    cout<<"\tEnter Name: "; cin>>name;
    cout<<"\tEnter Gender: "; cin>>gender;
    cout<<"\tEnter age: "; cin>>age;
    cout<<"\tEnter Address:"; cin>>address;
    cout<<"\tEnter DOB: "; cin>>dob;
    cout<<"\tEnter Contact: "; cin>>contact;
    cout<<"\tEnter Position: "; cin>>position;
}
void Hospital::list_room(){
    p:
    cout<<"\tEnter Room(1-200): "; cin>>room;
        if(room>=1 && room <=10){
            floor = 1;
        }else if( room>=11 && room <=20){
            floor = 2;
        }else if(room >= 21 && room <= 30){
            floor = 3;
        }else if(room >= 31 && room <= 40){
            floor = 4;
        }else if(room >= 41 && room <= 50){
            floor = 5;
        }else if(room >= 51 && room <= 60){
            floor = 6;
        }else if(room >= 61 && room <= 70){
            floor = 7;
        }else if(room >= 71 && room <= 80){
            floor = 8;
        }else if(room >= 81 && room <= 90){
            floor = 9;
        }else if(room >= 91 && room <= 100){
            floor = 10;
        }else if(room >= 101 && room <= 110){
            floor = 11;
        }else if(room >= 111 && room <= 120){
            floor = 12;
        }else if(room >= 121 && room <= 130){
            floor = 13;
        }else if(room >= 131 && room <= 140){
            floor = 14;
        }else if(room >= 141 && room <= 150){
            floor = 15;
        }else if(room >= 151 && room <= 160){
            floor = 16;
        }else if(room >= 161 && room <= 170){
            floor = 17;
        }else if(room >= 171 && room <= 180){
            floor = 18;
        }else if(room >= 181 && room <= 190){
            floor = 19;
        }else if(room >= 191 && room <= 200){
            floor = 20;
        }else{
            cout << "\033[1;31m"; 
            cout<<"\tRoom don't have!"<<endl;
            goto p;
        }
        system("Color 0A");
}
void Hospital::input(){
    system("CLS");
    system("Color 0A"); 
    fstream file;
    int p,a,r,r1,f;
    float b;
    string n,g,add,po,i,c,d;
    char bu;
    p:
    cout<<"==========>> Add Staff_A <<==========\n"<<endl;
    Add();
    buildA:
    cout<<"\tEnter Building(A): "; cin>>building;
    if(building == 'A' || building == 'a'){
        list_room();
    }else{
        cout<<"\tPlease Enter A"<<endl;
        goto buildA;
    }
    File_Input();
    system("Color 0A"); 
    cout<<"\tNew User Information Created Successfully..."<<endl;
}
void Hospital::output(){
    system("CLS");
    fstream file;
    int found = 0;
    cout<<"\t==========>> Output <<=========="<<endl<<endl;
    file.open("Staff_A.txt", ios::in); //បញ្ចេញទិន្នន័យចេញពីFile
    if(!file){
        cout<<"File Openning Error...!"<<endl;
    }else{
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
        while(!file.eof()){
            cout<<"\n\tID        : "<<id<<endl;
            cout<<"\tName      : "<<name<<endl;
            cout<<"\tGender    : "<<gender<<endl;
            cout<<"\tAge       : "<<age<<endl;
            cout<<"\tAddress   : "<<address<<endl;
            cout<<"\tDOB       : "<<dob<<endl;
            cout<<"\tContact   : "<<contact<<endl;
            cout<<"\tPosition  : "<<position<<endl;
            cout<<"\tBuilding  : "<<building<<endl;
            cout<<"\tRoom      : "<<room<<endl;
            cout<<"\tFloor     : "<<floor<<endl;
            cout<<"\n\t====================================="<<endl;
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
            found++;
        }
        file.close();
        if(found == 0){
            cout<<"\nData base is Empty...!"<<endl;
        }
    }
}
void Hospital::search(){
    system("CLS");
    fstream file;
    string t_id;
    int found = 0;
    cout<<"\t==========>> Search <<=========="<<endl;
    file.open("Staff_A.txt", ios::in);//បញ្ចេញទិន្នន័យចេញពីFile
    if(!file){
        cout<<"\n\tFile Opening Error...!"<<endl;
    }else{
        cout<<"\tInput ID for search: "; cin>>t_id;
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
    while(!file.eof()){ //end of file
        if(t_id==id){
            system("CLS");
            cout<<"\t==========>> Search User <<=========="<<endl<<endl;
            cout<<"\tID: "<<id<<endl;
            cout<<"\tName: "<<name<<endl;
            cout<<"\tGender: "<<gender<<endl;
            cout<<"\tAge: "<<age<<endl;
            cout<<"\tAddress: "<<address<<endl;
            cout<<"\tDOB: "<<dob<<endl;
            cout<<"\tContact: "<<contact<<endl;
            cout<<"\tPosition: "<<position<<endl;
            cout<<"\tBuilding: "<<building<<endl;
            cout<<"\tRoom: "<<room<<endl;
            cout<<"\tFloor: "<<floor<<endl;
            found++;
        }
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
    }
    file.close();
    if(found == 0){
        cout << "\033[1;31m"; 
        cout<<"\nUser ID can't Found...!"<<endl;
    }
    }
}

void Hospital::menu_update(){
    cout<<"\t [1]. Update ID"<<endl;
        cout<<"\t [2]. Update Name"<<endl;
        cout<<"\t [3]. Update Gender"<<endl;
        cout<<"\t [4]. Update Age"<<endl;
        cout<<"\t [5]. Update Address"<<endl;
        cout<<"\t [6]. Update DOB"<<endl;
        cout<<"\t [7]. Update Contact "<<endl;
        cout<<"\t [8]. Update Position"<<endl;
}

// Daro

void Hospital::update(){
    system("CLS");
    fstream file, file1;
    string t_id,n,g,add,po,i,c,d;
    char bu;
    int a,r,option;
    int found = 0,pi;
    cout<<"\t==========>> Update <<=========="<<endl;
    file.open("Staff_A.txt", ios::in);//បញ្ចេញទិន្នន័យចេញពីFile
    if(!file){
        cout<<"\tFile Openning Error...!"<<endl;
    }else{
        menu_update();
        cout<<"\t [9]. Update Room(1-200)"<<endl;
        cout<<"\t[10]. Update All"<<endl;
        cout<<"\tEnter your option: ";cin>>option;
        switch(option){
            case 1:
                cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("Staff1_A.txt",ios::app|ios::out); //បន្ថែមទិន្នន័យថ្មីទៅឲ file ចាស់ or បញ្ចូលទិន្នន័យទៅក្នុងfile
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){ //end of file
                    if(t_id == id){
                        cout<<"\tEnter New ID: "; cin>>i;
                        file1<<" "<<i<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("Staff_A.txt");
                    rename("Staff1_A.txt","Staff_A.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 2:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("Staff1_A.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Name: "; cin>>n;
                        file1<<" "<<id<<" "<<n<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("Staff_A.txt");
                    rename("Staff1_A.txt","Staff_A.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 3:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("Staff1_A.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Gender: "; cin>>g;
                        file1<<" "<<id<<" "<<name<<" "<<g<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("Staff_A.txt");
                    rename("Staff1_A.txt","Staff_A.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 4:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("Staff1_A.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Age: "; cin>>a;
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<a<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("Staff_A.txt");
                    rename("Staff1_A.txt","Staff_A.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 5:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("Staff1_A.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Address: "; cin>>add;
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<add<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("Staff_A.txt");
                    rename("Staff1_A.txt","Staff_A.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 6:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("Staff1_A.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New DOB: "; cin>>d;
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<d<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("Staff_A.txt");
                    rename("Staff1_A.txt","Staff_A.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 7:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("Staff1_A.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Contact: "; cin>>c;
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<c<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("Staff_A.txt");
                    rename("Staff1_A.txt","Staff_A.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 8:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("Staff1_A.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Position: "; cin>>po;
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<po<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("Staff_A.txt");
                    rename("Staff1_A.txt","Staff_A.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 9:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("Staff1_A.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Room(1-100): "; cin>>r;
                        if(r>=1 && r <=10){
                            floor = 1;
                        }else if( r>=11 && r <=20){
                            floor = 2;
                        }else if(r >= 21 && r <= 30){
                            floor = 3;
                        }else if(r >= 31 && r <= 40){
                            floor = 4;
                        }else if(r >= 41 && r <= 50){
                            floor = 5;
                        }else if(r >= 51 && r <= 60){
                            floor = 6;
                        }else if(r >= 61 && r <= 70){
                            floor = 7;
                        }else if(r >= 71 && r <= 80){
                            floor = 8;
                        }else if(r >= 81 && r <= 90){
                            floor = 9;
                        }else if(r >= 91 && r <= 100){
                            floor = 10;
                        }else if(r >= 101 && r <= 110){
                            floor = 11;
                        }else if(r >= 111 && r <= 120){
                            floor = 12;
                        }else if(r >= 121 && r <= 130){
                            floor = 13;
                        }else if(r >= 131 && r <= 140){
                            floor = 14;
                        }else if(r >= 141 && r <= 150){
                            floor = 15;
                        }else if(r >= 151 && r <= 160){
                            floor = 16;
                        }else if(r >= 161 && r <= 170){
                            floor = 17;
                        }else if(r >= 171 && r <= 180){
                            floor = 18;
                        }else if(r >= 181 && r <= 190){
                            floor = 19;
                        }else if(r >= 191 && r <= 200){
                            floor = 20;
                        }else{
                            cout<<"\tRoom don't have!"<<endl;
                        }
                        if(r == r){
                ROOM:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                if(r==room){
                    goto ROOM;
                    }
                }
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<r<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("Staff_A.txt");
                    rename("Staff1_A.txt","Staff_A.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 10:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Staff1_A.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New ID: "; cin>>i;
                cout<<"\tEnter New Name: "; cin>>n;
                cout<<"\tEnter New Gender: "; cin>>g;
                cout<<"\tEnter New Age: "; cin>>a;
                cout<<"\tEnter New Address: "; cin>>add;
                cout<<"\tEnter New DOB: "; cin>>d;
                cout<<"\tEnter New Contact: "; cin>>c;
                cout<<"\tEnter New Position: "; cin>>po;
                Build:
                cout<<"\tEnter New Building(Only A): "; cin>>bu;
                if(building == 'A' || building == 'a'){
                    cout<<"\tEnter Room(1-100): "; cin>>r;
                        cout<<"\tRoom Added successfully."<<endl;
                        if(r>=1 && r <=10){
                            floor = 1;
                        }else if( r>=11 && r <=20){
                            floor = 2;
                        }else if(r >= 21 && r <= 30){
                            floor = 3;
                        }else if(r >= 31 && r <= 40){
                            floor = 4;
                        }else if(r >= 41 && r <= 50){
                            floor = 5;
                        }else if(r >= 51 && r <= 60){
                            floor = 6;
                        }else if(r >= 61 && r <= 70){
                            floor = 7;
                        }else if(r >= 71 && r <= 80){
                            floor = 8;
                        }else if(r >= 81 && r <= 90){
                            floor = 9;
                        }else if(r >= 91 && r <= 100){
                            floor = 10;
                        }else if(r >= 101 && r <= 110){
                            floor = 11;
                        }else if(r >= 111 && r <= 120){
                            floor = 12;
                        }else if(r >= 121 && r <= 130){
                            floor = 13;
                        }else if(r >= 131 && r <= 140){
                            floor = 14;
                        }else if(r >= 141 && r <= 150){
                            floor = 15;
                        }else if(r >= 151 && r <= 160){
                            floor = 16;
                        }else if(r >= 161 && r <= 170){
                            floor = 17;
                        }else if(r >= 171 && r <= 180){
                            floor = 18;
                        }else if(r >= 181 && r <= 190){
                            floor = 19;
                        }else if(r >= 191 && r <= 200){
                            floor = 20;
                        }else{
                            cout<<"\tRoom don't have!"<<endl;
                        }
                        if(r == r){
                ROOM1:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                if(r==room){
                    goto ROOM1;
                    }
                }
                    }else{
                        cout<<"Please Enter A!"<<endl;
                        getch();
                        goto Build;
                    }
                file1<<" "<<i<<" "<<n<<" "<<g<<" "<<a<<" "<<add<<" "<<d<<" "<<c<<" "<<po<<" "<<bu<<" "<<r<<" "<<floor<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
        }
        file.close();
        file1.close();
        remove("Staff_A.txt");
        rename("Staff1_A.txt","Staff_A.txt");
        if(found == 0)
            cout<<"\tID can't found...!"<<endl;
                break;
            default:
            cout << "\033[1;31m"; 
                cout<<"Wrong Option!"<<endl;
                break;
        }
    }
}

//end Daro


//start Somean

void Hospital::del(){
    system("CLS");
    fstream file, file1;
    string t_id;
    int found = 0;
    file.open("Staff_A.txt", ios::in);
    if(!file){
        cout<<"\tFile openning Error...!"<<endl;
    }
    else{
        cout<<"\tInput ID for delete: "; cin>>t_id;
        file1.open("Staff1_A.txt", ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tDelete Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
        }
        file.close();
        file1.close();
        remove("Staff_A.txt");
        rename("Staff1_A.txt", "Staff_A.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't Found..."<<endl;
        }
    }
}


class Hospital2:public Hospital{
    public:
        void input4();
        void output4();
        void search4();
        void del4();
        void update4();
        void File_Input4();
        void Menu_Hospital4();
        void hospital_management_staff4();
};

void Hospital2::File_Input4(){
    fstream file;
    int p,a,r,r1,f;
    float b;
    string n,g,add,po,i,c,d;
    char bu;
    file.open("StaffB.txt", ios::in);
    if(!file){
        file.open("StaffB.txt", ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
        file.close();
    }else{
        file>>i>>n>>g>>a>>add>>d>>c>>po>>bu>>r>>f;
        while(!file.eof()){
            if(i==id && r == room){
                Again:
                cout << "\033[1;31m"; 
                cout<<"ID and Room is Already Exist..."<<endl;
                cout<<"\tInput ID: "; cin>>id;
                Hospital::list_room();
                if(i == id && r == room){
                    goto Again;
                }
            }else if(r == room){
                ROOM:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                Hospital::list_room();
                if(r==room){
                    goto ROOM;
                }
            }else if(i==id){
                ID:
                cout << "\033[1;31m"; 
                cout<<"\tUser ID is Already Exist..."<<endl;
                cout<<"\tInput ID: "; cin>>id;
                if(i == id){
                    goto ID;
                }
            }
            file>>i>>n>>g>>a>>add>>d>>c>>po>>bu>>r>>f;
        }
        file.close();
        file.open("StaffB.txt", ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
        file.close();
    }
}

void Hospital2::Menu_Hospital4(){
    Hospital::Menu();
}

void Hospital2::hospital_management_staff4(){
    p:
    system("CLS");
    int choice;
    Menu();
    cout<<"\tEnter your choice: "; cin>>choice;
    switch(choice){
        case 1:
            input4();
            break;
        case 2:
            output4();
            break;
        case 3:
            search4();
            break;
        case 4:
            del4();
            break;
        case 5:
            update4();
            break;
        case 6:
            break;
        default:
        cout << "\033[1;31m"; 
            cout<<"\tInvalid Value...Please Try Again...";
    }
    getch();
}

void Hospital2::input4(){
    system("CLS");
    system("Color 0A"); 
    fstream file;
    int p,a,r,r1,f;
    float b;
    string n,g,add,po,i,c,d;
    char bu;
    cout<<"==========>> Add Staff <<==========\n"<<endl;
    Hospital::Add();
    buildA:
    cout<<"\tEnter Building(Only B): "; cin>>building;
    if(building == 'B' || building == 'b'){
        Hospital::list_room();
    }else{
        cout<<"\tPlease Enter A"<<endl;
        goto buildA;
    }
    Hospital2::File_Input4();
    system("Color 0A"); 
    cout<<"\tNew User Information Created Successfully..."<<endl;
}
void Hospital2::output4(){
    system("CLS");
    fstream file;
    int found = 0;
    cout<<"\t==========>> Output <<=========="<<endl<<endl;
    file.open("StaffB.txt", ios::in);
    if(!file){
        cout<<"File Openning Error...!"<<endl;
    }else{
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
        while(!file.eof()){
            cout<<"\n\tID        : "<<id<<endl;
            cout<<"\tName      : "<<name<<endl;
            cout<<"\tGender    : "<<gender<<endl;
            cout<<"\tAge       : "<<age<<endl;
            cout<<"\tAddress   : "<<address<<endl;
            cout<<"\tDOB       : "<<dob<<endl;
            cout<<"\tContact   : "<<contact<<endl;
            cout<<"\tPosition  : "<<position<<endl;
            cout<<"\tBuilding  : "<<building<<endl;
            cout<<"\tRoom      : "<<room<<endl;
            cout<<"\tFloor     : "<<floor<<endl;
            cout<<"\n\t====================================="<<endl;
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
            found++;
        }
        file.close();
        if(found == 0){
            cout<<"\nData base is Empty...!"<<endl;
        }
    }
}
void Hospital2::search4(){
    system("CLS");
    fstream file;
    string t_id;
    int found = 0;
    cout<<"\t==========>> Search <<=========="<<endl;
    file.open("StaffB.txt", ios::in);
    if(!file){
        cout<<"\n\tFile Opening Error...!"<<endl;
    }else{
        cout<<"\tInput ID for search: "; cin>>t_id;
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
    while(!file.eof()){
        if(t_id==id){
            system("CLS");
            cout<<"\t==========>> Search User <<=========="<<endl<<endl;
            cout<<"\tID: "<<id<<endl;
            cout<<"\tName: "<<name<<endl;
            cout<<"\tGender: "<<gender<<endl;
            cout<<"\tAge: "<<age<<endl;
            cout<<"\tAddress: "<<address<<endl;
            cout<<"\tDOB: "<<dob<<endl;
            cout<<"\tContact: "<<contact<<endl;
            cout<<"\tPosition: "<<position<<endl;
            cout<<"\tBuilding: "<<building<<endl;
            cout<<"\tRoom: "<<room<<endl;
            cout<<"\tFloor: "<<floor<<endl;
            found++;
        }
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
    }
    file.close();
    if(found == 0){
        cout << "\033[1;31m"; 
        cout<<"\nUser ID can't Found...!"<<endl;
    }
    }
}


void Hospital2::update4(){
    system("CLS");
    fstream file, file1;
    string t_id,n,g,add,po,i,c,d;
    char bu;
    int a,r,option;
    int found = 0,pi;
    cout<<"\t==========>> Update <<=========="<<endl;
    file.open("StaffB.txt", ios::in);
    if(!file){
        cout<<"\tFile Openning Error...!"<<endl;
    }else{
        Hospital::menu_update();
        cout<<"\t [9]. Update Room(1-200)"<<endl;
        cout<<"\t[10]. Update All"<<endl;
        cout<<"\tEnter your option: ";cin>>option;
        switch(option){
            case 1:
                cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("StaffB1.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New ID: "; cin>>i;
                        file1<<" "<<i<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("StaffB.txt");
                    rename("StaffB1.txt","StaffB.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 2:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("StaffB1.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Name: "; cin>>n;
                        file1<<" "<<id<<" "<<n<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("StaffB.txt");
                    rename("StaffB1.txt","StaffB.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 3:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("StaffB1.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Gender: "; cin>>g;
                        file1<<" "<<id<<" "<<name<<" "<<g<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("StaffB.txt");
                    rename("StaffB1.txt","StaffB.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 4:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("StaffB1.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Age: "; cin>>a;
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<a<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("StaffB.txt");
                    rename("StaffB1.txt","StaffB.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 5:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("StaffB1.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Address: "; cin>>add;
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<add<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("StaffB.txt");
                    rename("StaffB1.txt","StaffB.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 6:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("StaffB1.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New DOB: "; cin>>d;
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<d<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("StaffB.txt");
                    rename("StaffB1.txt","StaffB.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 7:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("StaffB1.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Contact: "; cin>>c;
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<c<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("StaffB.txt");
                    rename("StaffB1.txt","StaffB.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 8:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("StaffB1.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Position: "; cin>>po;
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<po<<" "<<building<<" "<<room<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("StaffB.txt");
                    rename("StaffB1.txt","StaffB.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 9:
                    cout<<"\tInput ID for update: "; cin>>t_id;
                file1.open("StaffB1.txt",ios::app|ios::out);
                file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                while(!file.eof()){
                    if(t_id == id){
                        cout<<"\tEnter New Room(1-100): "; cin>>r;
                        if(r>=1 && r <=10){
                            floor = 1;
                        }else if( r>=11 && r <=20){
                            floor = 2;
                        }else if(r >= 21 && r <= 30){
                            floor = 3;
                        }else if(r >= 31 && r <= 40){
                            floor = 4;
                        }else if(r >= 41 && r <= 50){
                            floor = 5;
                        }else if(r >= 51 && r <= 60){
                            floor = 6;
                        }else if(r >= 61 && r <= 70){
                            floor = 7;
                        }else if(r >= 71 && r <= 80){
                            floor = 8;
                        }else if(r >= 81 && r <= 90){
                            floor = 9;
                        }else if(r >= 91 && r <= 100){
                            floor = 10;
                        }else if(r >= 101 && r <= 110){
                            floor = 11;
                        }else if(r >= 111 && r <= 120){
                            floor = 12;
                        }else if(r >= 121 && r <= 130){
                            floor = 13;
                        }else if(r >= 131 && r <= 140){
                            floor = 14;
                        }else if(r >= 141 && r <= 150){
                            floor = 15;
                        }else if(r >= 151 && r <= 160){
                            floor = 16;
                        }else if(r >= 161 && r <= 170){
                            floor = 17;
                        }else if(r >= 171 && r <= 180){
                            floor = 18;
                        }else if(r >= 181 && r <= 190){
                            floor = 19;
                        }else if(r >= 191 && r <= 200){
                            floor = 20;
                        }else{
                            cout<<"\tRoom don't have!"<<endl;
                        }
                        if(r == r){
                ROOM:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                if(r==room){
                    goto ROOM;
                    }
                }
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<r<<" "<<floor<<endl;
                        cout<<"\tUpdate Sucessfully..."<<endl;
                        found++;
                    }else{
                        
                        file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
                    }
                    file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
                }
                    file.close();
                    file1.close();
                    remove("StaffB.txt");
                    rename("StaffB1.txt","StaffB.txt");
                    if(found == 0)
                    cout<<"\tID can't found...!"<<endl;
                break;
            case 10:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("StaffB1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New ID: "; cin>>i;
                cout<<"\tEnter New Name: "; cin>>n;
                cout<<"\tEnter New Gender: "; cin>>g;
                cout<<"\tEnter New Age: "; cin>>a;
                cout<<"\tEnter New Address: "; cin>>add;
                cout<<"\tEnter New DOB: "; cin>>d;
                cout<<"\tEnter New Contact: "; cin>>c;
                cout<<"\tEnter New Position: "; cin>>po;
                Build:
                cout<<"\tEnter New Building(B): "; cin>>bu;
                if(building == 'B' || building == 'b'){
                    cout<<"\tEnter Room(1-100): "; cin>>r;
                        cout<<"\tRoom Added successfully."<<endl;
                        if(r>=1 && r <=10){
                            floor = 1;
                        }else if( r>=11 && r <=20){
                            floor = 2;
                        }else if(r >= 21 && r <= 30){
                            floor = 3;
                        }else if(r >= 31 && r <= 40){
                            floor = 4;
                        }else if(r >= 41 && r <= 50){
                            floor = 5;
                        }else if(r >= 51 && r <= 60){
                            floor = 6;
                        }else if(r >= 61 && r <= 70){
                            floor = 7;
                        }else if(r >= 71 && r <= 80){
                            floor = 8;
                        }else if(r >= 81 && r <= 90){
                            floor = 9;
                        }else if(r >= 91 && r <= 100){
                            floor = 10;
                        }else if(r >= 101 && r <= 110){
                            floor = 11;
                        }else if(r >= 111 && r <= 120){
                            floor = 12;
                        }else if(r >= 121 && r <= 130){
                            floor = 13;
                        }else if(r >= 131 && r <= 140){
                            floor = 14;
                        }else if(r >= 141 && r <= 150){
                            floor = 15;
                        }else if(r >= 151 && r <= 160){
                            floor = 16;
                        }else if(r >= 161 && r <= 170){
                            floor = 17;
                        }else if(r >= 171 && r <= 180){
                            floor = 18;
                        }else if(r >= 181 && r <= 190){
                            floor = 19;
                        }else if(r >= 191 && r <= 200){
                            floor = 20;
                        }else{
                            cout<<"\tRoom don't have!"<<endl;
                        }
                    }else{
                        cout<<"Please Enter B!"<<endl;
                        getch();
                        goto Build;
                    }
                    if(r == r){
                ROOM2:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                if(r==room){
                    goto ROOM2;
                    }
                }
                file1<<" "<<i<<" "<<n<<" "<<g<<" "<<a<<" "<<add<<" "<<d<<" "<<c<<" "<<po<<" "<<bu<<" "<<r<<" "<<floor<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
        }
        file.close();
        file1.close();
        remove("StaffB.txt");
        rename("StaffB1.txt","StaffB.txt");
        if(found == 0)
            cout<<"\tID can't found...!"<<endl;
                break;
            default:
            cout << "\033[1;31m"; 
                cout<<"Wrong Option!"<<endl;
                break;
        }
    }
}

//end somean

//start devit

void Hospital2::del4(){
    system("CLS");
    fstream file, file1;
    string t_id;
    int found = 0;
    file.open("Staff.txt", ios::in);
    if(!file){
        cout<<"\tFile openning Error...!"<<endl;
    }
    else{
        cout<<"\tInput ID for delete: "; cin>>t_id;
        file1.open("Staff1_A.txt", ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tDelete Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<building<<" "<<room<<" "<<floor<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>building>>room>>floor;
        }
        file.close();
        file1.close();
        remove("Staff.txt");
        rename("Staff1_A.txt", "Staff.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't Found..."<<endl;
        }
    }
}

class Patient_man:public Hospital{
    protected:
        int room = 0, day = 1, sick,floor = 0,option;
        string sicks,speak;
        float total, price;
        char building = '0';
    public: 
        void hospital_management_patient();
        void input1();
        void output1();
        void search1();
        void del1();
        void update1();
        void StoreInput();
        void list_sick();
        void list_update();
        void list_search();
        void list_desease();
        void list_room();
};
void Patient_man::list_room(){
    p:
    cout<<"\tEnter Room(1-200): "; cin>>room;
        if(room>=1 && room <=10){
            floor = 1;
        }else if( room>=11 && room <=20){
            floor = 2;
        }else if(room >= 21 && room <= 30){
            floor = 3;
        }else if(room >= 31 && room <= 40){
            floor = 4;
        }else if(room >= 41 && room <= 50){
            floor = 5;
        }else if(room >= 51 && room <= 60){
            floor = 6;
        }else if(room >= 61 && room <= 70){
            floor = 7;
        }else if(room >= 71 && room <= 80){
            floor = 8;
        }else if(room >= 81 && room <= 90){
            floor = 9;
        }else if(room >= 91 && room <= 100){
            floor = 10;
        }else if(room >= 101 && room <= 110){
            floor = 11;
        }else if(room >= 111 && room <= 120){
            floor = 12;
        }else if(room >= 121 && room <= 130){
            floor = 13;
        }else if(room >= 131 && room <= 140){
            floor = 14;
        }else if(room >= 141 && room <= 150){
            floor = 15;
        }else if(room >= 151 && room <= 160){
            floor = 16;
        }else if(room >= 161 && room <= 170){
            floor = 17;
        }else if(room >= 171 && room <= 180){
            floor = 18;
        }else if(room >= 181 && room <= 190){
            floor = 19;
        }else if(room >= 191 && room <= 200){
            floor = 20;
        }else{
            cout << "\033[1;31m"; 
            cout<<"\tRoom don't have!"<<endl;
            goto p;
        }
}
void Patient_man::hospital_management_patient(){
    int choice;
    Hospital::Menu();
    cout<<"\tEnter your choice: "; cin>>choice;
    switch(choice){
        case 1:
            input1();
            break;
        case 2:
            output1();
            break;
        case 3:
            search1();
            break;
        case 4:
            del1();
            break;
        case 5:
            update1();
            break;
        case 6:
            break;
        
        default:
        cout << "\033[1;31m"; 
            cout<<"\tInvalid Value...Please Try Again...";
    }
    getch();
}
void Patient_man::StoreInput(){
    system("Color 0A"); 
    system("CLS");
    cout<<"==========>> Add Patient_Woman <<==========\n"<<endl;
    Hospital::Add();
    list_sick();
    list_desease();
}

void Patient_man::list_sick(){
    string listAllSick[50] = {
        "Acute Flaccid Myelitis (AFM): 100$",
        "Alphaviruses: 100$",
        "Alzheimer's Disease: 100$",
        "Arboviral Encephalitis: 100$",
        "Arthritis: 100$",
        "Asthma: 100$",
        "Babesiosis: 100$",
        "Bacterial Vaginosis: 100$",
        "Bladder Cancer: 100$",
        "Breast Cancer: 100$",
        "Breast Exams and Mammograms: 100$",
        "Cancer: 100$",
        "Cancer and Your Environment: 100$",
        "Carbapenem-Resistant Enterobacteriaceae (CRE) Infections: 100$",
        "Carbon Monoxide: 100$",
        "Celiac Disease: 100$",
        "Cervical Cancer: 100$",
        "Chagas Disease: 100$",
        "Chancroid: 100$",
        "Chickenpox: 100$",
        "Chlamydia: 100$",
        "Chronic Fatigue Syndrome: 100$",
        "Chronic Obstructive Pulmonary Disease (COPD): 100$",
        "Clostridium Difficile: 100$",
        "Colon Cancer: 100$",
        "Colorectal Cancer: 100$",
        "Conjunctivitis: 100$",
        "COVID-19: 100$",
        "Crabs: 100$",
        "Creutzfeldt-Jakob Disease: 100$",
        "Cryptosporidiosis: 100$",
        "Cyclospora: 100$",
        "Cytomegalovirus (CMV) and Congenital CMV Infection: 100$",
        "Depression: 100$",
        "Diabetes: 100$",
        "Diphtheria: 100$",
        "Endometrial Cancer: 100$",
        "Harmful Algal Blooms (HABs): 100$",
        "Heart & Stroke: 100$",
        "HIV/AIDS: 100$",
        "Kidney Cancer: 100$",
        "Leukemia: 100$",
        "Liver Cancer: 100$",
        "Lung Cancer: 100$",
        "Multiple Myeloma: 100$",
        "Oral Cancer: 100$",
        "Ovarian Cancer: 100$",
        "Pancreatic Cancer: 100$",
        "Skin Cancer: 100$",
        "Stomach Cancer: 100$"
    };

    
    for (int i = 0; i < 50; i++) {
        cout << (i + 1) << ". " << listAllSick[i] << endl;
    }

            
}
void Patient_man::input1(){
    p:
    fstream file;
    int p,a,r,da,f;
    float b,t,pr;
    string n,g,add,po,i,c,si,d;
    char bu;
        StoreInput();
        if(gender == 'M'){
        system("Color 0A"); 
    }else{
        cout << "\033[1;31m"; 
        cout<<"\tDon't Input M"<<endl;
        StoreInput();
    }
            cout<<"You stay in hopital or not? (Yes or No): "; cin>>speak;
            if(speak == "yes" || speak == "YES"){
                cout<<"1 day = 50$"<<endl;
                cout<<"How many day that you want to stay: "; cin>>day;
                price = 100;
                total = price+(day*50);
                buildA:
                system("Color 0A"); 
    cout<<"\tEnter Building(Only A): "; cin>>building;
    if(building == 'A' || building == 'a'){
        list_room();
        system("Color 0A");
        cout<<"\tRoom Added successfully."<<endl;
    }else{
        cout << "\033[1;31m"; 
        cout<<"\tPlease Enter A"<<endl;
        getch();
        goto buildA;
    }
    
    file.open("Patient_Man.txt", ios::in);
    if(!file){
        file.open("Patient_Man.txt", ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
        file.close();
    }else{
        t = price*day;
        file>>i>>n>>g>>a>>add>>d>>c>>po>>si>>da>>bu>>r>>f>>t;
        while(!file.eof()){
            if(i==id && r == room){
                Again:
                cout << "\033[1;31m"; 
                cout<<"ID and Room is Already Exist..."<<endl;
                cout<<"\tInput ID: "; cin>>id;
                Patient_man::list_room();
                if(i == id && r == room){
                    goto Again;
                }
            }else if(r == room){
                ROOM:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                Patient_man::list_room();
                if(r==room){
                    goto ROOM;
                }
            }else if(i==id){
                ID:
                cout << "\033[1;31m"; 
                cout<<"\tUser ID is Already Exist..."<<endl;
                cout<<"\tInput ID: "; cin>>id;
                if(i == id){
                    goto ID;
                }
            }
            file>>i>>n>>g>>a>>add>>d>>c>>po>>si>>da>>bu>>r>>f>>t;
        }
        file.close();
        file.open("Patient_Man.txt", ios::app|ios::out);
                file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
        file.close();
    }
    system("Color 0A"); 
    cout<<"\tNew User Information Created Successfully..."<<endl;
    }else{
        again:
        room = 0;
        floor =0;
        building = '0';
        day = 0;
        price = 100;
        total = 100;
    file.open("Patient_Man.txt", ios::in);
    if(!file){
        total = 100;
        file.open("Patient_Man.txt", ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
        file.close();
    }else{
        t = 100;
        file>>i>>n>>g>>a>>add>>d>>c>>po>>si>>da>>bu>>r>>f>>t;
        while(!file.eof()){
            if(i==id && r==room){
                cout << "\033[1;31m"; 
                cout<<"\tUser ID and Room is Already Exist..."<<endl;
                getch();
                goto p;
            }else if(i==id){
                cout << "\033[1;31m"; 
                cout<<"\tUser ID is Already Exist..."<<endl;
                getch();
                goto p;
            }
            file>>i>>n>>g>>a>>add>>d>>c>>po>>si>>da>>bu>>r>>f>>total;
        }
        file.close();
        file.open("Patient_Man.txt", ios::app|ios::out);
                file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
        file.close();
    }
    system("Color 0A"); 
    cout<<"\tNew User Information Created Successfully..."<<endl;
    getch();
    system("CLS");
}   
    
}
void Patient_man::output1(){
    system("CLS");
    fstream file;
    int found = 0;
    system("Color 0A"); 
    cout<<"\t==========>> Output <<=========="<<endl<<endl;
    file.open("Patient_Man.txt", ios::in);
    if(!file){
        cout<<"File Openning Error...!"<<endl;
    }else{
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            cout<<"\n\tID        : "<<id<<endl;
            cout<<"\tName      : "<<name<<endl;
            Gender:
            cout<<"\tGender    : "<<gender<<endl;
            if(gender == 'M'){
            }else{
                cout<<"Don't Input F"<<endl;
                goto Gender;
            }
            cout<<"\tAge       : "<<age<<endl;
            cout<<"\tAddress   : "<<address<<endl;
            cout<<"\tDOB       : "<<dob<<endl;
            cout<<"\tContact   : "<<contact<<endl;
            cout<<"\tPosition  : "<<position<<endl;
            cout<<"\tDisease   : "<<sicks<<endl;
            cout<<"\tDay       : "<<day<<endl;
            cout<<"\tBuilding  : "<<building<<endl;
            cout<<"\tRoom      : "<<room<<endl;
            cout<<"\tFloor     : "<<floor<<endl;
            cout<<"\tTotal     : "<<total<<endl;
            cout<<"\n\t====================================="<<endl;
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
            found++;
        }
        file.close();
        if(found == 0){
            cout<<"\nData base is Empty...!"<<endl;
        }
    }
}
void Patient_man::list_search(){
    cout<<"\t==========>> Search User <<=========="<<endl<<endl;
            cout<<"\n\tID        : "<<id<<endl;
            cout<<"\tName      : "<<name<<endl;
            cout<<"\tGender    : "<<gender<<endl;
            cout<<"\tAge       : "<<age<<endl;
            cout<<"\tAddress   : "<<address<<endl;
            cout<<"\tDOB       : "<<dob<<endl;
            cout<<"\tContact   : "<<contact<<endl;
            cout<<"\tPosition  : "<<position<<endl;
            cout<<"\tDisease   : "<<sicks<<endl;
            cout<<"\tDay       : "<<day<<endl;
            cout<<"\tBuilding  : "<<building<<endl;
            cout<<"\tRoom      : "<<room<<endl;
            cout<<"\tFloor     : "<<floor<<endl;
            cout<<"\tTotal     : "<<total<<endl;
}

void Patient_man::search1(){
    system("CLS");
    fstream file;
    string t_id;
    int found = 0;
    cout<<"\t==========>> Search <<=========="<<endl;
    file.open("Patient_Man.txt", ios::in);
    if(!file){
        cout<<"\n\tFile Opening Error...!"<<endl;
    }else{
        system("Color 0A");
        cout<<"\tInput ID for search: "; cin>>t_id;
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
    while(!file.eof()){
        if(t_id==id){
            system("CLS");
            system("Color 0A");
            list_search();
            found++;
        }
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
    }
    file.close();
    if(found == 0){
        cout << "\033[1;31m"; 
        cout<<"\nUser ID can't Found...!"<<endl;
    }
    }
}
void Patient_man::list_desease(){
    cout<<"What disease: "; cin>>sick;
            switch(sick){
                case 1:
                    sicks = "Acute-Flaccid-Myelitis-(AFM)";
                    break;
                case 2:
                    sicks = "Alphaviruses";
                    break;
                case 3:
                    sicks = "Alzheimer's-Disease";
                    break;
                case 4:
                    sicks = "Arboviral-Encephalitis";
                    break;
                case 5:
                    sicks = "Arthritis";
                    break;
                case 6:
                    sicks = "Asthma";
                    break;
                case 7:
                    sicks = "Babesiosis";
                    break;
                case 8:
                    sicks = "Bacterial-Vaginosis";
                    break;
                case 9:
                    sicks = "Bladder-Cancer";
                case 10:
                    sicks = "Breast-Cancer";
                    break;
                case 11:
                    sicks = "Breast-Exams-and-Mammograms";
                    break;
                case 12:
                    sicks = "Cancer";
                    break;
                case 13:
                    sicks = "Cancer-and-Your-Environment";
                    break;
                case 14:
                    sicks = "Carbapenem-Resistant-Enterobacteriaceae-(CRE)-Infections";
                    break;
                case 15:
                    sicks = "Carbon-Monoxide";
                    break;
                case 16:
                    sicks = "Celiac-Disease";
                    break;
                case 17:
                    sicks = "Cervical-Cancer";
                    break;
                case 18:
                    sicks = "Chagas-Disease";
                    break;
                case 19:
                    sicks = "Chancroid";
                    break;
                case 20:
                    sicks = "Chickenpox";
                    break;
                case 21:
                    sicks = "Chlamydia";
                    break;
                case 22:
                    sicks = "Chronic-Fatigue-Syndrome";
                    break;
                case 23:
                    sicks = "Chronic-Obstructive-Pulmonary-Disease-(COPD)";
                    break;
                case 24:
                    sicks = "Clostridium-Difficile";
                    break;
                case 25:
                    sicks = "Colon-Cancer";
                    break;
                case 26:    
                    sicks = "Colorectal-Cancer";
                    break;
                case 27:
                    sicks = "Conjunctivitis";
                    break;
                case 28:
                    sicks = "COVID-19";
                    break;
                case 29:
                    sicks = "Crabs";
                    break;
                case 30:    
                    sicks = "Creutzfeldt-Jakob-Disease";
                    break;
                case 31:
                    sicks = "Cryptosporidiosis";
                    break;
                case 32:
                    sicks = "Cyclospora";
                    break;
                case 33:
                    sicks = "Cytomegalovirus-(CMV)-and-Congenital-CMV-Infection";
                    break;
                case 34:
                    sicks = "Depression";
                    break;
                case 35:
                    sicks = "Diabetes";
                    break;
                case 36:
                    sicks = "Diphtheria";
                    break;
                case 37:
                    sicks = "Endometrial-Cancer";
                    break;
                case 38:
                    sicks = "Harmful-Algal-Blooms-(HABs)";
                    break;
                case 39:
                    sicks = "Heart&Stroke";
                    break;
                case 40:
                    sicks = "HIV/AIDS";
                    break;
                case 41:
                    sicks = "Kidney-Cancer";
                    break;
                case 42:
                    sicks = "Leukemia";
                    break;
                case 43:
                    sicks = "Liver-Cancer";
                    break;
                case 44:
                    sicks = "Lung-Cancer";
                    break;
                case 45:
                    sicks = "Multiple-Myeloma";
                    break;
                case 46:
                    sicks = "Oral-Cancer";
                    break;
                case 47:
                    sicks = "Ovarian-Cancer";
                    break;
                case 48:
                    sicks = "Pancreatic-Cancer";
                    break;
                case 49:
                    sicks = "Skin-Cancer";
                    break;
                case 50:
                    sicks = "Stomach-Cancer";
                    break;
            }
}


void Patient_man::list_update(){
    cout<<"\t [1]. Update ID"<<endl;
        cout<<"\t [2]. Update Name"<<endl;
        cout<<"\t [3]. Update Gender"<<endl;
        cout<<"\t [4]. Update Age"<<endl;
        cout<<"\t [5]. Update Address"<<endl;
        cout<<"\t [6]. Update DOB"<<endl;
        cout<<"\t [7]. Update Contact"<<endl;
        cout<<"\t [8]. Update Position"<<endl;
        cout<<"\t [9]. Update Disease"<<endl;
        cout<<"\t[10]. Update Day"<<endl;
        cout<<"\t[11]. Update Room"<<endl;
        cout<<"\t[12]. Update All"<<endl;
}

void Patient_man::update1(){
    system("CLS");
    fstream file, file1;
    string t_id,n,add,po,i,c,si,d;
    char bu,g;
    int a,da,r,f;
    float t;
    int found = 0,pi;
    cout<<"\t==========>> Update <<=========="<<endl;
    file.open("Patient_Man.txt", ios::in);
    if(!file){
        cout<<"\tFile Openning Error...!"<<endl;
    }else{
        system("Color 0A");
        list_update();
        cout<<"\tWhich Option that you want to update: "; cin>>option;
        switch(option){
            case 1:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New ID: "; cin>>i;
                file1<<" "<<i<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 2:
        cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Name: "; cin>>n;
                file1<<" "<<id<<" "<<n<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 3:
            cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Gender: "; cin>>g;
                file1<<" "<<id<<" "<<name<<" "<<g<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;   
        case 4:
            cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Age: "; cin>>a;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<a<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 5:
            cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Address: "; cin>>add;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<add<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 7:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Contact: "; cin>>c;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<c<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 8:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Position: "; cin>>po;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<po<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 9:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                list_sick();
                list_desease();
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 10:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Day: "; cin>>da;
                total = da*100;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<da<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0)
            cout<<"\tID can't found...!"<<endl;
            break;
        case 11:
        cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                if(r == r){
                ROOM:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                if(r==room){
                    goto ROOM;
                    }
                }
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<r<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
            }
            file.close();
            file1.close();
            remove("Patient_Man.txt");
            rename("Patient_Man1.txt","Patient_Man.txt");
            if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 12:
            cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                ID:
                cout<<"\tEnter New ID: "; cin>>i;
                if(i == id){
                    goto ID;
                }else{
                    
                }
                cout<<"\tEnter New Name: "; cin>>n;
                Gender:
                cout<<"\tEnter New Gender: "; cin>>g;
                if(g == 'M'){
                }else{
                    goto Gender;
                }
                cout<<"\tEnter New Age: "; cin>>a;
                cout<<"\tEnter New Address: "; cin>>add;
                cout<<"\tEnter New DOB: "; cin>>d;
                cout<<"\tEnter New Contact: "; cin>>c;
                cout<<"\tEnter New Positon: "; cin>>po;
                list_sick();
                list_desease();
                cout<<"\tEnter New Day: "; cin>>da;
                cout<<"\tEnter New Building(Only A): "; cin>>bu;
                total = (50*da)+100;
                RoomA:
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r == room){
                    goto RoomA;
                }else{
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                }
                if(r == r){
                ROOM3:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                if(r==room){
                    goto ROOM3;
                    }
                }
                
                file1<<" "<<i<<" "<<n<<" "<<g<<" "<<a<<" "<<add<<" "<<d<<" "<<c<<" "<<po<<" "<<sicks<<" "<<da<<" "<<bu<<" "<<r<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 6:
            cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New DOB: "; cin>>d;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<d<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;
    }
}
}
//end devit

//start Hak

void Patient_man::del1(){
    system("CLS");
    fstream file, file1;
    string t_id;
    int found = 0;
    cout<<"\tDelete Patient_Man"<<endl;
    file.open("Patient_Man.txt", ios::in);
    if(!file){
        cout<<"\tFile openning Error...!"<<endl;
    }
    else{
        cout<<"\tInput ID for delete: "; cin>>t_id;
        file1.open("Patient_Man1.txt", ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tDelete Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt", "Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            
        }
    }
class Patient_Woman:public Patient_man{
    public: 
        void hospital_management_patient_woman();
        void input2();
        void output2();
        void search2();
        void del2();
        void update2();
};

void Patient_Woman::hospital_management_patient_woman(){
    p:
    system("CLS");
    int choice;
    Hospital::Menu();
    cout<<"\tEnter your choice: "; cin>>choice;
    switch(choice){
        case 1:
            input2();
            break;
        case 2:
            output2();
            break;
        case 3:
            search2();
            break;
        case 4:
            del2();
            break;
        case 5:
            update2();
            break;
        case 6:
            break;
        default:
            cout << "\033[1;31m"; 
            cout<<"\tInvalid Value...Please Try Again...";
    }
    getch();
}

void Patient_Woman::input2(){
    p:
    system("CLS");
    fstream file;
    int p,a,r,da,f;
    float b,t,pr;
    string n,g,add,po,i,c,si,d;
    char bu;
        Patient_man::StoreInput();
        if(gender == 'F'){
        system("Color 0A"); 
    }else{
        cout << "\033[1;31m"; 
        cout<<"\tDon't Input M"<<endl;
        getch();
        Patient_man::StoreInput();
    }
            cout<<"You stay in hopital or not? (Yes or No): "; cin>>speak;
            if(speak == "yes" || speak == "YES"){
                cout<<"1 day = 50$"<<endl;
                cout<<"How many day that you want to stay: "; cin>>day;
                total = price+(day*50);
                buildA:
    cout<<"\tEnter Building(B): "; cin>>building;
    if(building == 'B' || building == 'b'){
        room:
        Patient_man::list_room();
        system("Color 0A");
        cout<<"\tRoom Added successfully."<<endl;
    }else{
        cout<<"\tPlease Enter B"<<endl;
        goto buildA;
    }
    file.open("Patient_woman.txt", ios::in);
    if(!file){
        file.open("Patient_woman.txt", ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
        file.close();
    }else{
        t = price*day;
        file>>i>>n>>g>>a>>add>>d>>c>>po>>si>>da>>bu>>r>>f>>t;
        while(!file.eof()){
            if(i==id && r == room){
                Again:
                cout << "\033[1;31m"; 
                cout<<"ID and Room is Already Exist..."<<endl;
                cout<<"\tInput ID: "; cin>>id;
                Patient_man::list_room();
                if(i == id && r == room){
                    goto Again;
                }
            }else if(r == room){
                ROOM:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                Patient_man::list_room();
                if(r==room){
                    goto ROOM;
                }
            }else if(i==id){
                ID:
                cout << "\033[1;31m"; 
                cout<<"\tUser ID is Already Exist..."<<endl;
                cout<<"\tInput ID: "; cin>>id;
                if(i == id){
                    goto ID;
                }
            }
            file>>i>>n>>g>>a>>add>>d>>c>>po>>si>>da>>bu>>r>>f>>t;
        }
        file.close();
        file.open("Patient_woman.txt", ios::app|ios::out);
                file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
        file.close();
    }
    cout<<"\tNew User Information Created Successfully..."<<endl;
    }else{
        again:
        room = 0;
        floor =0;
        building = '0';
        day = 0;
        price = 100;
        total = 100;
    file.open("Patient_woman.txt", ios::in);
    if(!file){
        total = 100;
        file.open("Patient_woman.txt", ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
        file.close();
    }else{
        t = 100;
        file>>i>>n>>g>>a>>add>>d>>c>>po>>si>>da>>bu>>r>>f>>t;
        while(!file.eof()){
            if(i==id && r==room){
                cout << "\033[1;31m"; 
                cout<<"\tUser ID and Room is Already Exist..."<<endl;
                getch();
                goto p;
            }else if(i==id){
                cout << "\033[1;31m"; 
                cout<<"\tUser ID is Already Exist..."<<endl;
                getch();
                goto p;
            }
            file>>i>>n>>g>>a>>add>>d>>c>>po>>si>>da>>bu>>r>>f>>total;
        }
        file.close();
        file.open("Patient_woman.txt", ios::app|ios::out);
                file<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
        file.close();
    }
    cout<<"\tNew User Information Created Successfully..."<<endl;
    getch();
    system("CLS");
}   
    
}

void Patient_Woman::output2(){
    system("CLS");
    fstream file;
    int found = 0;
    system("Color 0A"); 
    cout<<"\t==========>> Output <<=========="<<endl<<endl;
    file.open("Patient_woman.txt", ios::in);
    if(!file){
        cout<<"File Openning Error...!"<<endl;
    }else{
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            cout<<"\n\tID        : "<<id<<endl;
            cout<<"\tName      : "<<name<<endl;
            Gender:
            cout<<"\tGender    : "<<gender<<endl;
            if(gender == 'F'){
            }else{
                cout<<"Don't Input F"<<endl;
                goto Gender;
            }
            cout<<"\tAge       : "<<age<<endl;
            cout<<"\tAddress   : "<<address<<endl;
            cout<<"\tDOB       : "<<dob<<endl;
            cout<<"\tContact   : "<<contact<<endl;
            cout<<"\tPosition  : "<<position<<endl;
            cout<<"\tDisease   : "<<sicks<<endl;
            cout<<"\tDay       : "<<day<<endl;
            cout<<"\tBuilding  : "<<building<<endl;
            cout<<"\tRoom      : "<<room<<endl;
            cout<<"\tFloor     : "<<floor<<endl;
            cout<<"\tTotal     : "<<total<<endl;
            cout<<"\n\t====================================="<<endl;
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
            found++;
        }
        file.close();
        if(found == 0){
            cout<<"\nData base is Empty...!"<<endl;
        }
    }
}
void Patient_Woman::search2(){
    system("CLS");
    fstream file;
    string t_id;
    int found = 0;
    system("Color 0A"); 
    cout<<"\t==========>> Search <<=========="<<endl;
    file.open("Patient_woman.txt", ios::in);
    if(!file){
        cout<<"\n\tFile Opening Error...!"<<endl;
    }else{
        cout<<"\tInput ID for search: "; cin>>t_id;
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
    while(!file.eof()){
        if(t_id==id){
            system("CLS");
            Patient_man::list_search();
            found++;
        }
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
    }
    file.close();
    if(found == 0){
        cout << "\033[1;31m"; 
        cout<<"\nUser ID can't Found...!"<<endl;
    }
    }
}

void Patient_Woman::update2(){
    system("CLS");
    fstream file, file1;
    string t_id,n,add,po,i,c,si,d;
    char bu,g;
    int a,da,r,f;
    float t;
    int found = 0,pi;
    system("Color 0A"); 
    cout<<"\t==========>> Update <<=========="<<endl;
    file.open("Patient_woman.txt", ios::in);
    if(!file){
        cout << "\033[1;31m"; 
        cout<<"\tFile Openning Error...!"<<endl;
    }else{
        Patient_man::list_update();
        cout<<"\tWhich Option that you want to update: "; cin>>option;
        switch(option){
            case 1:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New ID: "; cin>>i;
                file1<<" "<<i<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt","Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 2:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Name: "; cin>>n;
                file1<<" "<<id<<" "<<n<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt","Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 3:
            cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Gender: "; cin>>g;
                file1<<" "<<id<<" "<<name<<" "<<g<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt","Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;   
        case 4:
            cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Age: "; cin>>a;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<a<<" "<<dob<<" "<<address<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt","Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 5:
            cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Address: "; cin>>add;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<add<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt","Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 7:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Contact: "; cin>>c;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<c<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt","Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 8:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Position: "; cin>>po;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<po<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt","Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 9:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                Patient_man::list_sick();
                Patient_man::list_desease();
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt","Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 10:
                cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Day: "; cin>>da;
                total = da*100;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<da<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt","Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 11:
        cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                if(r == r){
                ROOM:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                if(r==room){
                    goto ROOM;
                    }
                }
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<r<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl; 
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
            }
            file.close();
            file1.close();
            remove("Patient_woman.txt");
            rename("Patient_woman1.txt","Patient_woman.txt");
            if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 12:
            cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_woman1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                ID:
                cout<<"\tEnter New ID: "; cin>>i;
                if(i == id){
                    goto ID;
                }else{
                }
                cout<<"\tEnter New Name: "; cin>>n;
                Gender:
                cout<<"\tEnter New Gender: "; cin>>g;
                if(g == 'F'){
                }else{
                    goto Gender;
                }
                cout<<"\tEnter New Age: "; cin>>a;
                cout<<"\tEnter New Address: "; cin>>add;
                cout<<"\tEnter New DOB: "; cin>>d;
                cout<<"\tEnter New Contact: "; cin>>c;
                cout<<"\tEnter New Positon: "; cin>>po;
                Patient_man::list_sick();
                Patient_man::list_desease();
                cout<<"\tEnter New Day: "; cin>>da;
                cout<<"\tEnter New Building(Only A): "; cin>>bu;
                RoomA:
                cout<<"\tEnter New Room(1-100): "; cin>>r;
                if(r == room){
                    goto RoomA;
                }else{
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                }
                if(r == r){
                ROOM4:
                cout << "\033[1;31m"; 
                cout<<"\tRoom is already!"<<endl;
                cout<<"\tEnter New Room(1-200): "; cin>>r;
                if(r>=1 && r <=10){
                    floor = 1;
                }else if( r>=11 && r <=20){
                    floor = 2;
                }else if(r >= 21 && r <= 30){
                    floor = 3;
                }else if(r >= 31 && r <= 40){
                    floor = 4;
                }else if(r >= 41 && r <= 50){
                    floor = 5;
                }else if(r >= 51 && r <= 60){
                    floor = 6;
                }else if(r >= 61 && r <= 70){
                    floor = 7;
                }else if(r >= 71 && r <= 80){
                    floor = 8;
                }else if(r >= 81 && r <= 90){
                    floor = 9;
                }else if(r >= 91 && r <= 100){
                    floor = 10;
                }else if(r >= 101 && r <= 110){
                    floor = 11;
                }else if(r >= 111 && r <= 120){
                    floor = 12;
                }else if(r >= 121 && r <= 130){
                    floor = 13;
                }else if(r >= 131 && r <= 140){
                    floor = 14;
                }else if(r >= 141 && r <= 150){
                    floor = 15;
                }else if(r >= 151 && r <= 160){
                    floor = 16;
                }else if(r >= 161 && r <= 170){
                    floor = 17;
                }else if(r >= 171 && r <= 180){
                    floor = 18;
                }else if(r >= 181 && r <= 190){
                    floor = 19;
                }else if(r >= 191 && r <= 200){
                    floor = 20;
                }else{
                    cout<<"\tRoom don't have!"<<endl;
                }
                if(r==room){
                    goto ROOM4;
                    }
                }
                file1<<" "<<i<<" "<<n<<" "<<g<<" "<<a<<" "<<add<<" "<<d<<" "<<c<<" "<<po<<" "<<sicks<<" "<<da<<" "<<bu<<" "<<r<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt","Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m";
            cout<<"\tID can't found...!"<<endl;
        }
            break;
        case 6:
            cout<<"\tInput ID for update: "; cin>>t_id;
        file1.open("Patient_Man1.txt",ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tEnter New DOB: "; cin>>d;
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<d<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
                cout<<"\tUpdate Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_Man.txt");
        rename("Patient_Man1.txt","Patient_Man.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't found...!"<<endl;
        }
            break;
    }
}
}
void Patient_Woman::del2(){
    system("CLS");
    fstream file, file1;
    string t_id;
    int found = 0;
    system("Color 0A"); 
    cout<<"\tDelete Patient_woman"<<endl;
    file.open("Patient_woman.txt", ios::in);
    if(!file){
        cout<<"\tFile openning Error...!"<<endl;
    }
    else{
        cout<<"\tInput ID for delete: "; cin>>t_id;
        file1.open("Patient_woman1.txt", ios::app|ios::out);
        file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        while(!file.eof()){
            if(t_id == id){
                cout<<"\tDelete Sucessfully..."<<endl;
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<gender<<" "<<age<<" "<<address<<" "<<dob<<" "<<contact<<" "<<position<<" "<<sicks<<" "<<day<<" "<<building<<" "<<room<<" "<<floor<<" "<<total<<endl;
            }
            file>>id>>name>>gender>>age>>address>>dob>>contact>>position>>sicks>>day>>building>>room>>floor>>total;
        }
        file.close();
        file1.close();
        remove("Patient_woman.txt");
        rename("Patient_woman1.txt", "Patient_woman.txt");
        if(found == 0){
            cout << "\033[1;31m"; 
            cout<<"\tID can't Found..."<<endl;
        }
        }
    }

    // Function to display a line with animation
void animatedLine(const string &line, int delay = 50) {
    for (char c : line) {
        cout << c; // Print each character one by one
        cout.flush(); // Flush output to ensure smooth display
        this_thread::sleep_for(chrono::milliseconds(delay)); // Add delay
    }
    cout << endl;
}

int main(){
    Hospital h;
    Patient_man pat;
    Patient_Woman w;
    Hospital2 h2;
    p:
    system("CLS");
    int choice,option;
    char ch;
    string pin,pass,email;
    do{
    system("Color 0A"); 
    animatedLine("\t==========>> Menu <<==========\n");
    cout << endl;
    animatedLine("\t#########################");
    animatedLine("\t#\t[1]. Staff      #");
    animatedLine("\t#########################");
    animatedLine("\t#\t[2]. Patient    #");
    animatedLine("\t#########################");
    animatedLine("\t#\t[3]. Exit       #");
    animatedLine("\t#########################");

    cout<<"\tEnter your choice: "; cin>> choice;
    switch(choice){
        case 1:
            system("CLS");
            cout<<"==========>> Login Account <<=========="<<endl<<endl;
            cout<<"\t-Enter Email: "; cin>>email;
            cout<<"\t-Pin Code: ";
            for(int i = 1; i<=5; i++){
                ch = getch();
                pin += ch;
                cout<<"*";
            }
            cout<<"\n\t-Password: ";
            for(int i=1; i<=5; i++){
                ch = getch();
                pass += ch;
                cout<<"*";
            }
            if(email == "hak@gmail.com" && pin == "11111" && pass == "22222"){
                system("CLS");
                system("Color 0A"); 
                int option;
                cout<<"==========>> Staff <<=========="<<endl;
                cout<<"\t1.-> Staff at building A"<<endl;
                cout<<"\t2.-> Staff at building B"<<endl;
                cout<<"\tWhich option that you want to choose: "; cin>>option;
                switch(option){
                    case 1:
                        h.hospital_management_staff();
                        break;
                    case 2:
                        h2.hospital_management_staff4();
                        break;
                }
            }else{
                cout << "\033[1;31m"; 
                cout<<"\n\tYour E-Mail, Pin & Password is Wrong...";
            }
            break;
        case 2:
            system("CLS");
            cout<<"==========>> Login Account <<=========="<<endl<<endl;
            cout<<"\t-Enter Email: "; cin>>email;
            cout<<"\t-Pin Code: ";
            for(int i = 1; i<=5; i++){
                ch = getch();
                pin += ch;
                cout<<"*";
            }
            cout<<"\n\t-Password: ";
            for(int i = 1; i<=5; i++){
                ch = getch();
                pass += ch;
                cout<<"*";
            }
            if(email == "hak@gmail.com" && pin == "11111" && pass == "22222"){
                cout<<"\tWelcome..."<<endl;
                system("CLS");
                cout<<"==========>> Patient <<=========="<<endl;
                cout<<"\t1.-> Patient Man"<<endl;
                cout<<"\t2.-> Patient Woman"<<endl;
                cout<<"\tWhich option that you want to choose: "; cin>>option;
                switch(option){
                    case 1:
                    system("CLS");
                    system("Color 0A"); 
                        pat.hospital_management_patient();
                        break;
                    case 2:
                    system("CLS");
                    system("Color 0A"); 
                        w.hospital_management_patient_woman();
                        break;
                }
            }
            else{
                cout << "\033[1;31m"; 
                cout<<"\n\tPlease try again!"<<endl;
            }
            break;
        case 3:
            exit(0);
        default:
            cout<<"\tInvalid Value...Please Try Again..."<<endl;
    }
    getch();
    goto p;
}while(choice != 3);
    return 0;
}

//end Hak
