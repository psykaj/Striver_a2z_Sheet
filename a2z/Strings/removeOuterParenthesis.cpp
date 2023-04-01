#include <iostream>
#include <string>
using namespace std;

string removeOuterParenthesis(string &str)
{
    string ans = "";
    int count = 0;
    bool flag = true;
    
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '(')
        {
            count++;
        }
        else if(str[i] == ')')
        {
            count--;
        }
        
        if(count == 1 && flag == true)
        {
            flag = false;
            continue;
        }
        
        if(count == 0 && flag == false)
        {
            flag = true;
            continue;
        }
        
        ans += str[i];
    }
    return ans;
}

int main()
{
    string str = "(()())(())";
    string res = removeOuterParenthesis(str);
    cout<<res<<" ";
    return 0;
}
