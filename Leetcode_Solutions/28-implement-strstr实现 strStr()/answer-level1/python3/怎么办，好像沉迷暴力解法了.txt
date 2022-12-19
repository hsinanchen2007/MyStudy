![QQ截图20191113163632.png](https://pic.leetcode-cn.com/00b319ca5bee75872180f9d6ab026e0a90b1f2313cbeea9e581d1fdbf30c4d55-QQ%E6%88%AA%E5%9B%BE20191113163632.png)

```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        l1 = len(haystack)
        l2 = len(needle)
        if l2 == 0:
            return 0
        elif l2 > l1:
            return -1
        else:
            cur = 0
            i = 0
            while i < l2 and cur <= l1-l2:
                if needle[i] == haystack[cur + i]:
                    i += 1
                else:
                    i = 0
                    cur += 1
            if i == l2:
                return cur
            else:
                return -1
```
