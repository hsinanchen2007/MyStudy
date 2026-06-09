#### 枚举：

我们首先把这个二维坐标分成两部分，前一部分表示 `x` 坐标，后一部分表示 `y` 坐标。例如当给出的二维坐标为 `(1234)` 时，我们可以把它分成 `1, 234`，`12, 34` 和 `123, 4` 三种情况。随后对于每一部分，我们再考虑是否可以添加小数点以及在哪里添加小数点。例如，对于 `123`，合法的坐标有 `1.23`，`12.3` 和 `123`。

在处理每一部分时，我们需要将出现多余 `0` 的不合法的坐标去除。如果我们不添加小数点，那么这个坐标不能有前导 `0`；如果我们在某个位置添加小数点，那么整数部分不能有前导 `0`，小数部分的末尾也不能有 `0`。

```Java [sol1]
class Solution { //aw
    public List<String> ambiguousCoordinates(String S) {
        List<String> ans = new ArrayList();
        for (int i = 2; i < S.length()-1; ++i)
            for (String left: make(S, 1, i))
                for (String right: make(S, i, S.length()-1))
                    ans.add("(" + left + ", " + right + ")");
        return ans;
    }

    public List<String> make(String S, int i, int j) {
        // Make on S.substring(i, j)
        List<String> ans = new ArrayList();
        for (int d = 1; d <= j-i; ++d) {
            String left = S.substring(i, i+d);
            String right = S.substring(i+d, j);
            if ((!left.startsWith("0") || left.equals("0"))
                    && !right.endsWith("0"))
                ans.add(left + (d < j-i ? "." : "") + right);
        }
        return ans;
    }
}

```

```Python [sol1]
class Solution(object):
    def ambiguousCoordinates(self, S):
        def make(frag):
            N = len(frag)
            for d in xrange(1, N+1):
                left = frag[:d]
                right = frag[d:]
                if ((not left.startswith('0') or left == '0')
                        and (not right.endswith('0'))):
                    yield left + ('.' if d != N else '') + right

        S = S[1:-1]
        return ["({}, {})".format(*cand)
                for i in xrange(1, len(S))
                for cand in itertools.product(make(S[:i]), make(S[i:]))]
```

**复杂度分析**

* 时间复杂度：$O(N^3)$，其中 $N$ 是字符串 `S` 的长度。

* 空间复杂度：$O(N^3)$，用来存储所有合法的情况。