### 解题思路
用堆栈的思路，如果遇到c，看看前两个是不是ab，是的话一起去掉，不是的话放入堆栈。

### 代码

```python3
class Solution:
    def isValid(self, S: str) -> bool:
        S2 = ''             # 充当堆栈作用
        for e in S:         
            # 如果是c，前面两个是ab，则去掉堆栈中的ab
            if e == 'c' and len(S2) >= 2 and (S2[-1] == 'b' and S2[-2] == 'a'):
                S2 = S2[:-2]   # -2是因为此时c还没放进来
            else:
                S2 += e 
        return S2 == ''
```