### 解题思路
这是格雷码那道题的[题解](https://leetcode-cn.com/problems/gray-code/solution/ling-lei-si-lu-by-github-crow/)，思路一样，状态变量的含义为只需要在前`1<<n`状态变量的基础上加1，也就是最高位的那个为1的bit就可以得到后面`1<<n`个状态变量。以`num=5`为例：
![338. 比特位计数.PNG](https://pic.leetcode-cn.com/3185e6c6612eb3d5b5515e34cd52e4261a6708081468b28b095b473980b32570-338.%20%E6%AF%94%E7%89%B9%E4%BD%8D%E8%AE%A1%E6%95%B0.PNG)

### 代码

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        int k = 1;
        while (k <= num) {
            for (int pos1 = k, pos2 = 0; pos1 <= num && pos2 < k; pos1++, pos2++)
                dp[pos1] = dp[pos2] + 1;
            k = k << 1;
        }
        return dp;
    }
};
```