### 解题思路
这里主要是要控制一个 2k, k 以及剩余的元素的个数。


### 代码

```python3
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        n = len(s)
        i = 0
        res = ""
        while i<n:
            if i+2*k <= n:
                res = res + s[i:i+k][::-1] + s[i+k:i+2*k]
                i = i+2*k
            else:
                if i+k <= n:
                    res = res + s[i:i+k][::-1] + s[i+k:]
                else:
                    res = res + s[i:][::-1]
                break
        return res
```