#### 方法一：暴力解法 【通过】

生成所有字符串的所有子序列共 $2^n$ 个，将其存储在 hashmap 中，并记录每个子序列出现的次数。然后找出出现次数为 $1$ 的最长子序列。如果不存在这样的子序列，返回 $-1$。 

```java [solution1-Java]
public class Solution {
    public int findLUSlength(String[] strs) {
        HashMap < String, Integer > map = new HashMap < > ();
        for (String s: strs) {
            for (int i = 0; i < (1 << s.length()); i++) {
                String t = "";
                for (int j = 0; j < s.length(); j++) {
                    if (((i >> j) & 1) != 0)
                        t += s.charAt(j);
                }
                if (map.containsKey(t))
                    map.put(t, map.get(t) + 1);
                else
                    map.put(t, 1);
            }
        }
        int res = -1;
        for (String s: map.keySet()) {
            if (map.get(s) == 1)
                res = Math.max(res, s.length());
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n*2^x)$，其中 $x$ 是所有字符串的平均长度，$n$ 是字符串的数量。

* 空间复杂度：$O(n*2^x)$，大小为 $n*2^x$ 的 HashMap。


#### 方法二：检查每个字符串 【通过】

**算法**

如果存在这样的特殊序列，那么它一定是某个给定的字符串。

检查每个字符串是否是其他字符串的子序列。如果不是，则它是一个特殊序列。最后返回长度最大的特殊序列。如果不存在特殊序列，返回 -1。

通过下面的例子，演示此方法的过程：

<![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide1.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide2.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide3.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide4.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide5.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide6.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide7.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide8.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide9.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide10.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide11.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide12.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide13.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide14.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide15.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide16.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide17.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide18.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide19.JPG),![1500](https://pic.leetcode-cn.com/Figures/595_Longest_UncommonSlide20.JPG)>

```java [solution2-Java]
public class Solution {
    public boolean isSubsequence(String x, String y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x.charAt(j) == y.charAt(i))
                j++;
        return j == x.length();
    }
    public int findLUSlength(String[] strs) {
        int res = -1;
        for (int i = 0, j; i < strs.length; i++) {
            for (j = 0; j < strs.length; j++) {
                if (j == i)
                    continue;
                if (isSubsequence(strs[i], strs[j]))
                    break;
            }
            if (j == strs.length)
                res = Math.max(res, strs[i].length());
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(x*n^2)$，其中 $n$ 是字符串的数量，$x$ 是每个字符串的平均长度。

* 空间复杂度：$O(1)$，恒定的额外空间。


#### 方法三：排序+检查每个字符串

**算法**

*方法二* 中需要判断每个字符串是否为特殊序列。如果最开始可以先将所有字符串排序，则可以节省一部分计算。

本方法中，首先按照长度降序排序所有字符串。然后，依次使用序列中的每个字符串与其他字符串比较，如果不存在字符串是当前字符串的子序列，则返回当前字符串的长度。否则返回 -1。

```java [solution3-Java]
public class Solution {
    public boolean isSubsequence(String x, String y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x.charAt(j) == y.charAt(i))
                j++;
        return j == x.length();
    }
    public int findLUSlength(String[] strs) {
        Arrays.sort(strs, new Comparator < String > () {
            public int compare(String s1, String s2) {
                return s2.length() - s1.length();
            }
        });
        for (int i = 0, j; i < strs.length; i++) {
            boolean flag = true;
            for (j = 0; j < strs.length; j++) {
                if (i == j)
                    continue;
                if (isSubsequence(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return strs[i].length();
        }
        return -1;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(x*n^2)$，其中 $n$ 是字符串的数量，$x$ 是每个字符串的平均长度。

* 空间复杂度：$O(1)$，恒定的额外空间。