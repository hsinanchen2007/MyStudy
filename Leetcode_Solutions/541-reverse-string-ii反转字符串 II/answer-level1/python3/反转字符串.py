### 解题思路
一个python小白写的解题 阅读起来完全没有压力。
把s得长度用k来分 0*k 1*k 2*k 3*k 4*k  还有剩余得部分len(s) - n*k
发现只要会被2整除得部分都需要反转
这个就是解题思路

### 代码

```python3
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        ans = ''
        count = len(s) // k
        if len(s) <= k:
            return s[::-1]
        for i in range(count):
            if i % 2 == 0:
                b = s[i*k:i*k+k][::-1]            
                ans += b
            else:
                ans += s[i*k:i*k+k]

        if len(s) % k == 0:
            return ans
        if count % 2 == 0:
            ans += s[(count)*k:len(s)][::-1]
        else:
            ans += s[count*k:len(s)]
        return ans
```