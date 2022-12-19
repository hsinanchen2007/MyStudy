```
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int n = 1;
        int w = 0;
        vector<int> ret;
        for(auto s:S)
        {
            if(w+widths[s-'a']<=100)
            {
                w += widths[s-'a'];
            }
            else
            {
                w = widths[s-'a'];
                n++;
            }
        }
        ret = {n, w};
        return ret;
    }
};
```
