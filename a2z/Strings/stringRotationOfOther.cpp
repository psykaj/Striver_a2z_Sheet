//Brute force approch
#include <iostream>
#include <string>
using namespace std;

//Tc = O(N) => traverse str1 loop
//Sc = O(1) => constant space

bool isRotation(string &str1,string &str2)
{
    int n = str1.length();
    int m = str2.length();
    
    //base case
    if(n != m)
    {
        return false;
    }
    
    string temp = str1 + str1;
    
    //string::npos => simply means till end of the strings
    if(temp.find(str2) != string::npos)
    {
        return true;
    }
    return false;
}

int main()
{
    string str1 = "geeksforgeeks";
    string str2 = "forgeeksgeeks";
    
    bool ans = isRotation(str1,str2);
    
    if(ans == true)
    {
        cout<<"Str1 is a rotation of Str2"<<endl;
    }
    else
    {
        cout<<"Str1 is not a rotation of Str2"<<endl;
    }

    return 0;
}
