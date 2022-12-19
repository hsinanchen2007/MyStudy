## 思路
### 代码
```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {        
        vector<vector<int>> res(numRows);        
        for (int i = 0; i < numRows; ++i) {
            vector<int> tmp(i + 1);
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0 || j == i) {
                    tmp[j] = 1;
                } else {
                    tmp[j] = res[i - 1][j] + res[i - 1][j - 1];
                }
            }
            res[i] = tmp;
        }
        return res;                                  
    }
};
```
