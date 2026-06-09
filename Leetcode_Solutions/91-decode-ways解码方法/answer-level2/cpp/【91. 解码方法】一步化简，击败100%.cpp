## 思路一
关键理清分类情况，从第二个字符开始遍历，从总体上可以分为两大类：
- if 当前字符为 0 （只有前一个字符为'1' 或 '2'才可以解码，且只可能有一种解码）
  - if 前一个字符为 '1' 或 '2' （需要判断是否是第二个字符）
    - if 是第二个字符，dp[i] = 1;
    - else dp[i] = dp[i-2];
  - else return 0;（非法）
- else 当前字符不为 0 （判断和前一个字符组成的数是否可以被当作整体解码）
  - if 组合数在 (10, 26] (在上个if中已排除20)
    - if 是第二个字符，则 dp[i] = 2;
    - else dp[i] = dp[i-2] + dp[i-1];（类似斐波那契数列）
  - else dp[i] = dp[i-1] （只能单个数解码）

最后返回dp[size-1]。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if (size == 0) {
            return 0;
        }
        if (s[0] == '0') {
            return 0;
        }
        int dp[size+1];
        dp[0] = 1;            
        for (int i = 1; i < size; ++i) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    if (i == 1) {
                        dp[i] = 1;
                    } else {
                        dp[i] = dp[i-2];
                    }
                } else {
                    return 0;
                }
            } else {
                int tmp = stoi(s.substr(i-1,2));
                if (tmp > 10 && tmp <= 26) {
                    if (i == 1) {
                        dp[i] = 2;
                    } else {
                        dp[i] = dp[i-2] + dp[i-1];
                    }
                } else {
                    dp[i] = dp[i-1];
                }
            }            
        }
        return dp[size-1];
    }
};
```

### 另一种写法（击败100%）
利用短路原理，可以将返回0的两个合并。
```c++
class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if (size == 0 || s[0] == '0') {
            return 0;
        }
        int dp[size+1];
        dp[0] = 1;            
        for (int i = 1; i < size; ++i) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    if (i == 1) {
                        dp[i] = 1;
                    } else {
                        dp[i] = dp[i-2];
                    }
                } else {
                    return 0;
                }
            } else {
                int tmp = stoi(s.substr(i-1,2));
                if (tmp > 10 && tmp <= 26) {
                    if (i == 1) {
                        dp[i] = 2;
                    } else {
                        dp[i] = dp[i-2] + dp[i-1];
                    }
                } else {
                    dp[i] = dp[i-1];
                }
            }            
        }
        return dp[size-1];
    }
};
```

## 思路二：类比爬楼梯
到达当前楼梯的方法数为前面两个楼梯数之和，但需要增加一些限制条件：
- 判断由s[i-1]的楼梯到达的方法数 a
  - if s[i] != '0'，可以，方法数为 s[i-1]
  - else 不可以为 0
- 判断由s[i-2]的楼梯到达的方法数 b（'10' <= s[i-1]s[i] <= '26'）
  - if s[i-1] == '1' || (s[i-1] == '2' && s[i-1] <= '6')，可以，方法数为s[i-2]
  - else 不可以为 0

最后到达当前楼梯方法数为 a + b，然后更新前两个楼梯值。
### 代码
```c++
class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if (size == 0 || s[0] == '0') {
            return 0;
        }
        int n0 = 1;
        int n1 = 1;
        for (int i = 1; i < size; ++i) {
            int a = s[i] == '0' ? 0 : n1;
            int b = s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6') ? n0 : 0;
            n0 = n1;
            n1 = a + b;            
        }
        return n1;
    }
};
```
