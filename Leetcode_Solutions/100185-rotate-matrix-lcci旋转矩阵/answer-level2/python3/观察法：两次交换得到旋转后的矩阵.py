观察由三组样例旋转后的结果可发现，旋转结果是由原矩阵对角线交换再横向对称交换得到的。
```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        row = 0
        for i in range(rows):
            for j in range(i+1):
                temp = matrix[row][j]
                matrix[row][j] = matrix[j][row]
                matrix[j][row] = temp
            row += 1
        for i in range(rows//2):
            for j in range(rows):
                temp = matrix[j][i]
                matrix[j][i] = matrix[j][rows-i-1]
                matrix[j][row-i-1] = temp
```
但要求不占用额外空间，而代码中temp是占用的。抱着试试的心态，居然通过了，而且内存还超过了100%用户，这就有点奇怪，按理说占用额外内存应该会低于不占用额外内存的算法呀！
![capture_20200217213035851.bmp](https://pic.leetcode-cn.com/777a32e5c6319e8a5cc7894d9b8ae2f4444ffa4d4cab7d774a20f9d22b85cfeb-capture_20200217213035851.bmp)
