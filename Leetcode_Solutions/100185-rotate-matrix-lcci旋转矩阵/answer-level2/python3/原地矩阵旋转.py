内存消耗13.7M，速度一般

每次循环将矩阵最外层旋转，而后向内部递进
![29DC09E747095ABA5D5FA5F79D203F19.png](https://pic.leetcode-cn.com/fd678cb5f8bf22f7c71a333d068b8946590cf2ddd034c83398056e9762c393bf-29DC09E747095ABA5D5FA5F79D203F19.png)

```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        right_border=len(matrix)-1
        left_border=0
        top_border=0
        bottom_border=len(matrix)-1
        offset=0
        size=len(matrix)
        while size>1:
            for i in range(size-1):
                temp=matrix[top_border][i+left_border]
                matrix[top_border][i+left_border]=matrix[bottom_border-i][left_border]
                matrix[bottom_border-i][left_border]=matrix[bottom_border][right_border-i]
                matrix[bottom_border][right_border-i]=matrix[top_border+i][right_border]
                matrix[top_border+i][right_border]=temp
            offset+=1
            size-=2
            right_border-=1
            left_border+=1
            top_border+=1
            bottom_border-=1
```
