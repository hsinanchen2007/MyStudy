```
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int mp[] = {1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};
        int i = 0;
        int j = 0;
        vector<string> ret;
        for(auto w:words)
        {
            i = mp[tolower(w[0])-'a'];
            for (j=1; j<w.size(); j++)
            {
                if(mp[tolower(w[j])-'a'] != i)
                {
                    break;
                }
            }
            if(j==w.size())
                ret.push_back(w);
        }
        return ret;
    }
};
```
