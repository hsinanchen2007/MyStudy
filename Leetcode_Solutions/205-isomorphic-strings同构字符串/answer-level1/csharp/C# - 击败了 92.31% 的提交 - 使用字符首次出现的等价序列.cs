[@fzls](/u/fzls/) 在此题中提供的思路很有参考价值，还可以将该方法迁移到 [Leetcode 290](https://leetcode-cn.com/problems/word-pattern).

例子：
paper 与 title
paper中各字母首次出现下标的序列为: [0, 1, 0, 3, 4]，
title中各字母首次出现下标的序列为: [0, 1, 0, 3, 4]
因为下标数组一致，所以两字符串同构。

以下是C#实现，代码清晰、简洁~

```csharp
public class Solution {
    public bool IsIsomorphic(string s, string t)
    {
        List<int> indexS = new List<int>();
        List<int> indexT = new List<int>();

        for (int i = 0; i < s.Length; i++)
            indexS.Add(s.IndexOf(s[i]));

        for (int j = 0; j < t.Length; j++)
            indexT.Add(t.IndexOf(t[j]));

        return indexS.SequenceEqual(indexT);
    }
}
```

**运行结果:**

执行用时: `92 ms`, 在所有 csharp 提交中击败了`92.31%`的用户

本人 `dotNET匠人`完成的 C#刷遍LeetCode面试题系列文章传送门:

<https://www.cnblogs.com/enjoy233/p/csharp_leetcode_series_1.html>


