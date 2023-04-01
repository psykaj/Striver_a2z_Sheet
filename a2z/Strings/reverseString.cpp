//Brute force approch
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Tc = O(N) -> traverse the entire string
//Sc = O(N) -> taken stack and variables

int main()
{
    string s = "This is an amazing program";
    s += " ";
    stack<string> st;
    int i;
    string str = "";
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ' ')
        {
           st.push(str);
           str = "";
        }
        else
        {
            str += s[i];
        }
    }
    
    string ans = "";
    
    while(st.size() != 1)
    {
        ans += st.top() + " ";
        st.pop();
    }
    
    ans += st.top(); //cause last word in string do nit have space
    
    cout<<ans;
    
    return 0;
}

//Optimise approch
#include <iostream>
#include <string>
using namespace std;

//Tc = O(N) -> n is the length of the string 
//Sc = O(1)

string result(string &str)
{
    int start = 0;
    int end = str.length()-1;
    
    string temp = "";
    string ans = "";
    
    while(start <= end)
    {
        if(str[start] != ' ')
        {
            temp += str[start];
        }
        else
        {
            if(ans != "")
            {
                ans = temp + " " + ans;
            }
            else
            {
                ans = temp;
            }
            temp = "";
        }
        start++;
    }
    
    //for the last word in the string 
    if(temp != "")
    {
        if(ans != "")
        {
            ans = temp + " " + ans;
        }
        else
        {
            ans = temp;
        }
    }
    return ans;
}

int main()
{
    string str = "TUF is great for interview preparation";
    cout<<"Before reversing the word : "<<str<<endl;
    cout<<"After reversing the word : "<<result(str)<<endl;

    return 0;
}

