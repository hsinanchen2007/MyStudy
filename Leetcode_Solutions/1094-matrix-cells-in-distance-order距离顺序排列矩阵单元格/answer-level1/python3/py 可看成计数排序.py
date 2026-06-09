### 解题思路
计数排序，可能的距离是有限范围内[0, R+C]

### 代码

```python3
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        disArr = [[] for dis in range(R + C + 1)]
        for i in range(R):
            for j in range(C):
                dis = abs(i - r0) + abs(j - c0)
                disArr[dis].append([i,j])
        res = []
        for dis in range(R + C + 1):
            res += disArr[dis]
        return res
```