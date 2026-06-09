### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        setJ = set(J)
        return sum(s in J for s in S)

        # O(n^2)
        # cnt = 0
        # for c in S:
        #     if c in J:
        #         cnt += 1
        # return cnt
```