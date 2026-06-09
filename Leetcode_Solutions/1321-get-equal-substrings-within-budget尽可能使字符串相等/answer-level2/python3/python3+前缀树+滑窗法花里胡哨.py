### 解题思路
越是花哨，越是慢
### 代码

```python3
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        res = [0]
        for i in range(len(s)):
            res.append(abs(ord(s[i]) - ord(t[i])))
        for i in range(1,len(res)):
            res[i] += res[i-1]
        window = []
        ans = 0
        for i in range(1,len(res)):
            window.append(res[i])
            if window[-1] > maxCost:
                while window[-1] - window[0] > maxCost:
                    window.pop(0)
            if window[-1] > maxCost:
                ans = max(ans, len(window)-1)
            else:
                ans = max(ans,len(window))
        return ans
```