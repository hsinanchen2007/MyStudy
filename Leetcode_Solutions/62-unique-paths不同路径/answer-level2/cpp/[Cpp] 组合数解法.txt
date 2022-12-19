### 解题思路
见注释

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 总共需要走m + n - 2步
        int all = m + n - 2;
        // 其中需要向下走m - 1步
        // 所以不同路径数为：C^{m - 1}_{m + n - 2}
        int tmp;
        if (n > m) tmp = m - 1;
        else tmp = n - 1;
        long long res_1 = 1;
        long long res_2 = 1;
        while (tmp) {
            res_1 *= tmp;
            res_2 *= all;
            all--;
            tmp--;
        }
        return res_2 / res_1;
    }
};
```