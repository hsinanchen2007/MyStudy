```
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> res; res.clear();
        for(int j=0;j<A[0].size();j++)
        {
            res.push_back(vector<int>());
            for(int i=0;i<A.size();i++)
            {
                res[j].push_back(A[i][j]);
            }
        }
        return res;
    }
};
```