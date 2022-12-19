```
class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map<char,int> s_map;
        for(auto it:s)
            s_map[it]++;
        
        unordered_map<char,int> t_map;
        for(auto it:t)
            t_map[it]++;

        for(auto it:t_map)
        {
            if(it.second != s_map[it.first])
                return it.first;
        }
        
        return t[0];  //此句无意义 
    }
};
```
