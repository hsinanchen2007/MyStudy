## 方法一：暴力法(exceed time)
Algorithm:
将每一种子串都判断是否符合括号匹配模式。  
```c++
bool isVaild(string s) {
    stack<char> a;
    for (auto v : s) {
        if (v == '(') {
            a.push(v);
        } else if (!a.empty() && a.top() == '(') {
            a.pop();
        } else return false;
    }
    return a.empty();
}

int longestValidParentheses(string s) {
    int maxLen = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 2; j + i <= s.length(); j += 2) {
            if (isVaild(s.substr(i, j))) {
                if (j > maxLen) {
                    maxLen = j;
                }
            }
        }
    }
    return maxLen;
}
```
复杂度分析：  
- 时间复杂度：O(n^2)。从长度为 n 的字符串产生所有可能的子字符串需要的时间复杂度为 O(n^2)。验证一个长度为 n 的子字符串需要的时间为 O(n) 。
- 空间复杂度： O(n) 。子字符串的长度最多会需要一个深度为 n 的栈。
## 方法二：动态规划
Algorithm：
动态规划的题目一般分成三步：  
1、确定状态，也就是你的答案表是存什么答案的。  
2、确定状态转移方程，也就是怎么将你的答案表填满，换句话说，就是一些表达式。  
3、确定边界情况，什么情况下有可能越界，要单独判断考虑（有可能无边界情况）。  
有兴趣的话可以看一下动态规划经典例题 [Leetcode-10-正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/solution/kan-liao-jiu-ming-bai-de-dong-tai-gui-hua-by-stree/).  

### 状态
```dp[i]``` 表示以下标 ```i``` 为字符结尾的最长有效字符串的长度
### 状态转移方程
以 ```(``` 结尾的子字符串不考虑，因为不可能构成合法括号
#### if ```s[i] == ')'```
1. ```s[i - 1] == '('```，也就是字符串形如 ```“……()”```，我们可以推出：  
```dp[i] = dp[i − 2] + 2```。   
因为结束部分的 "()" 是一个有效子字符串，并且将之前有效子字符串的长度增加了 2.  
2. ```s[i - 1] == ')'```，也就是字符串形如 ```“.......))”```，我们可以推出：  
if ```s[i - dp[i - 1] - 1] == '('```，```dp[i] = dp[i − 1] + dp[i − dp[i − 1] − 2] + 2```。  
因为如果倒数第二个 ```)```是一个有效子字符串的一部分（记为```subs```），我们此时需要判断 ```subs``` 前面一个符号是不是 ```(``` ，如果恰好是```(```，我们就用 ```subs``` 的长度(```dp[i - 1```)加上 2 去更新 ```dp[i]```。除此以外，我们也会把子字符串 ```subs``` 前面的有效字符串的长度加上，也就是 ```dp[i − dp[i − 1] − 2]```.  
### 边界情况
- ```i - 2``` 有可能小于零越界了，这种情况下就是只有 ```()``` ，前面记为 0 就好了.  
- ```i - dp[i - 1] - 1``` 和 ```i - dp[i - 1] - 2``` 都可能越界，越界了当成 0 来计算就可以了.  
```c++
int longestValidParentheses(string s) {
    int maxLen = 0;
    vector<int> dp(s.length());
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] - 1 >= 0 and s[i - dp[i - 1] - 1] == '(') {
                dp[i] = (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
            }
        }
        maxLen = fmax(dp[i], maxLen);
    }
    return maxLen;
}
```
复杂度分析：  
- 时间复杂度：O(n)。遍历整个字符串一次，就可以将 ```dp``` 数组求出来.  
- 空间复杂度： O(n)。需要一个大小为 ```n``` 的 ```dp``` 数组.  
