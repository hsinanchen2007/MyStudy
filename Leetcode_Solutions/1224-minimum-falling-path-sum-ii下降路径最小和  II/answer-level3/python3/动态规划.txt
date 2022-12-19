### 解题思路
相邻步骤间的关系是动态规划的最主要问题
初始状态：第一行的值本身为该位置结尾的最小值
遍历当前行的每一列，该位置结尾的最小值应为(当前值+上一步骤中的非当前列的最小值)

### 代码

```python3
class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        nrow = len(arr)
        ncol = len(arr[0])
        from collections import defaultdict
        dict1 = defaultdict(list)
        dict1[0] = arr[0]
        for subrow in range(1,nrow):
            for subcol in range(ncol):
                cp2 = dict1[subrow-1][:]
                del cp2[subcol]
                dict1[subrow].append(min(cp2)+arr[subrow][subcol])
        return min(dict1[nrow-1])
```