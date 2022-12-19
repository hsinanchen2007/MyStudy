## 思路一：找规律（最优解）
通过写出前几个数的最大乘积，可以看出以下规律，对大于3的数，尽可能将其拆分为3并且不出现1，所以可得出下面三种情况：
- 模3为0，最大乘积为所有3的乘积
- 模3为1，为了不出现1，最后一个3和1组成4，然后和之前所有3求得最大乘积
- 模3为2，最大乘积为所有3乘积再乘以2

### 代码
时间复杂度：O(1)
空间复杂度：O(1)
```cpp
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;        
        int res = 1, num3 = n / 3;        
        if (n % 3 == 0) {
            res = (int)pow(3, num3);            
        } else if (n % 3 == 1){            
            --num3;
            res = (int)pow(3, num3) *  4;
        } else {
            res = (int)pow(3, num3) * 2;
        }
        return res;
    }
};
```

### 另一种写法
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;        
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        return res * n;
    }
};
```

## 思路二：DP
暴力求解，对每个数，依次求出最大值，dp[i]表示数字i可以得到的最大乘积，数组大小为n + 1, 初始化为1（正整数乘积不为0），并且2的最大乘积为1， 所以从3到n依次求每个数最大乘积。对于每个数，将其进行任意拆分，j * (i - j)表示拆分为2个数，dp[i - j]表示数字i - j任意拆分的最大乘积，再乘以j可得数字i拆分为多个数最大乘积。然后取两者最大值来更新dp[i]。

### 代码
时间复杂度：O(n^2)
空间复杂度：O(n)
```c++
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
```

