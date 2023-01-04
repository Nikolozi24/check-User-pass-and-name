#include<cmath>
#include <iostream>
#include<fstream>
#include<string>
#include<array>
using namespace std;
class User{
    string name;
    string password;
public:
    User()=default;
    ~User()=default;
    User(string nam , string pass){
         name = nam;
        password = pass;
    }
    string getName(){ return name;}
    void setName(string value){
        if(value.empty()){
            cout<<"Error! , name is not valid! string is empty!\n";
        }
        else
        if(stringContainNumber(value)){
            cout<<"your name "<<value<<" is contain number\n";
        }
        else{
            name=value;
        }
    }
    string getPassword(){return password;}
    void setPassword(string value){
        if(value.empty()){
            cout<<"your password is empty!\n";
        }
        else
        if(stringContainNumber(value)){
            cout<<"password  must not contain number and your pass is:"<<value<<endl;
        }
        else
            if(value.size()<8){
                cout<<"password length must be greater or equal 8\n";
            }
        else{
            password = value;
        }
    }
    bool stringContainNumber( string val){
        int size = val.size();
        for(int i =0; i<size; i++){
            if(val[i]=='0'||val[i]=='1'||val[i]=='2'||val[i]=='3'|| val[i]=='4'||val[i]=='5'||val[i]=='6'||val[i]=='7'|| val[i]=='8'||val[i]=='9' )
                return true;
        }
        return false;
    }
     bool operator<(User& otherUser){
         if(name<=otherUser.name){
             return true;
         }
         else{
             return false;
         }
     } 
     User operator=(User& otherUser){
         User newUser("tegfdgst" ,"testfdfdgdgfg");
         newUser.setName(name);
         newUser.setPassword(password);
        return newUser;
     }
};
void Myswap( User *str1 , User *str2){
   User *temp = str1;
    *str1 = *str2;
   *str2 =*temp;
}
int main()
{
    int N =5 , i, j ;
    array<User,5>   userArr;
    string name , password;
    ifstream ifs("data.txt");
    for(i = 0; i<N; i++){
        ifs>>name;
        ifs>>password;
        userArr[i].setName(name);
        userArr[i].setPassword(password);
    }
    for(i=0 ; i<N; i++){
        j=i;
        while(j!=0 || userArr[j]<userArr[j-1]){
            Myswap(&userArr[j] , &userArr[j-1]);
            j--;
        }
    }
    return 0;
}