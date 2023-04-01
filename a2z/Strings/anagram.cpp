/*//Brute force approch
#include <iostream>
#include <algorithm>
using namespace std;

//Tc = O(NlogN) => for sorting
//Sc = O(1) => constant space

bool isAnagram(string &str1,string &str2)
{
    int n = str1.length();
    int m = str2.length();
    
    //base case
    if(n != m)
    {
       return false; 
    }
    
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    
    for(int i=0;i<n;i++)
    {
        if(str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1 = "INTEGER";
    string str2 = "TEGERNI";
    if(isAnagram(str1,str2))
    {
        cout<<"strings are anagram of each other"<<endl;
    }
    else
    {
        cout<<"strings are not anagram of each other"<<endl;
    }

    return 0;
}*/


//Optimise approch
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Tc = O(N) => N is a length of the string
//Sc = O(1) => constant space

bool isAnagram(string &str1,string &str2)
{
    int n = str1.length();
    int m = str2.length();
    
    //base case
    if(n != m)
    {
       return false; 
    }
    
    //sort(str1.begin(),str1.end());
    //sort(str2.begin(),str2.end());
    
    int freq[26] = {0};
    
    for(int i=0;i<n;i++)
    {
        freq[str1[i] - 'A']++;
    }
    
    for(int i=0;i<m;i++)
    {
        freq[str2[i] - 'A']--;
    }
    
    for(int i=0;i<26;i++)
    {
        if(freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1 = "INTEGER";
    string str2 = "TEGERNI";
    if(isAnagram(str1,str2))
    {
        cout<<"strings are anagram of each other"<<endl;
    }
    else
    {
        cout<<"strings are not anagram of each other"<<endl;
    }

    return 0;
}

