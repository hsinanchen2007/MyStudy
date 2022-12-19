### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        // vector<vector<int> > res(A[0].size());
        // for(int i = 0; i < A[0].size(); i++)
        // {
        //     res[i].rezise(A.size());
        // }
        vector<vector<int>> res(A[0].size(), vector<int>(A.size(), 0));
        for(int i = 0; i < res.size(); i++)
            for(int j = 0; j < res[0].size(); j++)
            {
                res[i][j] = A[j][i];
            }

        return res;
    }
};
```