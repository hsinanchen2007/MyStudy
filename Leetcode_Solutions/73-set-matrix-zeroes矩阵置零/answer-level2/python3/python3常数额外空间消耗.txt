使用一个列表来储存数组中0的索引，最后根据这个列表来遍历修改
![UC截图20191204140244.png](https://pic.leetcode-cn.com/6d4b63091ecc468770425d510b401980208a5e0ba76adb1ab6d68135388eb3e3-UC%E6%88%AA%E5%9B%BE20191204140244.png)
```
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        l = []
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    l.append([i,j])
        for item in l:
            matrix[item[0]] = [0] * n
            for i in range(m):
                matrix[i][item[1]] = 0
```
