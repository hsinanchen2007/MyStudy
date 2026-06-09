首先找到跳变处,随后统计跳变两边的长度,将长度较小的添加到结果中就是此段子串的结果.同时需要将指针指向跳变处,进行下一次统计直至结束.
效率一般,重在直接..
```
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        i, count, n = 0, 0, len(s)
        while i < n - 1:
            j = i + 1
            # 找到第一次跳变
            while j < n and s[j] == s[i]:
                j += 1
            k = j + 1
            le = j - i
            # 找到第二次跳变
            while k < n and s[k] == s[j] and k - j <= le:
                k += 1
            # 统计这一段的结果
            if j < n:
                count += min(j - i, k - j)
            i = j
        return count   
```
