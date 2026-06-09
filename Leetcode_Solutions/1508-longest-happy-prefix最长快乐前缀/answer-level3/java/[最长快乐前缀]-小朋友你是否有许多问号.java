线性、最值。动规应该不难想到，问题的关键就在 **dp[i]与 dp[i-1]之间状态如何转移**。
（这道题搞明白了，那 KMP 算法也就轻车熟路了）
---
动规的思考方式千篇一律：**已知上一状态的结果下，如何得到当前状态的结果。**
以样例 2 为例：
已知对于前一状态 `dp[i-1]` (也就是字符串`'ababa'`)来说，其结果为`'aba'` (见下图)

![image.png](https://pic.leetcode-cn.com/dd726855f01f0251278eaa02790653b13e297ed4eab178ba02deb5fe87cf20b0-image.png)

`dp[i-1]='aba'`**既是(` "ababa" `的)前缀又是后缀**，做为后缀，后面跟着的当前字符`'b'`与作为前缀时后面跟着的 `s[3]='b'` 相同，那么我们就得到了当前状态的答案： `dp[i]='abab'` (见下图)

![image.png](https://pic.leetcode-cn.com/2236dbbdb3ea840a4bcb504d0dd2209c2a26f4502ff4f552e7f3a4be0cec5203-image.png)
![image.png](https://pic.leetcode-cn.com/984c75ede735211fc77e73d2929ac4d6d685ef704590b98c5b851563805f6efa-image.png)

也就是说我们去比较 s[i] 与 **i-1状态下的最长快乐前缀**的后一个字符，如果相同，当前最长快乐前缀就等于**i-1状态下的最长快乐前缀再往后延伸一位**。

那如果不同呢？比如把最后一个字符 b 改为 a(见下图)
![image.png](https://pic.leetcode-cn.com/d72261437862acabf910c3f8dbb11617c800ee94840a5977bac5be7110a838f8-image.png)
这时候**需要退而求其次**，寻找字符串`'ababa'`的**第二长快乐前缀**，**然后看该前缀的后一个字符是否等于当前字符`'a'`。**

如何寻找字符串'ababa'的第二长快乐前缀呢？**其实就是最长快乐前缀的最长快乐前缀。`'ababa'`的第二长快乐前缀就是`'aba'`的最长快乐前缀：`'a'`。**

于是比较后一个字符是否等于当前字符'a'，发现不等（如下图）
![image.png](https://pic.leetcode-cn.com/e2aa0769ed9f24f6fe46da1e8d1537030fa1ea41c6fe28679d11f397a132c387-image.png)

如此重复，直至相等或者最长快乐前缀为0。

附上双百 Java ，想清楚处理索引时的+1-1就行。
```java
class Solution {
    public String longestPrefix(String s) {
        int[] dp=new int[s.length()+1];
        dp[0]=-1;
        for(int i=1;i<=s.length();i++){
            //当前字符
            char c=s.charAt(i-1);
            //待比较的最长快乐前缀的后一位
            int k=dp[i-1];
            while(k>=0&&c!=s.charAt(k)){
                k=dp[k];
            }
            dp[i]=k+1;
        }
        return s.substring(0,dp[s.length()]);
    }
}
```



