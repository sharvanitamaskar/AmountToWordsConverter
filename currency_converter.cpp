#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace std;
class am
{
    public:
            int currency_convert();
};

    string one[] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ",
                        "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ","Nineteen "};
    string ten[] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

    string decimal_convert(double num2,string s)//two decimal digit
    {
        string str="";
        int c=num2*100;
            if (num2>0.19)
            {

                str =str + ten[c/10]+one[c%10];
            }
            else
            {

                str =str + one[c];
            }
            if (num2!=0)
                str += s;
        return str;
    }

    string num_to_Words(int num1, string s)//two digit
    {
        string str = "";
        if (num1 > 19)
            str =str + ten[num1/10]+one[num1%10];
        else
            str =str + one[num1];
        if (num1!=0)
            str += s;
        return str;
    }

    string convert_to_rupee(long num1)
    {
        string out;

        out += num_to_Words(((num1 / 1000000000)%10),"Hundred and ");
        out += num_to_Words(((num1 / 10000000)%100) ,"Crore ");
        out += num_to_Words(((num1 / 100000)%100),"Lakh ");
        out += num_to_Words(((num1 / 1000) % 100),"Thousand ");
        out += num_to_Words(((num1 / 100) % 10) ,"Hundred ");
        if (num1 > 100 && num1 % 100)
        {
            out += "and ";
        }
        out += num_to_Words((num1 % 100), "");
        return out;
    }

    string convert_to_paise(double num2)
    {
        long c;
        string out;
        c=num2*100;
        out = decimal_convert((num2),"");
        return out;
    }

    string convert_to_dollar(long num1)
    {
        string out;
        out += num_to_Words((num1 / 1000000000)%100, "Billion ");
        out += num_to_Words((num1 / 100000000), "Hundred and ");
        out += num_to_Words(((num1 / 1000000) % 100), "Million ");
        out += num_to_Words(((num1 / 100000)% 10), "Hundred and ");
        out += num_to_Words(((num1 / 1000) % 100), "Thousand ");
        out += num_to_Words(((num1 / 100) % 10), "Hundred ");
        if (num1 > 100 && num1 % 100)
            out += "and ";
        out += num_to_Words((num1 % 100), "");
        return out;
    }

    string convert_to_pound(long num1)
    {
        string out;
        out += num_to_Words((num1 / 1000000000)%100, "Billion ");
        out += num_to_Words((num1 / 100000000), "Hundred and ");
        out += num_to_Words(((num1 / 1000000) % 100), "Million ");
        out += num_to_Words(((num1 / 100000)% 10), "Hundred and ");
        out += num_to_Words(((num1 / 1000) % 100), "Thousand ");
        out += num_to_Words(((num1 / 100) % 10), "Hundred ");
        if (num1 > 100 && num1 % 100)
            out += "and ";
        out += num_to_Words((num1 % 100), "");
        return out;
    }

    double convert(std::string string)
    {
        std::stringstream s(string);
        double num = 0;
        s >> num;
        return num;
    }

    bool check_string(string string_num)
    {
        for (int i = 0; i < string_num.length(); i++)
        if ((isdigit(string_num[i]) == false)&&((string_num[i])!='.'))
            return false;
        return true;
    }

    int currency_convert(string string_num,string error)
    {
        double num,num2,num1;
        string s;
        int sn;
        int i=0;
        stringstream ss(string_num);
        ss >> num;
        num2 = std::modf(num,&num1);

        if(check_string(string_num))
        {
            if(num2>0.0)
            {
                cout<<"INR "<<convert_to_rupee(num1)<<"Rupees and ";
                cout<<convert_to_paise(num2)<<"Paise"<<endl;
                cout<<"$   "<<convert_to_dollar(num)<<"Dollars and ";
                cout<<convert_to_paise(num2)<<"Cent"<<endl ;
                cout<<"#   "<<convert_to_pound(num)<<"Pounds and ";;
                cout<<convert_to_paise(num2)<<"Pense"<<endl ;
            }
            else
            {
                cout<<"INR "<<convert_to_rupee(num1)<<"Rupees "<<endl;
                cout<<"$   "<<convert_to_dollar(num)<<"Dollars "<<endl;
                cout<<"#   "<<convert_to_pound(num)<<"Pounds "<<endl;
            }
        }
        else
        {
            error=string_num;
            cout<<"Invalid input."<<endl;
            cout<<error<<endl;
            return 0;
        }//end of else
        return 0;
    }

    int main()
    {
        double num,num2,num1;
        string s,string_num,error;
        int sn;
        int i=0;
        do
        {
            cout<<"\n\nInput the amount you want to convert in words:";
            cin>>string_num;
            currency_convert(string_num,error);
            i++;
        }//end of do
        while(i>0);
        return 0;
    }//end of main
