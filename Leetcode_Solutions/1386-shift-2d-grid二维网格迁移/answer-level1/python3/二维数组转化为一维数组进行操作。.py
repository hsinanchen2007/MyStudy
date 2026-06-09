### 解题思路
将二维数组转为一维数组，每迁移一次在首部插入尾部最后一个元素，最后将迁移后的一维数组还原为二维数组。


### 代码

```python3
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        col_len = len(grid[0])
        tmp = [i for item in grid for i in item]
        for i in range(k):
            tmp.insert(0, tmp.pop())
            
        res = []
        ret = []
        for i in tmp:
            ret.append(i)
            if len(ret)== col_len:
                res.append(ret)
                ret = []
        return res
```