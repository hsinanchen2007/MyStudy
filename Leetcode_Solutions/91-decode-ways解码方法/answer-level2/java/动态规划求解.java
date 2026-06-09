萌新第一次写题解，写得不好希望大家多包涵。

本题使用**动态规划**求解，我最近在系统地刷动态规划的题。这题在提交了几次出错后我突然发现这题的解题思路和[爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)那题不是完全一样嘛！

如果我们先把题设范围设置得宽泛一点：字母表中对应的数字范围为[00, 99]，两端均为闭区间。那么任意两个数字组合均可对应字母表中一个字母。这样就可以写出动态方程：
`dp[i] = dp[i-1] + dp[i-2]`

即长度为 i 的字符串解码方是为长度为 i-1 的字符串和长度为 i-2 的字符串的解码方法之和。对照爬楼梯的解题过程就不难理解。长度为 i 的字符串的所有解码方法是以下两项数量之和：
将字符串对应的字符数组设为 chars = s.toCharArray();
- 长度为 i-1 的字符串的所有解码方法后再加一个 chars[i]
- 长度为 i-2 的字符串的所有解码方法后再加上 chars[i-1] + chars[i]


最后再对一些特殊方法进行补充就可以了。

我画的各种情况的图如下，大家可以看图帮助理解

![解码方法.jpg](https://pic.leetcode-cn.com/3c63463b7e7cb04a5c3276aea651049a99a105da85cbcdd02c3135805a74ea28-%E8%A7%A3%E7%A0%81%E6%96%B9%E6%B3%95.jpg)


```
public class Solution {
    public int numDecodings(String s) {
        int strLen = s.length();
        char[] chars = s.toCharArray();
        int[] dp = new int[strLen];
        if (chars[0] == '0') // 出现不合理的值就直接返回，dp矩阵中不允许出现0
            return 0;
        else
            dp[0] = 1;

        for (int i = 1; i < strLen; i++)
            if (chars[i] == '0') // 当前位为0的情况
                if (chars[i - 1] == '0' || chars[i - 1] > '2')
                    return 0;
                else if (i > 1)
                    dp[i] = dp[i - 2];
                else
                    dp[i] = 1;
            else if ((chars[i] < '7' && (chars[i - 1] == '1' || chars[i - 1] == '2')) || (chars[i] > '6' && chars[i - 1] == '1'))
                dp[i] = i > 1 ? dp[i - 1] + dp[i - 2] : dp[i - 1] + 1;
            else
                dp[i] = dp[i - 1];
        return dp[strLen - 1];
    }
}
```

**复杂度分析**

- 时间复杂度：*O*(*n*)，遍历长度为 *n* 的字符串 。

- 空间复杂度：*O*(*n*)，dp 数组用了 *n* 的空间。