![image.png](https://pic.leetcode-cn.com/37bac9d0969cbc3be8e10372a6323a4167592bf71a2336061b582381d7c5348c-image.png)

也不见得慢到不可接受的情况

```
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        a = []
        for i in range(R):
            for j in range(C):
                a += [[abs(i - r0) + abs(j - c0), i, j]]
        return [[i, j] for _, i, j in sorted(a)]
```
