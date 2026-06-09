**（1）题目**

给定一个字符串 `s`，找到 `s` 中最长的回文子串。你可以假设 `s` 的最大长度为 1000。


|示例|输入|输出|解释|
|-|-|-|-|
|示例1|"babad"|"bab"|"aba" 也是一个有效答案|
|示例2|"cbbd"|"bb"|因为无重复字符的最长子串是 "b"，所以其长度为1|



**（2）解答**

1）首先第一反应就是暴力解法：他的做法就是i从0开始、j从i+1开始两层循环截取sub字符串，然后使用StringBuilder的reverse函数去判断equals前后是否一样：

* equals为true则是回文，不断存取maxSubString
* false表示不是回文，进行下一轮for循环

两层循环的$n^2$再结合reverse函数的n，最后复杂度变为$n^3$

```java
   public boolean isPalindromic(String s) {
        String reverseSub = new StringBuffer(s).reverse().toString();
        return reverseSub.equals(s);
    }

    // 暴力解法
    public String longestPalindrome(String s) {
        String ans = "";
        int max = 0;
        int len = s.length();
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j <= len; j++) {
                String test = s.substring(i, j);
                if (isPalindromic(test) && test.length() > max) {
                    ans = s.substring(i, j);
                    max = Math.max(max, ans.length());
                }
            }
        return ans;
    }
```



2）为了改进暴力法，我们首先观察如何避免在验证回文时进行不必要的重复计算 => 动态规划的方法，回忆下斐波拉契数列（后一个数是前两个数之和），对每一次计算出的结果使用集合存储，可以避免重复计算带来的开销

==考虑 【ababa】这个示例：假如我们已知【bab】是回文子串，因为它的左首字母和右尾字母是相同的（'a' == 'a'），很明显【ababa】一定是回文==

我们给出 `P(i,j)` 的定义如下：$$ P(i,j)= \begin{cases} true, & 如果子串S_i ...S_j 是回文子串  \\ false, & 其他情况 \end{cases}$$

因此：$P(i,j)=(P(i+1,j−1) \ and \ S_i == S_j)$

首先要梳理==base case==：

* $P(i,i)=true$
* $P(i,i+1) = (S_i == S_{i+1})$

这产生了一个直观的动态规划解法，我们首先初始化一字母和二字母的回文，然后找到所有三字母回文，并依此类推…



**（3）代码**

```java
public static String longestPalindrome(String s) {
    int size = s.length();
    if (size < 2) {
        return s;
    }
    boolean[][] dp = new boolean[size][size];
    int maxLen = 1, start = 0;

    for (int i = 0; i < size; ++i) {
        dp[i][i] = true; //单个字符本身
        for (int j = 0; j < i; ++j) {
            if (s.charAt(i) == s.charAt(j) && (i - j == 1 || dp[j + 1][i - 1])) {
                dp[j][i] = true;
                if (i - j + 1 > maxLen) {
                    maxLen = i - j + 1;
                    start = j;
                }
            } else {
                dp[j][i] = false;
            }
        }
    }
//        System.out.println(Arrays.deepToString(dp));
    return s.substring(start, start + maxLen);
}
```

1）使用【abbac】打印出维护的dp二位数组

```python
[
	[true, false, false, true, false], 
	[false, true, true, false, false], 
	[false, false, true, false, false], 
	[false, false, false, true, false], 
	[false, false, false, false, true]
]
```