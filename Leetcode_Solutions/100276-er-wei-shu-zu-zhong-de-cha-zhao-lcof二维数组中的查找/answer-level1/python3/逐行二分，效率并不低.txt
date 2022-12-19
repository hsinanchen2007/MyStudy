### 解题思路
看了太多的一次减掉一行或一次减掉一列，最终保证O(m+n)复杂度，思路很好。
但最直接的思路可能还是逐行二分吧。如果行数大于列数，那就先转置一下，然后调用内置二分查找函数（当然自己写一个也行），效率并不低！
时间复杂度：O(min(m,n)*log(max(m,n)))

### 结果
![image.png](https://pic.leetcode-cn.com/661f33b15614f9845f3c851c1acb8eb2aa3cc3ecd377d1879b7228d44f964e00-image.png)

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        if len(matrix)>len(matrix[0]):
            matrix = zip(*matrix)
        for lyst in matrix:
            index = bisect.bisect_right(lyst, target)
            if index and lyst[index-1] == target:
                return True
        return False
```