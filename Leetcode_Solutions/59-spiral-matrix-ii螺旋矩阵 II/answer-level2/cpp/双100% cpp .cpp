### 解题思路

l, r, u, d 分别代表left, right, up, down边界。每一次循环都是一个正方形的最外四个边界值，循环一次后

l + 1
r - 1
u + 1
d + 1

直到
l > r 
u > d 
说明内部已经没有正方形了
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int l = 0, r = n - 1, u = 0, d = n - 1, index = 1;
        while (true) {
            for (int i = l; i <= r; i ++) matrix[u][i] = index ++; 
            if (++u > d) break;
            for (int i = u; i <= d; i ++) matrix[i][r] = index ++;
            if (--r < l) break;
            for (int i = r; i >= l; i --) matrix[d][i] = index ++;
            if (--d < u) break;
            for (int i = d; i >= u; i --) matrix[i][l] = index ++;
            if (++ l > r) break;
        }  
        return matrix;
    }
};
```