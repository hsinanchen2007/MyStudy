# 前言
为了区分数字本身和组成数字的位，我们用`num`表示数字本身，用`digit`表示组成数字的位，一个`num`由一个或多个`digit`组成。
数位dp解决的是从`o-n`数字中找到**满足某种条件的数字的个数**，那么数位dp可以轻易的解决本问题的简化版本——“求从1-n中`digit`包含1的`num`个数”，代码如下：
```c++
class Solution {
public:
    vector<int> digit;
    vector<vector<int>> memo;
    int countDigitOne(int n) {
        return solve(n);
    }
    
    int solve(int n) {
        int len = 0;
        digit.assign(64, 0);
        while (n) {
            digit[++len] = n%10;
            n /= 10;
        }
        memo.assign(len, vector<int>(2, -1));
        return dfs(len, 0, 1, 1);
    }
    int dfs(int pos, int sm, bool lead, bool limit) {
        if (pos == 0) return sm;
        if (!lead && !limit && memo[pos][sm] != -1) return memo[pos][sm];
        int up = limit ? digit[pos]:9;
        int ret = 0;
        for (int i=0; i<=up; ++i) {
            ret += dfs(pos-1, sm || (i == 1), lead && (i==0), limit && (i == up));
        }
        if (!limit && !lead) memo[pos][sm] = ret;
        return ret;
    }
};
```
如上是标准的数位dp模板的应用，关键点在于`sm`也就是dp中第二维状态的表示为**枚举到pos位时前面是否出现过1**。可以看到到最后一层也就是`pos == 0`时，sm的取值只有1或0，也就是标识当前的`num`是不是包含1。那么如何统计数字中1的个数呢，我们可以将递归到最后一层的返回值来表示当前`num`包含1的个数，当当然dp的状态也要变为**枚举到pos位时前面1出现的个数**。
```c++
class Solution {
public:
    vector<int> digit;
    vector<vector<int>> memo;
    int countDigitOne(int n) {
        return solve(n);
    }
    
    int solve(int n) {
        int len = 0;
        digit.assign(64, 0);
        while (n) {
            digit[++len] = n%10;
            n /= 10;
        }
        memo.assign(len, vector<int>(len+1, -1));
        return dfs(len, 0, 1, 1);
    }
    int dfs(int pos, int sm, bool lead, bool limit) {
        if (pos == 0) return sm;
        if (!lead && !limit && memo[pos][sm] != -1) return memo[pos][sm];
        int up = limit ? digit[pos]:9;
        int ret = 0;
        for (int i=0; i<=up; ++i) {
            ret += dfs(pos-1, sm + (i == 1), lead && (i==0), limit && (i == up));
        }
        if (!limit && !lead) memo[pos][sm] = ret;
        return ret;
    }
};
```