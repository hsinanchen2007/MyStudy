### 解题思路
暴力遍历法如下

### 代码

```python3
class Solution:
    def maximumSwap(self, num: int) -> int:
        t = num
        num = str(num)
        num = list(num)
        p = 0
        for i in range(len(num)):
            for j in range(len(num)):
                if i == j: break
                num[i],num[j] = num[j],num[i]
                if int(''.join(num)) > t and int(''.join(num)) > p:
                    p = int(''.join(num))
                num[i],num[j] = num[j],num[i]
        if p == 0: return t
        return p
```