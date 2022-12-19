## 动态规划解法

#### 动态规划逻辑
设$OPT(i, j)$表示字符串$s[i, n)$和模式串$p[j,m)$是否匹配。$OPT(0, 0)$表示$s$和$p$是否匹配。$m$为模式串$p$长度，$n$为字符串$s$长度。结束条件以及递推关系如下：
$$OPT(i, j)=
\begin{cases}
true& \text{i == n \&\& j == m}\\
false& \text{i != n \&\& j == m}\\
is\_all\_star\_or\_not(p[j, m))& \text{i == n \&\& j != m}\\
OPT(i+1, j+1)& \text{i !=n \&\& j != m \&\& (s[i] == p[j] || p[j] == ?)}\\
OPT(i+1, j)\ ||\ OPT(i, j+1)& \text{i !=n \&\& j != m \&\&  p[j] == *}\\
false& \text{otherwise}
\end{cases}$$


#### 动态规划自顶向下代码
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        return recursive_match(s, p, 0, 0);
    }

    bool recursive_match(string &s, string &p, int i, int j) {
        if (i == s.size() && j == p.size()) return true;
        if (i != s.size() && j == p.size()) return false;
        
        // is_all_star_or_not(p[j, m))
        if (i == s.size() && j != p.size()) {
            while (p[j] == '*') ++j;
            return (j == p.size());
        }

        if (s[i] == p[j] || p[j] == '?') return recursive_match(s, p, i+1, j+1);
        else if (p[j] == '*')
            return (recursive_match(s, p, i+1, j) || recursive_match(s, p, i, j+1));
        else {
            return false;
        }
    }
};
```
自顶向下不使用memoization会超时，只能通过940/1809个测试样例。

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        short int *mem = new short int[(n+1)*(m+1)];
        for (int i = 0; i < (n+1)*(m+1); ++i) {
            mem[i] = -1;
        }
        return recursive_match(s, p, 0, 0, m + 1, mem);
    }

    bool recursive_match(string &s, string &p, int i, int j, int cols, short int *mem) {
        if (mem[i*cols+j] != -1) return mem[i*cols+j];
        if (i == s.size() && j == p.size()) return mem[i*cols+j] = true;
        if (i != s.size() && j == p.size()) return mem[i*cols+j] = false;
        
        // is_all_star_or_not(p[j, m))
        if (i == s.size() && j != p.size()) {
            int temp = j;
            while (p[temp] == '*') ++temp;
            return mem[i*cols+j] = (temp == p.size());
        }

        if (s[i] == p[j] || p[j] == '?') 
            return mem[i*cols+j] = recursive_match(s, p, i+1, j+1, cols, mem);
        else if (p[j] == '*')
            return mem[i*cols+j] = 
            (recursive_match(s, p, i+1, j, cols, mem) || recursive_match(s, p, i, j+1, cols, mem));
        else {
            return mem[i*cols+j] = false;
        }
    }
};
```
使用memoization可以通过（32ms），时间复杂度$O(mn)$，空间复杂度$O(mn)$，$m$为模式串$p$长度，$n$为字符串$s$长度。另注意本题memset有坑，对mem初始化只能循环赋值一遍。

#### 动态规划自底向上代码
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        bool dp[m + 1];
        dp[m] = true;
        for (int j = m - 1; j >= 0; j--) {
            dp[j] = p[j] == '*' ? dp[j + 1] : false;
        }
        
        for (int i = n - 1; i >= 0; --i) {
            bool oldright = dp[m];
            for (int j = m - 1; j >= 0; --j) {
                if (s[i] == p[j] || p[j] == '?') {
                    int temp = dp[j];
                    dp[j] = oldright;
                    oldright = temp;
                }
                else if (p[j] == '*') {
                    int temp = dp[j];
                    dp[j] = dp[j] || dp[j+1];
                    oldright = temp;
                }
                else oldright = dp[j], dp[j] = false;
            }
            dp[m] = false;
        }
        return dp[0];
    }
};
```
自底向上可以通过（32ms），时间复杂度$O(mn)$，空间复杂度$O(min(m,n))$，$m$为模式串$p$长度，$n$为字符串$s$长度。上面这个代码假设$m<=n$，使用了长度为$m$的$dp$数组；当$n>m$的时候，也可以用类似方法使用长度为$n$的$dp$数组，代码略。

## 贪心算法解法
本题在遇到'\*'时存在贪心选择，题解中0ms到16ms使用的都是这种贪心算法。本文尝试解释贪心算法的逻辑并且给出一个贪心选择正确性的简单证明。

#### 贪心算法逻辑
$$OPT(i, j)=
\begin{cases}
true& \text{i == n \&\& j == m}\\
OPT(i\_start, j\_start), \ increment\ i\_start& \text{i != n \&\& j == m}\\
is\_all\_star\_or\_not(p[j, m))& \text{i == n \&\& j != m}\\
OPT(i+1, j+1)& \text{i !=n \&\& j != m \&\& (s[i] == p[j] || p[j] == ?)}\\
markdown\ then\ OPT(i, j+1)& \text{i !=n \&\& j != m \&\&  p[j] == *}\\
false& \text{i !=n \&\& j != m \&\& i == -1}\\
OPT(i\_start, j\_start), \ increment\ i\_start& \text{otherwise}
\end{cases}$$

从动态规划的递推式中可以看出，每遇到一个'\*'的就会产生两个子问题分支，如果$p$有5个'\*'，就会产生2^5=32个子问题分支，而贪心选择可以在遇到'\*'的时候只产生一个子问题分支。但需要维护两个全局变量$i\_start$和$j\_start$，初始时都为负数（-1）。每当遇到'\*'时，记录$j\_start$为'\*'的下一个位置，$i\_start$为当前$i$的下一个位置，因此$i\_start$指向回溯时$i$应该所在的位置，$j\_start$指向回溯时$j$应该所在的位置。每次发生不匹配或者$j$到了模式串$p$的末尾但$i$还没有到字符串$s$末尾的时候，就会发生回溯。**这种处理方式暗含了'\*'会从匹配0个字符开始。** 这是为什么第二种情况需要回溯而第三种情况不需要回溯。

这时有两个问题：
1. 回溯时如何确定有没有匹配过'\*'？
2. 已经匹配到一个'\*'的情况下再次匹配到一个'\*'，为何可以直接记录后面的'\*'？

对于第1个问题，判断$i\_start$和$j\_start$是否为负数（-1）即可解决。
对于第2个问题，需要证明这种贪心选择的正确性

#### 贪心选择的正确性证明
问题：已经匹配到一个'\*'的情况下再次匹配到一个'\*'，为何可以直接记录后面的'\*'？为什么不存在需要回溯到第一个'\*'的情况？
证明：首尾是'\*'中间夹着若干字符的模式串形如："$*abc*de$"。只要$i$匹配到第二个'\*'，则表示"$abc$"已经在$s$中被匹配过，且第一个'\*'已经是尽可能少的匹配字符。
反证法：如果$p$中第一个'\*'需要回溯，则一定需要找到$s$中更后面的"abc"，然后$i$和$p$中第二个'\*'的下一个字符开始匹配，记这时$i$的位置为$i\_trick$，$j$的位置为$j\_trick$。而同样的效果可以通过不回溯$p$中第一个'\*', 让第一个'\*'只匹配$s$的第一个"abc"，$p$的第二个'\*'匹配多几个字符直到$s$后面的"$abc$"与$p$的"abc"匹配，从而$i==i\_trick$，$j==j\_trick$而得到。因此第一个'\*'不需要回溯，证明结束。

例子：$s$="$abcxyzabcdeg$", $p$="$*abc*de$"。如下两个场景效果相同：
1. 回溯第一个'\*'，$p[0]$匹配到了$s[5]$，$i==9$与$j==5$匹配
2. 不回溯第一个'\*'，$p[0]$一个都不匹配，$p[4]$匹配到了$s[8]$，$i==9$与$j==5$匹配

#### 贪心算法自顶向下递归版代码
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int i_start = -1, j_start = -1;
        return recursive_match(s, p, 0, 0, i_start, j_start);
    }

    bool recursive_match(string &s, string &p, int i, int j, int &i_start, int &j_start) {
        if (i == s.size() && j == p.size()) return  true;
        if (i == -1) return false;
        // is_all_star_or_not(p[j, m))
        if (i == s.size() && j != p.size()) {
            while (p[j] == '*') ++j;
            return (j == p.size());
        }
        if (i != s.size() && j != p.size()) {
            if (s[i] == p[j] || p[j] == '?') 
                return recursive_match(s, p, i+1, j+1, i_start, j_start);
            else if (p[j] == '*') {
                i_start = i + 1;
                j_start = ++j;
                return recursive_match(s, p, i, j, i_start, j_start); 
            }
        }
        int origin_i_start = i_start++;
        return recursive_match(s, p, origin_i_start, j_start, i_start, j_start);
    }
};
```
最坏时间复杂度$O(mn)$，空间复杂度$O(1)$，$m$为模式串$p$长度，$n$为字符串$s$长度。

#### 贪心算法自顶向下非递归版代码
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int i_start = -1, j_start = -1, i = 0, j = 0, n = s.size(), m = p.size();
        while (i < n) {
            if (j != m && (s[i] == p[j] || p[j] == '?')) ++i, ++j;
            else if (j != m && p[j] == '*') i_start = i + 1, j_start = ++j;
            else if (j_start >= 0) i = i_start++, j = j_start;
            else return false;
        }
        while (j < p.size() && p[j] == '*') ++j;
        return j == p.size();
    }
};
```
最坏时间复杂度$O(mn)$，空间复杂度$O(1)$，$m$为模式串$p$长度，$n$为字符串$s$长度。


*本文若有遗漏不足请多指教。*
