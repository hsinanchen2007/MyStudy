#### 方法 1：暴力

**算法**

这个方法的思想是：我们创建一个列表保存所有 $s$ 删除一个或多个字符后可以产生的可能字符串。为了实现这个想法，我们使用递归函数 `generate(s, str, i, l)` ，它表示到原串第 $i$ 个字符为止添加或者移除第 $i$ 个字符所能生成的字符串。因此，把第 $i$ 个字符添加到字符串末尾，调用 `generate(s, str + s.charAt(i), i + 1, l)` 。如果忽略第 $i$ 个字符，调用 `generate(s, str, i + 1, l)` 。

所以在最后，列表 $l$ 包含所有 $s$ 形成的字符串。然后我们查找字典看是否有单词在 $l$ 中。进一步的，如果有出现在 $l$ 中的字符串，我们记录最长且字典序最小的一个。

```Java []
public class Solution {
    public String findLongestWord(String s, List < String > d) {
        HashSet < String > set = new HashSet < > (d);
        List < String > l = new ArrayList < > ();
        generate(s, "", 0, l);
        String max_str = "";
        for (String str: l) {
            if (set.contains(str))
                if (str.length() > max_str.length() || (str.length() == max_str.length() && str.compareTo(max_str) < 0))
                    max_str = str;
        }
        return max_str;
    }
    public void generate(String s, String str, int i, List < String > l) {
        if (i == s.length())
            l.add(str);
        else {
            generate(s, str + s.charAt(i), i + 1, l);
            generate(s, str, i + 1, l);
        }
    }
}
```

**复杂度分析**

* 时间复杂度： $O(2^n)$ 。 `generate` 调用自己 $2^n$ 次。这里的 $n$ 表示字符串 $s$ 的长度。

* 空间复杂度： $O(2^n)$ 。列表 $l$ 包含 $2^n$ 个字符串。

#### 方法 2：迭代暴力

**算法**

与上面递归 `generate` 函数找到所有 $s$ 能生成的字符串类似的，我们可以用迭代实现这个过程。这里我们使用一种叫二进制数生成的概念。

我们可以把给定的字符串 $s$ 用一个对应长度的二进制串表示。规则是如果第 $i$ 个位置是 1 ，那么就把对应位置的字符添加进最终字符串，否则移除。

我们知道如果字符串长度为 $n$ ，那么总共有 $2^n$ 个这样的二进制串。因此，我们从 $0$ 到 $2^n-1$ 考虑每一个二进制串，并根据上述规则生成所有的字符串。

下图展示了 $s$ 串为 "sea" 的一个例子：

![image.png](https://pic.leetcode-cn.com/a5213eb08da0aa3a2488e90da94da241febd4615cb336965aa8318314a6c6a13-image.png)
{:align="center"}


这个方法能解决长度为 32 以内的字符串，因为我们需要枚举一个整数，并对它做位移操作。

```Java []
public class Solution {
    public String findLongestWord(String s, List < String > d) {
        HashSet < String > set = new HashSet < > (d);
        List < String > l = new ArrayList < > ();
        for (int i = 0; i < (1 << s.length()); i++) {
            String t = "";
            for (int j = 0; j < s.length(); j++) {
                if (((i >> j) & 1) != 0)
                    t += s.charAt(j);
            }
            l.add(t);
        }
        String max_str = "";
        for (String str: l) {
            if (set.contains(str))
                if (str.length() > max_str.length() || (str.length() == max_str.length() && str.compareTo(max_str) < 0))
                    max_str = str;
        }
        return max_str;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(2^n)$ 。生成了 $2^n$ 个字符串。

* 空间复杂度： $O(2^n)$ 。列表 $l$ 包含 $2^n$ 个字符串。

#### 方法 3：排序并检查子序列

**算法**

问题中匹配的条件是我们需要考虑字典中能匹配的最长字符串，相同长度的情况下考虑字典序最小的。为了简化搜索过程，我们把字典中的字符串按照这一规则排序，这样越靠前的字符串是我们越优先考虑的。

现在，与其删除 $s$ 中的字符，我们直接从头开始检查字典中的单词是否是 $s$ 串的子序列。这是因为，如果 $x$ 是 $s$ 的子序列，我们可以直接通过删除 $s$ 中的某些字符得到 $x$ 。

如果 $x$ 是 $s$ 的子序列，那么 $x$ 中的每个字符在 $s$ 中出现过。下图展示了一个关于如何检查一个子序列的例子：

<![image.png](https://pic.leetcode-cn.com/8eacf29fbae164820b5905b61343b3111add9eb07d54489b23afc770437ab2c9-image.png),![image.png](https://pic.leetcode-cn.com/220ebc4d00b223df2b8413930f6895efde959a7ccd9952438ee91d6361eef32f-image.png),![image.png](https://pic.leetcode-cn.com/2c3dee177f3b342ec88789d55ce9f9c67ec50d7387becbe7c24b09a8698ff53a-image.png),![image.png](https://pic.leetcode-cn.com/3af726432e58d0370b5db508c6dce594729ba7b57671fa01288e24300ca4e072-image.png),![image.png](https://pic.leetcode-cn.com/eab8c6f46921512440bffa446eb22eb863da08712377228b3098b79f56cfc8e1-image.png),![image.png](https://pic.leetcode-cn.com/92984af646d23949f02b15b6d3c2c68e963f45aeeab1f80d651fe08febd185cc-image.png),![image.png](https://pic.leetcode-cn.com/bf3300a0e7222c8ecd122c857267c4886aacbcca9b01629685acddd958613009-image.png)>

只要我们找到了这样的一个 $x$，我们可以立即停止搜索过程，因为我们已经找到了最优答案。

```Java []
public class Solution {
    public boolean isSubsequence(String x, String y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x.charAt(j) == y.charAt(i))
                j++;
        return j == x.length();
    }
    public String findLongestWord(String s, List < String > d) {
        Collections.sort(d, new Comparator < String > () {
            public int compare(String s1, String s2) {
                return s2.length() != s1.length() ? s2.length() - s1.length() : s1.compareTo(s2);
            }
        });
        for (String str: d) {
            if (isSubsequence(str, s))
                return str;
        }
        return "";
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n \cdot x \log n + n \cdot x)$ 。这里， $n$ 表示列表 $d$ 中字符串的数目，$x$ 表示字符串的平均长度。排序需要花费 $O(n\log n)$ 的时间， `isSubsequence` 函数需要花费 $O(x)$ 的时间去检查一个字符串是否是另一个字符串的子序列。

* 空间复杂度： $O(\log n)$ 。排序平均需要 $O(\log n)$ 的空间。

#### 方法 4：不需要排序

**算法**

由于将字典排序需要消耗额外的时间和空间，我们可以跳过排序的过程，直接在未排序的字典 $d$ 中查找字符串 $x$ 满足 $x$ 是 $s$ 的子序列。如果 $x$ 被找到了，我们将它与其他匹配的字符串做比较，直到找到长度最长、字典序最小的单词为止。

```Java []
public class Solution {
    public boolean isSubsequence(String x, String y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x.charAt(j) == y.charAt(i))
                j++;
        return j == x.length();
    }
    public String findLongestWord(String s, List < String > d) {
        String max_str = "";
        for (String str: d) {
            if (isSubsequence(str, s)) {
                if (str.length() > max_str.length() || (str.length() == max_str.length() && str.compareTo(max_str) < 0))
                    max_str = str;
            }
        }
        return max_str;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n \cdot x)$ 。这里 $n$ 是列表 $d$ 中字符串的数目， $x$ 是字符串平均长度。

* 空间复杂度： $O(x)$ 。使用了变量 $max\_str$ 。