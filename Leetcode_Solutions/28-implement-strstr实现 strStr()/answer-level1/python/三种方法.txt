## 思路：

思路 1：调用库函数

思路 2：暴力法，时间复杂度：$O((m-n)n)$，$m$ 是主字符串，$n$ 是模式字符串。

思路 3：KMP 算法

## 代码：

思路 2：

```Python [solution1]
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle : return 0
        n1 = len(haystack)
        n2 = len(needle)
        if n1 < n2:return -1
        def helper(i):
            haystack_p = i
            needle_q = 0
            while needle_q < n2:
                if haystack[haystack_p] !=  needle[needle_q]:
                    return False
                else:
                    haystack_p += 1
                    needle_q += 1
            return True
        for i in range(n1 - n2 + 1):
            if helper(i):
                return i
        return -1
```


```Python [solution1]
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack) - len(needle)+1):
            if haystack[i:i+len(needle)] == needle:
                return i
        return -1
```


```Java [solution1]
class Solution {
    public int strStr(String S, String T) {
        int n1 = S.length();
        int n2 = T.length();
        if (n1 < n2) return -1;
        else if ( n2 == 0) return 0;
        for (int i = 0; i < n1 - n2 + 1; i++ ){
            if (S.substring(i, i+n2).equals(T)) return i;
        }
        return -1;
    }
}
```



思路 3

```Python [solution2]
class Solution:
    def strStr(self, t, p):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not p : return 0
        _next = [0] * len(p)

        def getNext(p, _next):
            _next[0] = -1
            i = 0
            j = -1
            while i < len(p) - 1:
                if j == -1 or p[i] == p[j]:
                    i += 1
                    j += 1
                    _next[i] = j
                else:
                    j = _next[j]
        getNext(p, _next)
        i = 0
        j = 0
        while i < len(t) and j < len(p):
            if j == -1 or t[i] == p[j]:
                i += 1
                j += 1
            else:
                j = _next[j]
        if j == len(p):
            return i - j
        return -1
```
```Java [solution2]
class Solution {
     public int strStr(String S, String T) {
        if (T == null || T.length() == 0) return 0;
        int[] next = new int[T.length()];
        getNext(T, next);
        int i = 0;
        int j = 0;
        while (i < S.length() && j < T.length()) {
            if (j == -1 || S.charAt(i) == T.charAt(j)) {
                i++;
                j++;
            } else j = next[j];
        }
        if (j == T.length()) return i - j;
        return -1;


    }

    private void getNext(String t, int[] next) {
        next[0] = -1;
        int i = 0;
        int j = -1;
        while (i < t.length() - 1) {
            if (j == -1 || t.charAt(i) == t.charAt(j)) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }
}
```
