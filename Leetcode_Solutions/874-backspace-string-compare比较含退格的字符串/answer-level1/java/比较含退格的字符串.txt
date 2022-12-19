#### 方法一：重构字符串【通过】

**思想**

使用 `build(S)` 和 `build(T)` 构造去除了退格符和被删除字符后的字符串，然后比较它们是否相等。

**算法**

在 `build(S)` 中，使用栈存储每次输入的字符。

```java [solution1-Java]
class Solution {
    public boolean backspaceCompare(String S, String T) {
        return build(S).equals(build(T));
    }

    public String build(String S) {
        Stack<Character> ans = new Stack();
        for (char c: S.toCharArray()) {
            if (c != '#')
                ans.push(c);
            else if (!ans.empty())
                ans.pop();
        }
        return String.valueOf(ans);
    }
}
```

```python [solution1-Python]
class Solution(object):
    def backspaceCompare(self, S, T):
        def build(S):
            ans = []
            for c in S:
                if c != '#':
                    ans.append(c)
                elif ans:
                    ans.pop()
            return "".join(ans)
        return build(S) == build(T)
```

**复杂度分析**

* 时间复杂度：$O(M + N)$，其中 $M, N$ 是字符串 `S` 和 `T` 的长度。

* 空间复杂度：$O(M + N)$。

#### 方法二：双指针【通过】

**思路**

一个字符是否属于最终字符串的一部分，取决于它后面有多少个退格符。

如果反向遍历字符串，就可以先知道有多少个退格符，然后知道退格符左边有多少个字符会被删除，对应的也就知道哪些字符会保留在最终的字符串中。

**算法**

反向遍历字符串，如果遍历到一个退格符，那么再往左第一个非退格字符将会被删除，剩余未被删除的字符就是最终的字符串。

```java [solution2-Java]
class Solution {
    public boolean backspaceCompare(String S, String T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) { // While there may be chars in build(S) or build (T)
            while (i >= 0) { // Find position of next possible char in build(S)
                if (S.charAt(i) == '#') {skipS++; i--;}
                else if (skipS > 0) {skipS--; i--;}
                else break;
            }
            while (j >= 0) { // Find position of next possible char in build(T)
                if (T.charAt(j) == '#') {skipT++; j--;}
                else if (skipT > 0) {skipT--; j--;}
                else break;
            }
            // If two actual characters are different
            if (i >= 0 && j >= 0 && S.charAt(i) != T.charAt(j))
                return false;
            // If expecting to compare char vs nothing
            if ((i >= 0) != (j >= 0))
                return false;
            i--; j--;
        }
        return true;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def backspaceCompare(self, S, T):
        def F(S):
            skip = 0
            for x in reversed(S):
                if x == '#':
                    skip += 1
                elif skip:
                    skip -= 1
                else:
                    yield x

        return all(x == y for x, y in itertools.izip_longest(F(S), F(T)))
```

**复杂度分析**

* 时间复杂度：$O(M + N)$，其中 $M, N$ 是字符串 `S` 和 `T` 的长度。

* 空间复杂度：$O(1)$。