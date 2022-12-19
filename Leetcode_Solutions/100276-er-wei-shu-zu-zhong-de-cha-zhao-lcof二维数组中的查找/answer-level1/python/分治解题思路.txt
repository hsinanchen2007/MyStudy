一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 题解
从右上角(或者左下角)开始查找：

如果target更大，指针下移
如果target更小，指针左移

### 代码
```python
class Solution(object):
    def findNumberIn2DArray(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        i = 0
        if len(matrix) == 0: return False
        j = len(matrix[0]) - 1
        while i < len(matrix) and j >= 0:
            base = matrix[i][j]
            if target == base:
                return True
            elif target > base: 
                i += 1
            else:
                j -= 1
        return False
        
```
