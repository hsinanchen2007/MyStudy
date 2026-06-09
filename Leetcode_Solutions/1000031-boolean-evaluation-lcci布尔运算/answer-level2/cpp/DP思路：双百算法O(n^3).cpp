![QQ截图20200326121650.png](https://pic.leetcode-cn.com/c431ad1dbd714731816c6c95d140a9dad5a9beeb06d5f1eb8102bd45d87dfabe-QQ%E6%88%AA%E5%9B%BE20200326121650.png)

### 解题思路
题的本质就是运算的排列数中满足解是res的方案数。
如果直接暴力用dfs做，19!数量级，大概1e14次方左右不行。

然后思考了是否可以将父问题划分为子问题：
1-n的答案是否可以由1-mid, mid-n得到，仔细一想是可以的。
设mid的运算为op, get(op, t1, t2)。
1. 如果f[1][mid-1][0], f[mid+1][n][0]都能获得(即方案数不为0)， 则f[1][n][get(op, 0, 0)] = f[1][mid-1][0] * f[mid+1][n][0]; 
2. 如果f[1][mid-1][0], f[mid+1][n][1]都能获得(即方案数不为0)， 则f[1][n][get(op, 0, 1)] = f[1][mid-1][0] * f[mid+1][n][1]; 
3. 如果f[1][mid-1][1], f[mid+1][n][0]都能获得(即方案数不为0)， 则f[1][n][get(op, 1, 0)] = f[1][mid-1][1] * f[mid+1][n][0]; 
4. 如果f[1][mid-1][1], f[mid+1][n][1]都能获得(即方案数不为0)， 则f[1][n][get(op, 1, 1)] = f[1][mid-1][1] * f[mid+1][n][1]; 

还有就是一些边界情况的处理，比如mid=1， mid=n的时候。
整个时间最多为19^3.

### 代码

```cpp
class Solution {
public:
    int countEval(string s, int result) {
        // 1, 2, 3
        // 1->2->3, 3->2->1
        // 1^1, 2^2, 3^3;
        if (s.empty()) return 0; 
        if (s.size() == 1) return s[0] - '0' == result;
        
        int n = s.size(), m = n / 2;
        int f[m][m][2]; 
        memset(f, 0, sizeof f);
        
        for (int len = 1; len <= m; len ++)
            for (int i = 0; i + len - 1 < m; i ++) {
                int j = i + len - 1;
                if (len == 1) {
                    int t = i * 2;
                    f[i][j][get(s[t + 1], s[t] - '0', s[t + 2] - '0')] = 1;
                } else {
                    for (int k = i; k <= j; k ++) { // 一定要保证状态划分的边界线正确
                        int t = k * 2;
                        if (k == i) { 
                            if (f[k + 1][j][0]) f[i][j][get(s[t + 1], s[t] - '0', 0)] += f[k + 1][j][0];
                            if (f[k + 1][j][1]) f[i][j][get(s[t + 1], s[t] - '0', 1)] += f[k + 1][j][1];
                        } else if (k == j) {
                            if (f[i][k - 1][0]) f[i][j][get(s[t + 1], s[t + 2] - '0', 0)] += f[i][k - 1][0];
                            if (f[i][k - 1][1]) f[i][j][get(s[t + 1], s[t + 2] - '0', 1)] += f[i][k - 1][1];
                        } else {
                            if (f[i][k - 1][0] && f[k + 1][j][0]) f[i][j][get(s[t + 1], 0, 0)] += f[i][k - 1][0] * f[k + 1][j][0];
                            if (f[i][k - 1][0] && f[k + 1][j][1]) f[i][j][get(s[t + 1], 0, 1)] += f[i][k - 1][0] * f[k + 1][j][1];  
                            if (f[i][k - 1][1] && f[k + 1][j][0]) f[i][j][get(s[t + 1], 1, 0)] += f[i][k - 1][1] * f[k + 1][j][0];
                            if (f[i][k - 1][1] && f[k + 1][j][1]) f[i][j][get(s[t + 1], 1, 1)] += f[i][k - 1][1] * f[k + 1][j][1];  
                        }
                        // cout << k << ',' << f[i][j][0] << ',' << f[i][j][1] << endl;
                    }
                    // if (i == 2 && j == 3) exit(0);
                }
            }
        return f[0][m - 1][result];
    }
    
    bool get(char op, int t1, int t2) {
        if (op == '^') return t1 ^ t2;
        if (op == '|') return t1 | t2;
        return t1 & t2;
    }
};
```