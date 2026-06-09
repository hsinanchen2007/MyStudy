数位dp一般解决的问题是：给定区间Si 和Sj,求Si Sj之间共有多少个数(或字符串))，通常会对这个数加上约束条件。
result = dp[j][state] - dp[i][state]。state是根据问题场景而设置的状态。

在这道题中，i 即为当前数位字符串长度，state为匹配evil的长度。

这里讲一下为什么要用kmp。

首先，如果不用kmp，则进行状态转移时，判断匹配失败直接回退到0
```
            int nxt = match;
            ret = (ret + dfs(x+1,evilStr.charAt(nxt) == c?nxt+1:0, flag && (c == lim))) % mod;
```
考虑这种情况，evil串为"abab"，当前匹配到的字符为"aba_b_",如果匹配失败，下一层将从"_a_bab"重新开始匹配，但是前面
的公共前缀"ab"已经匹配到了，如果把这部分匹配到的丢弃掉重新开始匹配。那么结合递归的终止条件，最终将漏掉一些符合evil子串的字符串，得到的结果会变大。

所以，正确的匹配方式是：
如果当前子串的nxt位置不匹配当前递归层的字符c，就根据kmp的next数组回退。
如果匹配到，nxt++，进入下一层递归。
```
            int nxt = match;
            while(nxt > 0 && evilStr.charAt(nxt) != c) nxt = next[nxt];
            if(nxt >=0 && c == evilStr.charAt(nxt)) nxt++;
            ret = (ret + dfs(x+1,nxt, flag && (c == lim))) % mod;
```


Java 代码如下所示：

java```
class Solution {

    String limitStr = "";
    String evilStr = "";
    int mod = (int)1e9+7;
    int[][] dp;
    int[] next;
    int m, len;
    public int findGoodStrings(int n, String s1, String s2, String evil) {
        m = evil.length();
        len = n;
        evilStr = evil;
        dp = new int[550][55];
        next = getNext(evil);
        limitStr = s1;
        int ret = dfs(0,0,true);
        limitStr = s2;
        ret = (dfs(0,0,true) - ret + mod) % mod;
        if(!s1.contains(evilStr)) ret++;
        return ret;
    }

    int dfs(int x, int match, boolean flag) {
        if(match >= m) return 0;
        if(x >= len) return 1;
        if(!flag && dp[x][match] != 0) return dp[x][match];
        char lim = 'z';
        if(flag) lim = limitStr.charAt(x);
        int ret = 0;
        for(char c = 'a' ; c <= lim ; c++) {
            int nxt = match;
            while(nxt > 0 && evilStr.charAt(nxt) != c) nxt = next[nxt];
            if(nxt >=0 && c == evilStr.charAt(nxt)) nxt++;
            ret = (ret + dfs(x+1,nxt, flag && (c == lim))) % mod;
        }
        if(!flag) dp[x][match] = ret;
        return ret;
    }

    int[] getNext(String evilStr) {
        int n = evilStr.length();
        int[] next = new int[n+1];
        next[0] = -1;
        int i = 0, j = -1;
        while(i < n) {
            if(j == -1 || evilStr.charAt(i) == evilStr.charAt(j)) {
                ++i;
                ++j;
                next[i] = j;
            } else
                j = next[j];
        }
        return next;
    }
}
```
