####  方法一：按字符分组 
我们可以将字符串 `s` 转换为 `groups` 数组表示字符串中相同字符连续块的长度。例如，如果 `s=“11000111000000”`，则 `groups=[2，3，3，6]`。 

对于 `'0' * k + '1' * k` 或 `'1' * k + '0' * k` 形式的每个二进制字符串，此字符串的中间部分必须出现在两个组之间。 

让我们尝试计算 `groups[i]` 和 `groups[i+1]` 之间的有效二进制字符串数。如果我们有 `groups[i] = 2, groups[i+1] = 3`，那么它表示 `“00111”` 或 `“11000”`。显然，我们可以在此字符串中生成 `min(groups[i], groups[i+1])` 有效的二进制字符串。

**算法：**
- 让我们创建上面定义的 `groups`。`s` 的第一个元素属于它自己的组。每个元素要么与前一个元素不匹配，从而开始一个大小为 1 的新组；要么匹配，从而使最近一个组的大小增加 1。
- 然后，我们将取 `min(groups[i-1], groups[i])` 的和。 

```Python [ ]
class Solution(object):
    def countBinarySubstrings(self, s):
        groups = [1]
        for i in xrange(1, len(s)):
            if s[i-1] != s[i]:
                groups.append(1)
            else:
                groups[-1] += 1

        ans = 0
        for i in xrange(1, len(groups)):
            ans += min(groups[i-1], groups[i])
        return ans
```

```Python[  ]
class Solution(object):
    def countBinarySubstrings(self, s):
        groups = [len(list(v)) for _, v in itertools.groupby(s)]
        return sum(min(a, b) for a, b in zip(groups, groups[1:]))
```

```Java [ ]
class Solution {
    public int countBinarySubstrings(String s) {
        int[] groups = new int[s.length()];
        int t = 0;
        groups[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i-1) != s.charAt(i)) {
                groups[++t] = 1;
            } else {
                groups[t]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= t; i++) {
            ans += Math.min(groups[i-1], groups[i]);
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。其中 $N$ 是 `s` 的长度。每个循环都是 $O(N)$。 
* 空间复杂度：$O(N)$，`groups` 使用的空间。


####  方法二：线性扫描 
我们可以修改我们的方法 1 来实时计算答案。我们将只记住 `prev = groups[-2]` 和 `cur=groups[-1]` 来代替 `groups`。然后，答案是我们看到的每个不同的 `(prev, cur)` 的 `min(prev, cur)` 之和。 

```Python [ ]
class Solution(object):
    def countBinarySubstrings(self, s):
        ans, prev, cur = 0, 0, 1
        for i in xrange(1, len(s)):
            if s[i-1] != s[i]:
                ans += min(prev, cur)
                prev, cur = cur, 1
            else:
                cur += 1

        return ans + min(prev, cur)
```

```Java [ ]
class Solution {
    public int countBinarySubstrings(String s) {
        int ans = 0, prev = 0, cur = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i-1) != s.charAt(i)) {
                ans += Math.min(prev, cur);
                prev = cur;
                cur = 1;
            } else {
                cur++;
            }
        }
        return ans + Math.min(prev, cur);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。其中 $N$ 是 `s` 的长度。每个循环都是 $O(N)$。 
* 空间复杂度：$O(1)$。