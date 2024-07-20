#include <iostream>
#include<ctime>
#include <unordered_map>
#include<fstream>
#include <iomanip>
#include<vector>
#include<algorithm>

using namespace std;

//Passenger Class
class Passenger{
    public:
    struct details{
        string passengerId,name,gender,nationality,ticketNumber,sNo,mp;
  	    int age,bl;
  	    char ch;
    };

     virtual void writePassengerDetailsIntoFile(details d[],fstream &p,int n){
            string s = "";
            p << "  Passenger No:  " << " | "  << "  Economy/Bussiness Passenger:  " << " | " << "  PassengerId  " << " | " << "  Name  "  << " | " << " Age " << " | " << "  Gender  " << " | " <<   "  Nationality  " <<  " | " << "  TicketNumber   |" ;
            p << endl;
            p << "---------------------------------------------------------------------------------------------------------------------------------------------";
            p << endl;

            for(int i = 0 ; i < n ; i++){
                if(d[i].ch == 'E' || d[i].ch == 'e'){
                    s = "Economy class Passenger";
                }
                else if(d[i].ch == 'B' || d[i].ch == 'b'){
                    s = "Business class Passenger";
                }
                p << "  Passenger-" << i+1 << ":   " << " | " << setw(32) << s << " | " << setw(15) << d[i].passengerId << " | " << setw(8) << d[i].name  << " | "  << setw(5) << d[i].age << " | "  << setw(10) << d[i].gender << " | " << setw(15) <<  d[i].nationality <<  " | " <<  setw(17) << d[i].ticketNumber   << "|" << endl;
                p << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
      }

    //Function Overriding
 	 virtual void showPassengerDetails(fstream &f2){
 	    string line;
      	while (getline(f2, line)) {
            cout << line << endl;
        }
   	}
};

//class to generate a random id
class GenerateId{
    public:
      string generatePassengerID() {
        time_t my_time = time(NULL);
        string s = ctime(&my_time);
        string h = s.substr(11,2);
        string m = s.substr(14,2);
        string se = s.substr(17,2);

        return h+m+se;
     }
};

//Class to give the meal preference or meal choice
class MealPreference: public Passenger{
 	public:
  	void showdet(int b,details d[],int i){
  	        vector<string> food;
  	        food.push_back("Butter Chicken & Naan");
            food.push_back("Parrota");
            food.push_back("Meals");
            food.push_back("HamBurger");
            food.push_back("Steak");
            food.push_back("Grilled Chicken");
            food.push_back("Sushi");
            food.push_back("Ramen");
            food.push_back("Misosoup");
            food.push_back("Jiangsu");
            food.push_back("Zhejiang");
            food.push_back("Fujian");
            food.push_back("Kimchi Fried Rice");
            food.push_back("Jajangmyeon");
            food.push_back("Tteokguk");

          	int c;

              switch(b){
            	case 1:
                    mn1:
                        cout << "Anything you can choose from " << endl  << "1." << food[0] << endl << "2." << food[1]  << endl << "3." << food[2] << endl;
                        cout << "Select the Dish Number : " ;
                        cin >> c;
                        if(c >= 1 && c <= 3 ){
                            d[i].mp = food[c-1];
                        }
                        else{
                             cout << "Enter the Correct Number for your Meal Preference." << endl;
                             goto mn1;
                        }
                        break;
            	case 2:
            	    mn2:
                        cout << "Anything you can choose from " << endl  << "1." << food[3] << endl << "2." << food[4]  << endl << "3." << food[5] << endl;
                        cout << "Select the Dish Number : " ;
                        cin >> c;
                        if(c >= 1 && c <= 3 ){
                             d[i].mp = food[c+2];
                        }
                        else{
                             cout << "Enter the Correct Number for your Meal Preference." << endl;
                             goto mn2;
                        }
                        break;
            	case 3:
                    mn3:
                        cout << "Anything you can choose from " << endl  << "1." << food[6] << endl << "2." << food[7]  << endl << "3." << food[8] << endl;
                        cout << "Select the Dish Number : " ;
                        cin >> c;
                        if(c >= 1 && c <= 3 ){
                            d[i].mp = food[c+5];
                        }
                        else{
                            cout << "Enter the Correct Number for your Meal Preference." << endl;
                            goto mn3;
                        }
                        break;
            	case 4:
            	    mn4:
                        cout << "Anything you can choose from " << endl  << "1." << food[9] << endl << "2." << food[10]  << endl << "3." << food[11] << endl;
                        cout << "Select the Dish Number : " ;
                        cin >> c;
                        if(c >= 1 && c <= 3 )
                            d[i].mp = food[c+8];
                        else{
                            cout << "Enter the Correct Number for your Meal Preference." << endl;
                            goto mn4;
                        }
                        break;
            	case 5:
            	    mn5:
                        cout << "Anything you can choose from " << endl  << "1." << food[12] << endl << "2." << food[13]  << endl << "3." << food[14] << endl;
                        cout << "Select the Dish Number : " ;
                        cin >> c;
                        if(c >= 1 && c <= 3 )
                             d[i].mp = food[c+11];
                        else{
                            cout << "Enter the Correct Number for your Meal Preference." << endl;
                            goto mn4;
                        }
                        break;
          	}
   	}

   	void showMenuForFood(details d[],int i){
       	int selectNumber;

       	cout << endl;
       	cout.width(20);

        cout << "Cuisines Available for Meal Preference.." << endl;
       	cout << "1.Indian" << endl;
       	cout << "2.American" << endl;
       	cout << "3.Japanese" << endl;
       	cout << "4.Chinese" << endl;
       	cout << "5.Korean" << endl;

       	sNu:
       	cout << "Select Your Cuisine Number: " ;
       	cin >>  selectNumber ;
       	if(selectNumber > 5 || selectNumber < 1){
            cout << "Please choose the correct cuisine." << endl;
            goto sNu;
       	}
       	else{
           switch(selectNumber){
                case 1:
                    showdet(1,d,i);
                    break;
                case 2:
                    showdet(2,d,i);
                    break;
                 case 3:
                    showdet(3,d,i);
                    break;
                case 4:
                    showdet(4,d,i);
                    break;
                case 5:
                    showdet(5,d,i);
                    break;
           }
       	}

   	}
};

//Multiple Inheritance(Economy Passenger Class)
class EconomyPassenger : public Passenger,MealPreference{
	private:
   	string sNo;
   	int bl;

	public:
   	void setEconomypassengerRequirements(details d[],int i){
       MealPreference m1;
       cout << "Enter your seatNumber:";
            cin >> d[i].sNo;
       m1.showMenuForFood(d,i);
       try{
           cout << "Enter your Baggage Limit (in kgs):";
            cin >> d[i].bl;
            if(d[i].bl > 30){
                throw 0;
            }
       }
       catch(...){
            cout << "Your Bag Limit was overload." << endl;
            exit(0);
       }
   	}

   	 void writeEconomyPassengerDetailsIntoFile(details d,fstream &ep,int i){
            string s = "";
            ep << "  Passenger No:  "  << " | " << "  PassengerId  " << " | " << "  Name  "  << " | " << "  Seat Number  " << " | " <<   "    MealPreferred    " <<  " | " << "  Baggage Limit |" ;
            ep << endl;
            ep << "------------------------------------------------------------------------------------------------------------";
            ep << endl;

            ep << "  Passenger-" << i+1 << ":   " << " | " << setw(15) << d.passengerId << " | " << setw(8) << d.name  << " | "  << setw(15) << d.sNo << " | "  << setw(17) << d.mp << " | " << setw(16) <<  d.bl <<  "| " << endl;
            ep << "------------------------------------------------------------------------------------------------------------" << endl;
      }

   	 //Function overriding
   	 void showPassengerDetails(fstream &f4){
        string line;
      	while (getline(f4, line)) {
            cout << line << endl;
        }
   	 }
};

//Multiple Inheritance(Bussiness Passenger)
class BussinessPassenger : public Passenger,MealPreference{
	private:
   	string sNo;
   	int bl;

	public:
   	void setBussinesspassengerRequirements(details d[],int i){
       MealPreference m1;
       cout << "Enter your seatNumber:";
         cin >> d[i].sNo;
       m1.showMenuForFood(d,i);
       try{
           cout << "Enter your Baggage Limit (in kgs):";
            cin >> d[i].bl;
            if(d[i].bl > 35){
                throw 0;
            }
       }
       catch(...){
            cout << "Your Bag Limit was overload." << endl;
            exit(0);
       }
   	}

   	 void writeBussinessPassengerDetailsIntoFile(details d,fstream &bp,int i){
            bp << "  Passenger No:  "  << " | " << "  PassengerId  " << " | " << "  Name  "  << " | " << "  Seat Number  " << " | " <<   "    MealPreferred    " <<  " | " << "  Baggage Limit " << " | " << "  Priority Boarding/Lounge Access|" ;
            bp << endl;
            bp << "-----------------------------------------------------------------------------------------------------------------------------------------------";
            bp << endl;

            bp << "  Passenger-" << i+1 << ":   " << " | " << setw(15) << d.passengerId << " | " << setw(8) << d.name  << " | "  << setw(15) << d.sNo << " | "  << setw(17) << d.mp << " | " << setw(16) <<  d.bl <<  " | " << setw(35) << " Yes|" << endl;
            bp << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
      }

   	 //Function overriding
   	 void showPassengerDetails(fstream &f5){
        string line;
      	while (getline(f5, line)) {
            cout << line << endl;
        }
   	 }
};

//Luggage Class to store luggage details
class Luggage:public Passenger
{
public:
    struct lug
    {
            string LuggageID,size1,contents;
            vector<string> con;
    };

    void writeLuggageDetailsIntoFile(lug l[], fstream &p, int n, details d[],int i) {
            p << " Passenger Id " << " | "  << " Luggage Id " << " | " << " Size " << " | " << " Contents " << endl;
            p << "------------------------------------------------------------------------------------" << endl;

            p << setw(14) << d[i].passengerId << " | " << setw(12) << l[i].LuggageID << " | " << setw(8) << l[i].size1 << " | ";

            for (auto item : l[i].con) {
                p << item << ", ";
            }

            p.seekp(-2, p.cur);
            p <<"|" << setw(50) <<endl;
            p<<"---------------------------------------------------------------------------------------"<<endl;
    }

    void showluggageDetails(fstream &f5){
        string line;
      	while (getline(f5, line)) {
            cout << line << endl;
        }
   	 }
};


class LuggageDet:public Luggage,Passenger,GenerateId
{
public:
    GenerateId g1;
    void printDetails(){
        cout<<setw(70)<<"The Things Are Allowed to Carry in your luggage"<<endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cout<<"S.No|"<<"                    Things                      |"<<"Applicable/Not Applicable|"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<" 1  |"<<"Sports Equipments (Bat,Balls,etc... )           |"<<"     Applicable          |"<<endl;
        cout<<" 2  |"<<"Weaponary,explosives & ammunition               |"<<"     Not Applicable      |"<<endl;
        cout<<" 3  |"<<"Satellite phones without authorisation from BSNL|"<<"     Not Applicable      |"<<endl;
        cout<<" 4  |"<<"Mobile Phones,Camcorder & Camera Equipments     |"<<"     Applicable          |"<<endl;
        cout<<" 5  |"<<"Diabetes-related supplies/equipment             |"<<"     Applicable          |"<<endl;
        cout<<" 6  |"<<"Gasoline,Fuels,Chlorine,Liquid Bleach           |"<<"     Not Applicable      |"<<endl;
        cout<<" 7  |"<<"Foldable Umbrellas,Eye Curlers                  |"<<"     Applicable          |"<<endl;
        cout<<" 8  |"<<"Clothes,Perfumes,Bakery Items                   |"<<"     Applicable          |"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<endl;
    }

    void SetLuggageDetails(fstream &f7,int i,int n,details d[])
    {
        string u = g1.generatePassengerID();
        string li = "l"+u;
        lug l[n];

        char y_n;

        cout<<"Your Luggage Id is : "<< li <<endl;
        cout<<"Do You want to change Your Luggage Id (y/n):";
        cin>>y_n;
        string conv;
        yn:
        if(y_n=='y' || y_n=='Y')
        {
           cout<<"Enter the new Luggage Id: ";
           cin >> l[i].LuggageID;
           cout << "Luggage Id Updated Successfully.." << endl;
        }
        else if(y_n=='n'||y_n=='N')
        {
            l[i].LuggageID=li;
        }
        else
        {
            cout << "Enter the correct value to change the id." << endl;
            goto yn;
        }

        che:
        cout<<"Enter the size of the Luggage (S(small)/M(medium)/B(big)):";
        cin>>l[i].size1;
        if(l[i].size1 == "s" || l[i].size1 =="S"){
            l[i].size1 = "Small";
        }
        else if(l[i].size1 == "m" || l[i].size1 == "M"){
            l[i].size1 = "Medium";
        }
        else if(l[i].size1 == "B" || l[i].size1 == "b"){
            l[i].size1 = "Big";
        }
        else{
            cout<<"Please Enter the valid detail" << endl;
            goto che;
        }

        cout<<endl;
        cout<<endl;
        printDetails();

        cout<<setw(70)<<"You can add the above-mentioned applicable items to your luggage"<<endl;
        cout<<"How many items do you want to add (limit 3): ";
        int n_item,item;
        noitem:
        cin>>n_item;
        if(n_item>3)
        {
            goto noitem;
        }
        for (int j = 0; j < n_item; j++) {
            ite:
            cout << "Enter the corresponding serial number for the items you want: ";
            cin >> item;
            if (item != 1 && item != 4 && item != 5 && item != 7 && item!=8) {
                cout << "This item is not applicable to add to your luggage. Please add valid items..." << endl;
                goto ite;
            } else {
                if (item == 1) {
                    l[i].con.push_back("Sports Equipments (Bat, Balls, etc...)");
                } else if (item == 4) {
                    l[i].con.push_back("Mobile Phones, Camcorder & Camera Equipments");
                } else if (item == 5) {
                    l[i].con.push_back("Diabetes-related supplies/equipment");
                } else if (item == 7) {
                    l[i].con.push_back("Foldable Umbrellas, Eye Curlers");
                }
                else if(item==8)
                {
                    l[i].con.push_back("Clothes,Perfumes,Bakery Items");
                }
            }
        }

        sort(l[i].con.begin(),l[i].con.end());
        auto it = unique(l[i].con.begin(), l[i].con.end());
        l[i].con.erase(it,l[i].con.end());
        cout<<endl;
        cout<<"Items you have selected:"<<endl;
        for(auto v:l[i].con)
        {
            cout<<v<<endl;
        }

         cout << "\n\n" << endl;
         writeLuggageDetailsIntoFile(l,f7,n,d,i);
    }

};


//Common class to access every class
class Info : public Passenger,EconomyPassenger,BussinessPassenger,LuggageDet,GenerateId{
    public:
        EconomyPassenger ep1;
        BussinessPassenger bp1;
        Passenger ps;
        LuggageDet l1;

        char gen;

        unordered_map<string,details> umap;

        void setPassengerDetails(int n,fstream &f1,fstream &f2,fstream &f3,fstream &f4){
            GenerateId g1;
            char y_n;


            details d[n];
            try{
                for(int i = 0 ; i < n ; i++){
                     cout << endl;
                     cout.width(70);
                     cout << "Getting the details of Passenger " << i+1 << ":" << endl;
                     cout << endl;
                     check:
                     cout << "Economy Class Passenger or Bussiness Class Passenger(B or E) :";
                        cin >> d[i].ch;
                     if(d[i].ch != 'E' && d[i].ch != 'e' && d[i].ch != 'B' && d[i].ch != 'b'){
                        cout << endl;
                        cout << "Enter the correct Character to choose Economy or Bussiness Class Passenger." << endl;
                        goto check;
                     }
                     string u = g1.generatePassengerID();
                     string p = "p"+u;
                     cout << "Your passenger Id is : " + p << endl;
                        d[i].passengerId = p;
		     yn:
                     cout<<"Do You want to change Your Passenger Id (y/n):";
                     cin>>y_n;
                     if(y_n=='y' || y_n=='Y')
                     {
                        cout<<"Enter the new Passenger Id: ";
                        cin >> d[i].passengerId;
                        cout << "Passenger Id Updated Successfully.." << endl;
                        cout << "You can verify your details with the new Id." << endl;
                     }
                     else if(y_n=='n'||y_n=='N')
                     {
                        d[i].passengerId = p;
                     }
                     else
                     {
                        cout << "Enter the correct value to change the id." << endl;
                        goto yn;
                     }
                     cout << "Enter your name:";
                        cin >> d[i].name;
                     ai:
                     cout << "Enter your age:";
                        cin >> d[i].age;
                        if(cin.fail()){
                            cout << "Please Enter the correct value for age.." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            goto ai;
                        }
                        if(d[i].age > 150){
                            goto ai;
                        }
                        e:
                        cout << "Enter your Gender(M/F/O):";
                        cin >> gen;
                        if(gen == 'm' || gen == 'M'){
                            d[i].gender = "Male";
                        }
                        else if(gen == 'f' || gen == 'F'){
                            d[i].gender = "Female";
                        }
                        else if(gen == 'o' || gen == 'O'){
                            d[i].gender = "Other";
                        }
                        else{
                            cout << "Please enter the correct character to choose gender" << endl;
                            goto e;
                        }

                     cout << "Enter your Nationality :";
                        cin >> d[i].nationality;
                     cout << "Enter your TicketNumber :";
                        cin >> d[i].ticketNumber;

                    if(d[i].ch == 'E' || d[i].ch == 'e'){
                        ep1.setEconomypassengerRequirements(d,i);
                        ep1.writeEconomyPassengerDetailsIntoFile(d[i],f2,i);
                    }
                    else if(d[i].ch == 'B' || d[i].ch == 'b'){
                        bp1.setBussinesspassengerRequirements(d,i);
                        bp1.writeBussinessPassengerDetailsIntoFile(d[i],f3,i);
                    }
                    umap[d[i].passengerId] = d[i];
                    l1.SetLuggageDetails(f4,i,n,d);
                }
                ps.writePassengerDetailsIntoFile(d,f1,n);
            }
            catch(...){
                cout << "Please Enter the correct information." << endl;
            }

  	}

  	 int FetchDetails(string Pid) {
        if (umap.find(Pid) != umap.end()) {
            details d1 = umap[Pid];
            cout << "Passenger Type : " << d1.ch << endl;
            cout << "Name: " << d1.name << endl;
            cout << "Age: " << d1.age << endl;
            cout << "Gender: " << d1.gender << endl;
            cout << "Nationality " << d1.nationality << endl;
            cout << "Ticket Number: " << d1.ticketNumber << endl;
            cout << "Seat Number: " << d1.sNo << endl;
            cout << "Meal Preferred: " << d1.mp << endl;
            return 1;
        }
        return 0;
    }

    ~Info() {
        umap.clear();
    }
};


int main(){
       cout.width(110);
       cout << "..AIRLINE PASSENGER AND LUGGAGE MANAGEMENT SYSTEM.." << endl ;
       cout << "\n" << endl;

       int tot_pass,bl,c;
       string pId,s;

       tot:
       cout << "Enter the total Number of Passenger: " ;
       cin >> tot_pass;

       if(cin.fail()){
            cout << "Please Enter the correct number of passengers.." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto tot;
       }



       fstream f1,f2,f3,f4,f5,f6,f7,f8;
       f1.open("passenger_details.txt",ios::out);
       f2.open("economy_passenger.txt",ios::out);
       f3.open("bussiness_passenger.txt",ios::out);
       f7.open("luggage.txt",ios::out);

       Info p1;
       LuggageDet l1;
       p1.setPassengerDetails(tot_pass, f1, f2, f3 , f7);

       while(true){
           cout << "Do you want to verify your details:" << endl;
           val:
            cout << "If Yes,Press 1 otherwise Press 0." << endl;
            cin >> c;
            if(c == 0){
                break;
            }
            try {
                if (c > 1) {
                    throw (404);
                }
                else if (c == 1) {
                ele:
                    cout << "Enter your PassengerId :";
                    cin >> pId;
                    if (pId == "0") {
                        goto x;
                        break;
                    }
                    cout << endl;
                    cout << setw(50) << " Fetching your details.... " << endl;
                    try {
                        if (p1.FetchDetails(pId) == 0) {
                            throw 0;
                        }
                    }
                    catch (...) {
                        cout << "Enter the correct Passenger Id." << endl;
                        goto ele;
                    }
                }
            }
            catch (...) {
                cout << "Enter the correct number to check your details." << endl;
                goto val;
            }
       }

           x:
           cout << "If you are a manager enter the secret code to see all Passengerdetails : " ;
           cin >> s;
           cout << "\n\n" << endl;
           if(s == "iammanager"){
               cout.width(70);
               cout << "Passenger Details.." << endl;
               Passenger p;
               f4.open("passenger_details.txt",ios::in);
               p.showPassengerDetails(f4);
               cout << "\n\n" << endl;

               cout.width(70);
               cout << "Economy Passenger Details.." << endl;
               EconomyPassenger e1;
               f5.open("economy_passenger.txt",ios::in);
               e1.showPassengerDetails(f5);
               cout << "\n\n" << endl;

               cout.width(70);
               cout << "Bussiness Passenger Details.." << endl;
               BussinessPassenger b1;
               f6.open("bussiness_passenger.txt",ios::in);
               b1.showPassengerDetails(f6);
               cout << "\n\n" << endl;

               cout.width(70);
               cout << "Luggage Details.." << endl;
               Luggage l1;
               f8.open("luggage.txt",ios::in);
               l1.showluggageDetails(f8);
           }

        return 0;
}