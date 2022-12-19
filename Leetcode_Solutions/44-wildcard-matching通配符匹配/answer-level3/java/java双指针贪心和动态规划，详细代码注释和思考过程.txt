## 贪心+动态规划

这道题和NO.10正则表达式匹配看起来很像，正则匹配的题解可以参考[徒手挖地球十六周目](https://blog.csdn.net/qq_42758551/article/details/104286793)中的记录。

这两道题目的区别在于'*'的处理不同，正则中的星号是星号前的字符可以出现0次、1次或多次，而本题中通配符中的星号则是可以匹配任意字符。但是正则中的'.'和通配符中的'?'作用是一样的。

所以说这道题的难点一样是对于'*'的处理。

**思路一：双指针贪心算法** 重点就是我们如何充分的利用'*'。

我们用i和j分别标记s和p的第一个字符下标，即都初始化为0。用istart和jstart分别标记s和p中'*'匹配过的位置，即初始化为-1。

和普通字符串匹配的思路差不多，`已经匹配成功的部分就不再考虑了`，所以要用i和j标记当前正在比较的字符；但是`最近匹配过的'*'`可能会被`重复使用去匹配更多的字符`，所以我们要用istart和jstart分别标记`s和p中最近匹配过'*'的位置`。可以参考[徒手挖地球十六周目](https://blog.csdn.net/qq_42758551/article/details/104286793)NO.正则表达式匹配的思路一是如何从普通情况延伸到特殊字符的。

s和p匹配过程中可能会遇到的情况：

1. 如果`i和j标记的字符正好相等或者j字符是'?'`匹配成功，则"移除"i和j元素，即`自增i、j`。
2. 否则如果`j字符是'*'`依然可以匹配成功，`则用istart和jstart分别标记i元素和j元素`之后`自增j`。
3. 再否则如果`istart>-1`说明之前匹配过'\*'，因为'\*'可以匹配多个字符，所以这里要再次利用这个最近匹配过的'\*'匹配更多的字符，`移动i标记istart的下一个字符，再让istart重新标记i元素`同时`移动j标记jstart的下一个字符`。
4. 上述三种情况都不满足，则匹配失败，`返回false`。

最后当s中的字符都判断完毕，则认为s为空，此时需要p为空或者p中只剩下星号的时候，才能成功匹配。

```java
public boolean isMatch(String s, String p) {
    if (p==null||p.isEmpty())return s==null||s.isEmpty();
    int i=0,j=0,istart=-1,jstart=-1,slen=s.length(),plen=p.length();
    //判断s的所有字符是否匹配
    while (i<slen){
        //三种匹配成功情况以及匹配失败返回false
        if (j<plen&&(s.charAt(i)==p.charAt(j)||p.charAt(j)=='?')){
            i++;
            j++;
        }else if (j<plen&&p.charAt(j)=='*'){
            istart=i;
            jstart=j++;
        }else if (istart>-1){
            i=++istart;
            j=jstart+1;
        }else {
            return false;
        }
    }
    //s中的字符都判断完毕，则认为s为空，此时需要p为空或者p中只剩下星号的时候，才能成功匹配。
    //如果p中剩余的都是*，则可以移除剩余的*
    while (j<plen&&p.charAt(j)=='*')j++;
    return j==plen;
}
```

时间复杂度：O(mn)  	m、n分别是s和p的长度。

**思路二：动态规划法** 分析步骤依然按照[徒手挖地球十六周目](https://blog.csdn.net/qq_42758551/article/details/104286793)NO.正则表达式匹配思路二的步骤来。

dp数组的含义：dp[i\][j\]意思是s的前i个元素能否被p的前j个元素成功匹配。

知道了dp数组的含义之后，我们就知道了初始化细节：

1. `boolean类型`的dp数组，大小是`[s.length+1][p.length+1]`，因为存在s前0个字符和p前0个字符的情况。
2. `dp[0][0]一定是true`，因为s空串和p空串是可以匹配成功的；`dp[1][0]~dp[s.length][0]一定都是false`，因为s不为空串而p为空串是不能匹配成功的。
3. `dp[0][1]~dp[0][p.length]`当s为空串的时候，而p不是空串的时候，当且仅当p的j字符以及前面都为'*'才为true。
4. `dp[s.length][p.length]`就得到了s和p最终的匹配情况。

有了上述理解之后，就可以初始化dp数组了。

然后填写dp数组剩余部分即可，状态转移方程：

1. 当`s[i]==p[j]或者p[j]=='?'`，则`dp[i][j]=dp[i-1][j-1]`。可以理解为当前字符成功匹配后，只需要考虑之前的字符串是否匹配即可；也可以理解为当前字符匹配成功之后，"移除"当前元素(即不需要再考虑当前元素)。
2. 当`p[j]=='*'`，则`dp[i][j]=dp[i-1][j]||dp[i][j-1]`。可以理解为当字符为'\*'的时候会出现两种情况，第一种是'*'需要作为一个字母与s[i]进行匹配；第二种是'\*'需要作为空字符(即不需要'\*'可以直接"移除")，所以dp[i\][j-1]；用逻辑或将两种情况连接，是因为只要有一种情况可以匹配成功则当前匹配成功，有点暴力算法的感觉。
3. 最后当`s[i]!=p[j]&&p[j]!='*'`，`dp[i][j]=false`。这步可以省略，因为dp数组元素的默认值就是false，所以不必要进行显式的赋值为false。

```java
public boolean isMatch(String s, String p) {
    if (p==null||p.isEmpty())return s==null||s.isEmpty();
    int slen = s.length(),plen=p.length();
    boolean[][] dp=new boolean[slen+1][plen+1];
    //初始化dp数组,dp[1][0]~dp[s.length][0]默认值flase不需要显式初始化为false
    dp[0][0]=true;
    //dp[0][1]~dp[0][p.length]只有p的j字符以及前面所有字符都为'*'才为true
    for (int j=1;j<=plen;j++)dp[0][j]=p.charAt(j-1)=='*'&&dp[0][j-1];
    //填写dp数组剩余部分
    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= plen; j++) {
            char si = s.charAt(i - 1),pj=p.charAt(j-1);
            if (si==pj||pj=='?'){
                dp[i][j]=dp[i-1][j-1];
            }else if (pj=='*'){
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }
        }
    }
    return dp[slen][plen];
}
```

时间复杂度：O(mn)	m、n分别是s和p的长度。

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/)