### 解题思路
1.判断是否存在二维数组，如果不存在则直接返回False
2.从右上角的值开始判断，如果第一个数不满足，则列减少1，因为数字是从左往右，从上往下递增
3.做一个循环判断，判断的条件是行不能小于二维数组的列长度，而行则是必须大于等于0行

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix)==0:
            return False
        row=0
        col=len(matrix[0])-1
        while row<len(matrix) and col>=0:
            if matrix[row][col]==target:
                return True
            elif target>matrix[row][col]:
                row+=1
            else:
                col-=1
        return False
```