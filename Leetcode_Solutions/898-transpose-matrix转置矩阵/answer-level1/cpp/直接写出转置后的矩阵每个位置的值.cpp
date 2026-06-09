
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> res(A[0].size());
        for(int i=0;i<A[0].size();i++)
            for(int j=0;j<A.size();j++)
                res[i].push_back(A[j][i]);
        return res;
    }
};
```