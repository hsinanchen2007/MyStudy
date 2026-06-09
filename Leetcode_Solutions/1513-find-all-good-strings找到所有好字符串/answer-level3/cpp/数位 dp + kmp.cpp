### 思路
如果见过数位 dp，很容易想到应该用这种方法。参考[数位dp](https://oi-wiki.org/dp/number/)。
> 数位 DP 问题往往都是这样的题型，给定一个闭区间[l, r]，让你求这个区间中满足**某种条件**的数的总数。
> 首先我们将问题转化成更加简单的形式。设`f[i]`表示在区间`[1,i]`中满足条件的数的数量，那么所求的答案就是`f[r] - f[l-1]`。

对于这道题目也是一样的。题目要求`[s1, s2]`内不含`evil`子串的字符串，计算方式即为`f[s2]-f[s1-1]`。先求`s1-1`，这个比较简单，当`s1`全为`'a'`时，无法减1，此时`f[s1-1] = 0`，无需调用f。

### 如何求`f[s]`
#### 定义状态
数位 dp 里面，dp 数组永远为`dp[i][state][eq]`(state可以是多维的）。其中，`i`表示只考虑`[0, i)`位，即为结果字符串的前缀。`state`刻画前缀的状态，,`eq`表示前缀是否与`s[0,i)`相等，`dp[i][state][eq]`就是有多少个长度为`i`的前缀，其状态为`state`且`eq`值符合。

在这道题目里面，`state`表示前缀与`evil`字符串匹配的最长长度。数位 dp 里面最重要的就是`state`如何定义。我们知道，动态规划里面，状态就是为了刻画当前所处的状态，使得之后的转移只与状态有关。所以这里`state`表示`evil`字符串匹配的最大长度就自然而然了。

#### 状态初始化
初始化`dp[0][*][1]`即可，显然长度为0时，匹配长度为0，只有一个长度为0的前缀，则`dp[0][0][1] = 1`。其它位置都为0。

#### 状态的转移
当前匹配`state`长度后，增加一个字符`c`，与`evil`字符串匹配的最大长度怎么计算？根据 kmp 的`next`数组计算即可，在下面的代码中，调用了`getNextState`。

然后考虑 dp 数组的转移，这道题目采用我为人人的方式转移，即看当前状态可以转移到其它哪些状态。另一种方式是看当前状态可以由之前的哪些状态转移，在这道题目上不适合。

先看`dp[i][state][0]`，看它通过增添一个字符可以转移到哪些状态。`eq`为`0`，表示前缀已经小于`s`了，所以接下来取任意字符都会使得长度加1的前缀比`s`对应的前缀小，所以会转移到`dp[i+1][ns][0]`，其中`ns`要按照上面的内容根据`state`和所选择的字符`c`计算。所以
```C++
for (char c = 'a'; c <= 'z'; c++) {
    int ns = getNextState(state, c, evil);
    dp[i+1][ns][0] = (dp[i+1][ns][0] + dp[i][state][0]) % MOD;
}
```

然后看`dp[i][state][1]`可以转移到哪些状态。
增加一个小于当前字符`s[i]`的字符`c`，则尽管前`i`个字符相等，加上第`i+1`个字符后，得到的前缀仍是小于`s`的。所以`dp[i][state][1]`可以转移到`dp[i+1][ns][0]`。
```C++
for (char c = 'a'; c < s[i]; c++) {
    int ns = getNextState(state, c, evil);
    dp[i+1][ns][0] = (dp[i+1][ns][0] + dp[i][state][1]) % MOD;
}
```
或者增加一个等于当前字符`s[i]`的字符，则得到的前缀与`s`的前缀相等，那么会转移到`dp[i+1][ns][1]`。
```C++
int ns = getNextState(state, s[i], evil);
dp[i+1][ns][1] = (dp[i+1][ns][1] + dp[i][state][1]) % MOD;
```
如果增加一个大于当前字符`s[i]`的字符，则得到的前缀比`s`大，已经非法了。不做贡献。

可以看到以上的转移是完备的。最后的结果即是$\sum_{i=0}^{evil.length-1} dp[n][i][0] + dp[n][i][1]$。


```C++
#define mst(x, a) memset(x, a, sizeof(x))

typedef long long ll;
const ll MOD = 1e9+7;

ll dp[510][51][2];

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        build(evil);
        // --s1
        bool flag = false;
        for (int i = n - 1; i >= 0; i--) {
            if (s1[i] > 'a') {
                s1[i]--;
                flag = true;
                break;
            } else {
                s1[i] = 'z';
            }
        }

        if (flag) {
            return (helper(n, s2, evil) - helper(n, s1, evil) + MOD) % MOD;
        } else {
            return helper(n, s2, evil);
        }
    }
    
    int helper(int n, const string& s, const string& evil) {
        // printf("%s\n", s.c_str());
        mst(dp, 0);
        dp[0][0][1] = 1;
        for (int i = 0; i < n; i++) {
            for (int state = 0; state < evil.size(); state++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    int ns = getNextState(state, c, evil);
                    dp[i+1][ns][0] = (dp[i+1][ns][0] + dp[i][state][0]) % MOD;
                }
                for (char c = 'a'; c < s[i]; c++) {
                    int ns = getNextState(state, c, evil);
                    dp[i+1][ns][0] = (dp[i+1][ns][0] + dp[i][state][1]) % MOD;
                }
                int ns = getNextState(state, s[i], evil);
                dp[i+1][ns][1] = (dp[i+1][ns][1] + dp[i][state][1]) % MOD;
            }
        }
    
        int ans = 0;
        for (int i = 0; i < evil.size(); i++) {
            ans = (ans + dp[n][i][0]) % MOD;
            ans = (ans + dp[n][i][1]) % MOD;
        }
        return ans;
    }
        
    int getNextState(int state, char c, const string& evil) {
        int j = state;
        while (~j && evil[j] != c) j = next[j];
        return j + 1;
    }
    
    vector<int> next;
 
    // 求 next 数组
    void build(const string &pattern){
        int n = pattern.length();
        next.resize(n + 1);
        for (int i = 0, j = next[0] = -1; i < n; next[++i] = ++j){
            while(~j && pattern[j] != pattern[i]) j = next[j];
        }
    }
};
```