### 解题思路
$O(N^2)$暴力求解

### 代码

```c++ []
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // 暴力求解
        int R = matrix.size(), C =matrix[0].size(), i, j;
        // a存储每行的最小元素
        memset(a, 127, sizeof(a));
        // b存储每列的最大元素
        memset(b, 0, sizeof(b));

        for(i=0; i<R; ++i)
            for(j=0; j<C; ++j){
                a[i] = min(a[i], matrix[i][j]);
                b[j] = max(b[j], matrix[i][j]);
            }

        res.clear();

        for(i=0; i<R; ++i)
            for(j=0; j<C; ++j){
                if(a[i] == matrix[i][j] && b[j] == matrix[i][j])
                    res.push_back(matrix[i][j]);
            }

        return res;


    }
private:
    int a[60], b[60];
    vector<int> res;
};
```