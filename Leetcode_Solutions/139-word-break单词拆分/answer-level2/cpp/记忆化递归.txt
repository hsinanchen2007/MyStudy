走过的路用hash表存储
```
class Solution {
public:
    bool f=false;
    map<char,vector<string>> mp;
    map<string,bool> judge;
    bool wordBreak(string s, vector<string>& wordDict) {
    for(auto i:wordDict) mp[i[0]].push_back(i);
    wordBreak(s);
    return f;
    }
    void wordBreak(string s)
    {
        if(s.empty()) 
        {
            f=true;
            return;
        }
        if(judge[s]) return;
        for(auto i:mp[s[0]])
        {
            string temp=s.substr(0,i.size());
            int k=s.size()-i.size();
            if(k>=0)
            {
                if(i==temp)
                {
                     wordBreak(s.substr(i.size(),k));
                    string temp=s.substr(i.size(),k);
                    judge[temp]=true;
                }
            }
        }
    }
};
```
