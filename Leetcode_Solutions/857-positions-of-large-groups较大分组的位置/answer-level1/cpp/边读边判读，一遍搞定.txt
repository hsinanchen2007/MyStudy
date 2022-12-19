```
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int start = 0, end = 0;
        for(end = 1;end < S.length(); end++)
        {
            if(S[end] != S[start])
            {
                if(end - start >= 3)
                {
                    vector<int> tmp;
                    tmp.push_back(start);
                    tmp.push_back(end-1);
                    res.push_back(tmp);
                }
                start = end;
            }
        }
        if(S[end-1] == S[start] && end - start >= 3)
        {
            vector<int> tmp;
            tmp.push_back(start);
            tmp.push_back(end-1);
            res.push_back(tmp);
        }
        return res;
    }
};

```