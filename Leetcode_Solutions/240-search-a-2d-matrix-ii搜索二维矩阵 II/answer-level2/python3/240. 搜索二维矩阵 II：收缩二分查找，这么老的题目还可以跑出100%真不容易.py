
第一种方法，具体解读在官解和其他大佬的题解那里，非常巧妙的路径查找法，从某个角开始扫描，时间复杂度$O(M+N)$。

```py
class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        m, n = len(matrix), len(matrix[0])
        i, j = m - 1, 0
        while i >= 0 and j < n:
            if matrix[i][j] > target:
                i -= 1
            elif matrix[i][j] < target:
                j += 1
            else:
                return True
        return False
```

第二种方法，收缩区间的二分查找法。

```py
class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        p = len(matrix[0])
        for mat in matrix:
            if mat[-1] < target:    #如果行内末元素太小就跳过这行
                continue
            if mat[0] > target:     #如果行内首元素太大就返回错误
                return False
            m = bisect.bisect(mat, target, hi = p)  #默认插在元素右边的二分查找
            if mat[m - 1] == target:
                return True
            p = m                   #区间收缩
        return False
```
![image.png](https://pic.leetcode-cn.com/6dac2229b7094daa8d92a065f9a27c6fad8e06deaad603248c0f70e437b4afed-image.png)
