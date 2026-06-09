```
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> ptmap;
        map<string, int> stmap;
        vector<int> vp, vs;
        for(int i=0; i<pattern.size(); i++)
        {
            if(ptmap.count(pattern[i]) == 0)
            {
                ptmap[pattern[i]] = i;
                vp.push_back(i);
            }
            else
            {
                vp.push_back(ptmap[pattern[i]]);
            }
        }
        int i = 0;
        int j = 0;
        int n = 0;
        string s;
        while(i<str.size())
        {
            while(j<str.size() && str[j] != ' ')
                j++;
            s = str.substr(i, j-i);
            i = ++j;
            if(stmap.count(s) == 0)
            {
                stmap[s] = n;
                vs.push_back(n);
            }
            else
            {
                vs.push_back(stmap[s]);
            }
            n++;       
        }
        return vp == vs;
    }
};
```
