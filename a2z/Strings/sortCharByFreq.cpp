
//Optimise approch
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue> 
using namespace std;

//Tc = O(N) -> length of the string
//Sc = O(N) + O(N) -> map,priority_queue

string frequencySort(string &s)
{
    //Declare map
    unordered_map<char,int> mp;
    
    //Declare priority queue to store value according to frequency 
    priority_queue<pair<int,char>> pq;
    
    //to return final ans;
    string ans = "";
    
    //push values into the map 
    for(auto ch:s)
    {
        mp[ch]++;
    }
    
    //Now push values into the priority_queue
    for(auto x:mp)
    {
        //store first freq then char 
        pq.push({x.second,x.first});
    }
    
    while(!pq.empty())
    {
        //auto variable cause used in 2 data type 
        auto temp = pq.top();
        int freq = temp.first;
        char ch = temp.second;
        
        //string(freq,ch) will print char till frequency become 0 and concat to ans
        ans += string(freq,ch);
        //then pop from the pq
        pq.pop();
    }
    return ans;
}

int main()
{
    string s = "tree";
    string ans = frequencySort(s);
    cout<<ans<<endl;
    return 0;
}
