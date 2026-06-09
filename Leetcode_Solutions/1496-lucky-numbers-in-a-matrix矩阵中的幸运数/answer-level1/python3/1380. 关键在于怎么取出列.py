### 解题思路
取出每行最小值，取出每列最大值，交集即为幸运树。
遇到的两个问题：
1. 怎么取出列：list(zip(*matrix))
2. 怎么取交集：[val for val in min_vol if val in max_column]

### 代码

```python3
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        min_vol = []
        for item in matrix:
            min_vol.append(min(item))

        max_column  = []
        for item in list(zip(*matrix)):
            max_column.append(max(item))

        return [val for val in min_vol if val in max_column]

```