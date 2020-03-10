//Write your code here
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

string upper (string );

int main(){
    vector<string> v_name,v_grade;
    string Gscore;
    int num1,num2,num3,total;
    char name[100];
    ifstream note("name_score.txt");
    string s;
    while (getline(note,s))
    {
        sscanf(s.c_str(),"%[^:]:%d %d %d",name,&num1,&num2,&num3);
        v_name.push_back(name);
        total=0;
        total=num1+num2+num3;
        if (total>=80)  Gscore = "A" ;
        else if (total>=70 && total<=79) Gscore = "B" ;
        else if (total>=60 && total<=69) Gscore = "C" ;
        else if (total>=50 && total<=59) Gscore = "D" ;
        else if (total< 50 ) Gscore = "F";
        v_grade.push_back(Gscore);

    }
    
    while (true){
        cout<<"Pleaes input your command : ";
        getline(cin,s);
        int idx =s.find_first_of(" ");
        string s1= upper(s.substr(0,idx));
        string s2= upper(s.substr(idx+1,s.size()));
        
        if(s1=="NAME"){
            cout<<"---------------------------------"<<"\n";
            int n=0;
            for (int i=0; i < v_name.size();i++) {
                if (s2 == upper(v_name[i]))
                {
                    cout<<v_name[i]<<"'s grade = "<<v_grade[i]<<'\n';
                    n++;
                }
                
            }
            if (n == 0) cout<<"Cannot found."<<"\n";
            cout<<"---------------------------------"<<"\n";
        }
        else if (s1=="GRADE"){
            cout<<"---------------------------------"<<"\n";
            for (int i = 0; i < v_grade.size(); i++){
                if (s2 == upper(v_grade[i]))
                {
                    cout<<v_name[i]<<"\n";
                }
                
            }
            cout<<"---------------------------------"<<"\n";
        }
        else if (s1=="EXIT"){
            break;
        }
        else {
            cout<<"Invalid command.\n";
        }
        
    }
}


string upper (string s){
    int i =0;
    while (s[i])
    {
        s[i]=toupper(s[i]);
        i++;
    }
    
    return s ;
}
