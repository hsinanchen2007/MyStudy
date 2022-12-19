### 解题思路
![结果.jpg](https://pic.leetcode-cn.com/020c9e592c247f4292b15edfd129446f883cb6c4d79021e56f9a74e6ccaca90f-%E7%BB%93%E6%9E%9C.jpg)

如图，下面两个是暴力法的运行结果，上面两个是从左下角开始找值的运行结果。为什么我用O(m+n)的算法写的python3程序，还不如暴力法（两层循环）来的快？

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix) -1
        n = 0

        while m >=0 and n < len(matrix[0]):
            if matrix[m][n] == target:
                return True
            elif matrix[m][n] > target:
                m -= 1
            else:
                n += 1
        
        return False
```