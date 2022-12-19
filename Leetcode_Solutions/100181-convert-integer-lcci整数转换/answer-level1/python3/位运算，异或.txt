### 解题思路
注意这里python得负数表示

### 代码

```python3
class Solution:
    def convertInteger(self, A: int, B: int) -> int:
        ans=0
        A=A&0xffffffff
        B=B&0xffffffff
        while A or B:
            ans+=(A&1)^(B&1)
            A,B=A>>1,B>>1
        return ans            
```