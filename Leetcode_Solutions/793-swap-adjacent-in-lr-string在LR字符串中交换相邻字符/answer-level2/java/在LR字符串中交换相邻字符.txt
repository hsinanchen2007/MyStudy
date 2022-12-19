#### 方法一： 性质分析【通过】

**思路**

将 `'L'`，`'R'` 分别理解为一个队伍中面向左和面向右的人，`'X'` 理解为队伍中的空挡。可以问自己一个问题，一次移动操作之后有什么是保持不变的？ 这是状态转换问题中一个很常见的思路。

**算法**

这道题的 *转换不变性* 在于字符串中的 `'L'` 和 `'R'` 是不会互相穿插的，也就是队伍中的人在移动过程中是不能穿过人的。这意味着开始和结束的字符串如果只看 `'L'` 和 `'R'` 的话是一模一样的。

除此之外，第 `n` 个 `'L'` 不可能移动到初始位置的右边，第 `n` 个 `'R'` 不可能移动到初始位置的左边，我们把这个特性称为 “*可到达性*“。设 $(i_1, i_2, \cdots )$，$(i^{'}_1, i^{'}_2, \cdots )$ 为每个字符 `'L'` 在原始字符串和目标字符串的位置，$(j_1, j_2, \cdots )$，$(j^{'}_1, j^{'}_2, \cdots )$ 为每个字符 `'R'` 在原始字符串和目标字符串的位置，如果 $i_k \geq i^{'}_k$ 和 $j_k \leq j^{'}_k$ 都能满足，这个字符串就是 ”*可到达的*“。

根据 *转换不变性* 和 *可到达性*，在算法中可以分别检查这两个性质是否满足。如果都满足，则返回 `True`，否则返回 `False`。

```java [solution1-Java]
class Solution {
    public boolean canTransform(String start, String end) {
        if (!start.replace("X", "").equals(end.replace("X", "")))
            return false;

        int t = 0;
        for (int i = 0; i < start.length(); ++i)
            if (start.charAt(i) == 'L') {
                while (end.charAt(t) != 'L') t++;
                if (i < t++) return false;
            }

        t = 0;
        for (int i = 0; i < start.length(); ++i)
            if (start.charAt(i) == 'R') {
                while (end.charAt(t) != 'R') t++;
                if (i > t++) return false;
            }

        return true;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def canTransform(self, start, end):
        if start.replace('X','') != end.replace('X', ''):
            return False

        for (symbol, op) in (('L', operator.ge), ('R', operator.le)):
            B = (i for i, c in enumerate(end) if c == symbol)
            for i, c in enumerate(start):
                if c == symbol and not op(i, next(B)):
                    return False

        return True
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 为 `start` 和 `end` 的长度。

* 空间复杂度：$O(N)$。

#### 方法二： 双指针 【通过】

**思路和算法**

由方法一可知，如果可以到达目标字符串，那么一定满足 *转换不变性* 和 *可到达性*。

可以用双指针来解决这个问题，对于 `i`， `j` 两个指针，分别让他们指向 `start` 和 `end`，且保证 `start[i] != 'X'`，`end[j] != 'X'`。接下来开始移动指针，如果 `start[i] != end[j]`，则不满足 *转换不变性*，如果 `start[i] == 'L'` 且 `i < j`，则不满足 *可到达性*。

```java [solution2-Java]
class Solution {
    public boolean canTransform(String start, String end) {
        int N = start.length();
        char[] S = start.toCharArray(), T = end.toCharArray();
        int i = -1, j = -1;
        while (++i < N && ++j < N) {
            while (i < N && S[i] == 'X') i++;
            while (j < N && T[j] == 'X') j++;
            /* At this point, i == N or S[i] != 'X',
               and j == N or T[j] != 'X'.  i and j
               are the indices representing the next
               occurrences of non-X characters in S and T.
            */

            // If only one of i < N and j < N, then it isn't solid-
            // there's more people in one of the strings.
            if ((i < N) ^ (j < N)) return false;

            if (i < N && j < N) {
                // If the person isn't the same, it isn't solid.
                // Or, if the person moved backwards, it isn't accessible.
                if (S[i] != T[j] || (S[i] == 'L' && i < j) ||
                        (S[i] == 'R' && i > j) )
                    return false;
            }
        }
        return true;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def canTransform(self, start, end):
        # For (i, x) and (j, y) in enumerate(start), enumerate(end)
        # where x != 'X' and y != 'X',
        # and where if one exhausts early, it's elements are (None, None),...
        for (i, x), (j, y) in itertools.izip_longest(
                ((i, x) for i, x in enumerate(start) if x != 'X'),
                ((j, y) for j, y in enumerate(end) if y != 'X'),
                fillvalue = (None, None)):

            # If not solid or accessible, return False
            if x != y or (x == 'L' and i < j) or (x == 'R' and i > j):
                return False

        return True
```

**复杂度分析**

* 空间复杂度：$O(N)$，其中 $N$ 为 `start` 和 `end` 的长度。

* 空间复杂度：$O(1)$。