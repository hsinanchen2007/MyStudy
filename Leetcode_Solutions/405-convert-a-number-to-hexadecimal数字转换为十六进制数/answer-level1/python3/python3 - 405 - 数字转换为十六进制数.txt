### 解题思路
常规长除法

### 代码

```python3
class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return '0'
        dic = {'10':'a', '11':'b', '12':'c', '13':'d', '14':'e', '15':'f'}
        ans = []
        max_int = 0xffffffff + 0x00000001
        if num < 0:
            num += max_int
        while num != 0:
            tmp = num % 16
            num = num // 16
            ans.append(str(tmp))
        ans.reverse()
        for i in range(len(ans)):
            if ans[i] in dic:
                ans[i] = dic[ans[i]] 
        return ''.join(ans)
```