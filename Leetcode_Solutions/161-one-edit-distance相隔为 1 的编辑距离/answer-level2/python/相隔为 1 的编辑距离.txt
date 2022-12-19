#### 遍历一遍的算法：

**想法**

首先，我们确认两个字符串的长度差得不会太远。如果长度差大于等于 2 个字符，那么 `s` 和 `t` 肯定不是编辑距离为 1 的字符串。

![image.png](https://pic.leetcode-cn.com/b71a7ebf1b4fa95af0417160bb5b7e547d6979f1d0f5e84e458ae7bd532f9ebc-image.png)

接下来，我们假设 `s` 总是比 `t` 短或者长度相等。否则，调用函数 `isOneEditDistance(t, s)` 来将两个字符串交换。

现在，遍历字符串一遍并找到第一个不同的字符。

如果前 `len(s)` 个字符没有差别，那么只有两种可能：

- 两个字符串是相同的

- 两个字符串的编辑距离相隔为 1


![image.png](https://pic.leetcode-cn.com/55101ef4b0653403e4172f0f30a90e058e7aa878fd7c50f6846b392d078514ad-image.png)

如果存在不同的字符 `s[i] != t[i]`：

- 如果两个字符串的长度相等，_所有_ 接下来的字符都应该相等，否则编辑距离不为 1 。这种情况下，我们需要比较 `s` 和 `t` 从第 `i + 1` 个字符开始的子串是否相等。

- 如果 `t` 比 `s` 多一个字符， `t[i]` 应该是 `t` 串多出来的那个字符。这种情况下，我们需要比较 `s` 串从第 `i` 个字符开始的子串和 `t` 串从 `i + 1` 开始的子串是否相等。

![image.png](https://pic.leetcode-cn.com/3d006d3cccb907303ce52f5466e3dc0a4ea50a7162c5c1b85a11931126cc8961-image.png)

**算法实现**

```Java []
class Solution {
  public boolean isOneEditDistance(String s, String t) {
    int ns = s.length();
    int nt = t.length();

    // Ensure that s is shorter than t.
    if (ns > nt)
      return isOneEditDistance(t, s);

    // The strings are NOT one edit away distance  
    // if the length diff is more than 1.
    if (nt - ns > 1)
      return false;

    for (int i = 0; i < ns; i++)
      if (s.charAt(i) != t.charAt(i))
        // if strings have the same length
        if (ns == nt)
          return s.substring(i + 1).equals(t.substring(i + 1));
        // if strings have different lengths
        else
          return s.substring(i).equals(t.substring(i + 1));

    // If there is no diffs on ns distance
    // the strings are one edit away only if
    // t has one more character. 
    return (ns + 1 == nt);
  }
}
```

```Python []
class Solution:
    def isOneEditDistance(self, s: 'str', t: 'str') -> 'bool':
        ns, nt = len(s), len(t)

        # Ensure that s is shorter than t.
        if ns > nt:
            return self.isOneEditDistance(t, s)

        # The strings are NOT one edit away distance  
        # if the length diff is more than 1.
        if nt - ns > 1:
            return False

        for i in range(ns):
            if s[i] != t[i]:
                # if strings have the same length
                if ns == nt:
                    return s[i + 1:] == t[i + 1:]
                # if strings have different lengths
                else:
                    return s[i:] == t[i + 1:]
        
        # If there is no diffs on ns distance
        # the strings are one edit away only if
        # t has one more character. 
        return ns + 1 == nt
```

**时间复杂度**

* 时间复杂度：$O(N)$ 。最坏情况下，当字符串的长度足够接近，即 $abs(N(s) - N(t)) <= 1$，其中 `N` 是求一个字符串的长度的函数。 最好情况下， $abs(N(s)-N(t))>1$ 时，时间复杂度为 $O(1)$ 。
 
* 空间复杂度：$O(1)$ 。

**类似题目：72. 编辑距离** [给两个单词 word1 和 word2 ，找到将 word1 转变成 word2 的最少操作次数](https://leetcode-cn.com/problems/edit-distance/)
