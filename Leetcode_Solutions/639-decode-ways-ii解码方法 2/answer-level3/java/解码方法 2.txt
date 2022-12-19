#### 方法一：记忆性递归

**算法**

对输入的字符序列，考虑每种可能的解码情况。

假设有函数 `ways(s,i)`，返回字符串 $s$ 中前 $i$ 个字符的解码方法数量。调用 `ways(s, s.length()-1)` 得到字符串中所有字符的解码方法数量。

我们从字符串 $s$ 的最后一个字符开始解码，假设此时调用函数 `ways(s,i)`。在 `ways(s,i)` 中计算前 $i$ 个字符的所有解码方法数量。第 $i$ 个字符有以下几种情况。

![解码方式](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways2.png){:width=400}

第 $i$ 个字符是 `*`。首先考虑第 $i$ 个字符单独解码的情况，`*` 表示 `1-9` 中任意一个数字，对应 `A-I` 中任意一个字母。前 $i$ 个字符的解码可以表示为在前 $i-1$ 个字符解码的结尾加上 `A-I` 中任意一个字母。因此总的解码数量为前 $n-1$ 个字符解码数量的 9 倍，即 `9*ways(s,i-1)`。

除此之外，第 $i$ 个字符也可以和第 $i-1$ 个字符一起解码。如果第 $i-1$ 个字符是 `1`，它们可以表示 `11-19` 中任意一个数字，对应 `K-S` 中任意一个字母。前 $i$ 个字符的解码可以表示为在前 $i-2$ 个字符解码的结尾加上 `K-S` 中任意一个字母。因此总的解码数量为前 $n-2$ 个字符解码数量的 9 倍，即 `9*ways(s,i-2)`。需要注意的是使用两个字符 `1*` 一起解码和两个字符分开单独解码的结果不重复。

如果第 $i-1$ 个字符是 `2`，那么 `2*` 可以表示 `21-26` 中任意一个数字，对应 `U-Z` 中任意一个字母。总的解码数量是前 $i-2$ 个字符解码数量的 6 倍，即 `6*ways(s,i-2)`。
 
![解码方式](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways3.PNG){:width=470}

如果第 $i-1$ 个字符是 `*`，那么 `**` 可以表示 `11-19`（9）和 `21-26`（6） 中任意一个数字。因此总的解码数量是前 $i-2$ 个字符解码数量的 15（9+6） 倍，即 `15*ways(s,i-2)`。

如果第 $i$ 个字符是 `1-9` 的数字。首先考虑单个字符解码的情况。此时前 $i$ 个字符的解码数量等于前 $i-1$ 个字符的解码数量。如果第 $i$ 个字符是 `0`，那么它不能单独解码，必须与它的前一个字符一起解码。前一个字符是 `1`，`2` 或 `*` 时才可以解码。具体情况如下。

如果前一个字符是 `1`，那么它们可以是 `10-19` 中任意一个数字。此时解码数量等于前 $i-2$ 个字符的解码数量。

如果前一个字符是 `2`，则有效数字范围为 `20-26`。只有当前字符小于 7 时可以解码。此时解码数量等于前 $i-2$ 个字符的解码数量。

如果前一个字符是 `*`，那么解码数量取决于当前数字。如果当前数字大于 6，那么它们只能是 `17-19` 中任意一个（`27-29` 是无效的解码数字）。此时解码数量等于前 $i-2$ 个字符的解码数量。

如果当前数字小于 `7`，则 `*` 可以是 `1` 或 `2`。对应 `10-16` 或者 `20-26` 中任意一个数字。此时解码数量等于前 $i-2$ 个字符解码数量的 2 倍。

在函数 `ways` 中实现所有的情况，递归调用 `ways` 计算所有字符的解码数量。记录已经计算出来的前 $i$ 个字符的解码数量，减少重复调用，降低计算复杂度。

```java [solution1-Java]
public class Solution {
    int M = 1000000007;
    public int numDecodings(String s) {
        Integer[] memo=new Integer[s.length()];
        return ways(s, s.length() - 1,memo);
    }
    public int ways(String s, int i,Integer[] memo) {
        if (i < 0)
            return 1;
        if(memo[i]!=null)
            return memo[i];
        if (s.charAt(i) == '*') {
            long res = 9 * ways(s, i - 1,memo);
            if (i > 0 && s.charAt(i - 1) == '1')
                res = (res + 9 * ways(s, i - 2,memo)) % M;
            else if (i > 0 && s.charAt(i - 1) == '2')
                res = (res + 6 * ways(s, i - 2,memo)) % M;
            else if (i > 0 && s.charAt(i - 1) == '*')
                res = (res + 15 * ways(s, i - 2,memo)) % M;
            memo[i]=(int)res;
            return memo[i];
        }
        long res = s.charAt(i) != '0' ? ways(s, i - 1,memo) : 0;
        if (i > 0 && s.charAt(i - 1) == '1')
            res = (res + ways(s, i - 2,memo)) % M;
        else if (i > 0 && s.charAt(i - 1) == '2' && s.charAt(i) <= '6')
            res = (res + ways(s, i - 2,memo)) % M;
        else if (i > 0 && s.charAt(i - 1) == '*')
                res = (res + (s.charAt(i)<='6'?2:1) * ways(s, i - 2,memo)) % M;
        memo[i]= (int)res;
        return memo[i];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 $n$ 表示输入字符串和备忘录数组的长度，备忘录数组中每项计算时间复杂度为 $O(1)$。

* 空间复杂度：$O(n)$，递归树的深度为 $n$。


#### 方法二：动态规划

**算法**

从 *方法一* 可以看出，字符串前 $i$ 个字符的解码方法数量只与前 $i$ 个字符有关，与它后面的字符无关。因此该问题也可以使用动态规划解决。

如果知道字符串前 $i-1$ 个字符的解码数量和前 $i-2$ 个字符的解码数量，就可以计算出前 $i$ 个字符的解码数量。从前往后计算数组 $dp$ 中每一项，$dp[i]$ 表示字符串 $s$ 前 $i$ 个字符的编码数量。 

通过一个简单实例的图解说明 $dp$ 的计算过程。

![](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways_IISlide1.PNG)
![](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways_IISlide2.PNG)
![](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways_IISlide3.PNG)
![](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways_IISlide4.PNG)
![](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways_IISlide5.PNG)
![](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways_IISlide6.PNG)
![](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways_IISlide7.PNG)
![](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways_IISlide8.PNG)
![](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways_IISlide9.PNG)
![](https://pic.leetcode-cn.com/Figures/639/639_Decode_Ways_IISlide10.PNG)

```java [solution2-Java]
public class Solution {
    int M = 1000000007;
    public int numDecodings(String s) {
        long[] dp = new long[s.length() + 1];
        dp[0] = 1;
        dp[1] = s.charAt(0) == '*' ? 9 : s.charAt(0) == '0' ? 0 : 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == '*') {
                dp[i + 1] = 9 * dp[i];
                if (s.charAt(i - 1) == '1')
                    dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % M;
                else if (s.charAt(i - 1) == '2')
                    dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % M;
                else if (s.charAt(i - 1) == '*')
                    dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % M;
            } else {
                dp[i + 1] = s.charAt(i) != '0' ? dp[i] : 0;
                if (s.charAt(i - 1) == '1')
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
                else if (s.charAt(i - 1) == '2' && s.charAt(i) <= '6')
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
                else if (s.charAt(i - 1) == '*')
                    dp[i + 1] = (dp[i + 1] + (s.charAt(i) <= '6' ? 2 : 1) * dp[i - 1]) % M;
            }
        }
        return (int) dp[s.length()];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 $n$ 是输入字符串的长度，数组 $dp$ 长度为 $n+1$，计算数组每一项的时间复杂度为 $O(1)$。

* 空间复杂度：$O(n)$，数组 $dp$ 的长度为 $n+1$。


#### 方法三：恒定空间的动态规划

**算法**

只要知道 $dp[i-2]$ 和 $dp[i-1]$ 就可以计算出 $dp[i]$。因此不需要保存数组 $dp$ 的所有值，只需要记录数组 $dp$ 的最后两个值就可以计算出下一项。其他过程与 *方法二* 相同。

```java [solution3-Java]
public class Solution {
    int M = 1000000007;
    public int numDecodings(String s) {
        long first = 1, second = s.charAt(0) == '*' ? 9 : s.charAt(0) == '0' ? 0 : 1;
        for (int i = 1; i < s.length(); i++) {
            long temp = second;
            if (s.charAt(i) == '*') {
                second = 9 * second;
                if (s.charAt(i - 1) == '1')
                    second = (second + 9 * first) % M;
                else if (s.charAt(i - 1) == '2')
                    second = (second + 6 * first) % M;
                else if (s.charAt(i - 1) == '*')
                    second = (second + 15 * first) % M;
            } else {
                second = s.charAt(i) != '0' ? second : 0;
                if (s.charAt(i - 1) == '1')
                    second = (second + first) % M;
                else if (s.charAt(i - 1) == '2' && s.charAt(i) <= '6')
                    second = (second + first) % M;
                else if (s.charAt(i - 1) == '*')
                    second = (second + (s.charAt(i) <= '6' ? 2 : 1) * first) % M;
            }
            first = temp;
        }
        return (int) second;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 $n$ 是输入字符串的长度，需要计算到第 $n$ 次才能得到所有字符的解码数量。

* 空间复杂度：$O(1)$，使用恒定空间。