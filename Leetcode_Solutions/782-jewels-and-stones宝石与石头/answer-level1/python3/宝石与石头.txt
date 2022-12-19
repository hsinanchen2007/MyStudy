### 解题思路
字典

### 代码

```python3
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        baoshi = {}
        for x in J:
            if x not in baoshi:
                baoshi[x] = 1
        result = 0
        for x in S:
            if x in baoshi:
                result += 1
        return result
```