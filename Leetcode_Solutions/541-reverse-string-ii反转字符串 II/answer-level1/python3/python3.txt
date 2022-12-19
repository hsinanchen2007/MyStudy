### 解题思路
每隔k隔翻转

### 代码

```python3
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        count = len(s)//(2*k)
        strs = list(s)
        ans = []
        i = 0
        while i*k < len(strs):
            tmp = strs[i*k:(i+1)*k]
            tmp.reverse()
            ans += tmp
            ans += strs[(i+1)*k:(i+2)*k]
            i += 2
        return ''.join(ans)
            
```