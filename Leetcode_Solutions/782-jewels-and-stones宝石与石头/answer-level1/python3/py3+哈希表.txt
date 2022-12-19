### 代码

```python3
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        output=0
        J=set(J)
        for i in S:
            if i in J:
                output+=1
        return output
```