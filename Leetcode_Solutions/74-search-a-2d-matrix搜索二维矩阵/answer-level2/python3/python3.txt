简单的二分查找
![UC截图20191204141447.png](https://pic.leetcode-cn.com/f7c119195d73f80436a2a456b5d3d17256759a649a9211a92ca36397a16e168e-UC%E6%88%AA%E5%9B%BE20191204141447.png)
```
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l = []
        for i in range(len(matrix)):
            l += matrix[i]
        left = 0
        right = len(l) - 1
        while left <= right:
            mid = (left + right)//2
            if l[mid] < target:
                left = mid + 1
            elif l[mid] > target:
                right = mid - 1
            else:
                return True
        return False
```

