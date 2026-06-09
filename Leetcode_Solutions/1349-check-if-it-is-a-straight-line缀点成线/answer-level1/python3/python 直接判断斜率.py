### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        ans = []
        for i in range(1, len(coordinates)):
            if coordinates[i][0] - coordinates[i-1][0] == 0:
                k = float("inf")
            else:
                k = (coordinates[i][1] - coordinates[i-1][1])/(coordinates[i][0] - coordinates[i-1][0])
            ans.append(k)
        return len(set(ans)) == 1
```