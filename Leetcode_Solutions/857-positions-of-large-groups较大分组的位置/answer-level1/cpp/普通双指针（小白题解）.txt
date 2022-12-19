
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) 
    {
        vector<vector<int>> res;

        int lo=0,hi=0;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]==S[lo]) hi=i;
            else
            {
                if(hi-lo>1) res.push_back({lo,hi});
                lo=i;
            }
        }
        if(hi-lo>1) res.push_back({lo,hi});

        return res;
    }
};
```