题解1：暴力。
遍历所有字符串长度因子长度的子串，判断其是否能够重复多次得到字符串，如果全都不能输出False。

复杂度：设字符串长度为n，每次比较是O(n)的时间，比较的次数是n的因数的个数，设为f(n)，复杂度为O(n*f(n))。

```
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for i in range(len(s)//2):
            if len(s) % (i+1) == 0 and s[:i+1] * (len(s)//(i+1)) == s:
                return True
        return False

```

题解2：KMP。
主要是利用KMP中的next数组，next[i]表示s[:i+1]前缀后缀匹配的前缀最后一个字符索引，因此令next[-1] == j, len(s)-1 - j == k，k即是前缀后缀匹配的后缀的第一个字符索引，那么s[0: j+1] == s[k : len(s)]。
如果k > j+1，那么字符串不可能有重复子串；
如果k <= j+1，且k能整除len(s)，那么令len(s) == m*k，s[0: j+1] == s[k: k+j+1]，其中j+1 == len(s)-k == (m-1)*k，所以s[0: (m-1)*k] == s[k: m*k]，拆分开得到s[0: k] == s[k: 2*k] == ... == s[(m-1)*k: m*k]，那么s可以由s[0: k]重复m次得到；
如果如果k <= j+1，但k不能能整除len(s)，那么一定没有重复子串（反证法：如果有重复子串，那么由next数组求出的k一定就是重复子串的长度，一定可以整除len(s)）。next数组可以在线性的时间内求出。

复杂度：O(n)。

```
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        # 动态规划计算next表
        l = len(s)
        next = [-1 for _ in range(l)]
        for j in range(1, l):
            i = next[j-1]
            while i>=0 and s[i+1] != s[j]:
                i = next[i]
            if s[i+1] == s[j]:
                next[j] = i+1
        # 根据next表判断
        return next[-1] >= 0 and l % (l - 1 - next[-1]) == 0
```
