```
class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
        string q{"qwertyuiop"};
        string a{"asdfghjkl"};
        string z{"zxcvbnm"};
        vector<string> ans;    

        for(int i=0;i<words.size();i++)
        {
            int d=0,b=0,c=0;
            for(int j=0;j<words[i].size();j++)
            {
                if(q.find(tolower(words[i][j]))!=string::npos) b++;
                if(a.find(tolower(words[i][j]))!=string::npos) c++;
                if(z.find(tolower(words[i][j]))!=string::npos) d++;
            }
            if(b==words[i].size()||c==words[i].size()||d==words[i].size()) 
                ans.push_back(words[i]);
        }
        return ans;      
    }
};
```
