一开始看到这题还以为要动规或者要搞点高级字符串算法了，结果一遍就过了，直接两边收缩判断如果相等就+2，然后最后如果有剩余的字符串就+1，所以就是加n次2和1次1，周赛四题里估计这题比赛时候的通过率就是最高的，简直是困难之耻。

![image.png](https://pic.leetcode-cn.com/11218f580b3bce68d75a8265e069383fd4173ef9f30f316568d5406fe5c63ec5-image.png)


```py
class Solution:
    def longestDecomposition(self, text: str) -> int:
        l, r = 0, len(text) - 1
        tl ,tr = '', ''
        ans = 0
        while l < r:
            tl = tl + text[l]
            tr = text[r] + tr
            if tl == tr:
                tl, tr = '', ''
                ans += 2
            l += 1
            r -= 1
        return ans + (1 if tl or len(text) % 2 == 1 else 0)
```
