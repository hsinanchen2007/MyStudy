### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& myVec) {
    int m = myVec[0].size();
    int n = myVec.size();
    for (int i = 1; i < m; ++i) {
        myVec[0][i] += myVec[0][i - 1];
    }
    for (int j = 1; j < n; ++j) {
        myVec[j][0] += myVec[j - 1][0];
    }
    for (int k = 1; k < n; ++k) {
        for (int i = 1; i < m; ++i) {
            myVec[k][i] += min(myVec[k - 1][i], myVec[k][i - 1]);
        }
    }
    return myVec[n-1][m-1];
}
};
```