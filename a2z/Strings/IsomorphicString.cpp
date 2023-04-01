//Brute force approch
#include <iostream>
#include <unordered_map>
using namespace std;

//Tc = O(N+M);
//Sc = O(1);

bool isIsomorphic(string &str1,string &str2)
{
    int n = str1.length();
    int m = str2.length();
    
    //Base case
    if(n != m)
    {
        return false;
    }
    
    unordered_map<char,char> mp1;
    unordered_map<char,char> mp2;
    
    for(int i=0;i<n;i++)
    {
        if(mp1.find(str1[i]) == mp1.end() && mp2.find(str2[i]) == mp2.end())
        {
            mp1[str1[i]] = str2[i];
            mp2[str2[i]] = str1[i];
        }
        else
        {
            if(mp1[str1[i]] != str2[i] || mp2[str2[i]] != str1[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string str1 = "aab";
    string str2 = "xxy";
    
    bool ans = isIsomorphic(str1,str2);
    
    if(ans)
    {
        cout<<"Both the strings are isomorphic of each other";
    }
    else
    {
        cout<<"Both the strings are not isomorphic of each other";
    }
    return 0;
}
