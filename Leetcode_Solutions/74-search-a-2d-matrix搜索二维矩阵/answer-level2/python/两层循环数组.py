### 解题思路
将目标数与每行最后一个数进行比较，如果小于等于最后一个数，说明目标数在此行中，可以与此行的数再次进行比较返回结果
### 代码

```python
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        for i in matrix:
            try:
                if target <= i[-1]:
                    for j in i:
                        if target == j:
                            return True
            except:
                return False
        return False
```