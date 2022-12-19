这道题的做法事实上和54类似，都是螺旋遍历一个矩阵，而螺旋的遍历可以当做一边遍历一边缩小矩阵的大小，可以定义4个变量：up、down、left、right来界定矩阵的范围，然后填上相对应的数即可。
```python
class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        num = 1
        matrix = [[0 for _ in range(n)] for _ in range(n)]
        up, down, left, right = 0, n - 1, 0, n - 1

        while True:
            for i in range(left, right + 1):
                matrix[up][i] = num
                num += 1
            up += 1
            if up > down: break
            
            for i in range(up, down + 1):
                matrix[i][right] = num
                num += 1
            right -= 1
            if right < left:break

            for i in range(right, left - 1, -1):
                matrix[down][i] = num
                num += 1
            down -= 1
            if down < up:break

            for i in range(down, up - 1, -1):
                matrix[i][left] = num
                num += 1
            left += 1
            if left > right:break

        return matrix
```
