### 解题思路
双层循环即可

### 代码

```python3
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        for i in grid:
            for j in i:
                if j < 0 :
                    count +=1
        return count

```