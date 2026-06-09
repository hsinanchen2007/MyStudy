先将第一行加入数组,然后将余下的数组先转置,后reverse,这样得到了new_matrix,循环以上步骤即可
![image.png](https://pic.leetcode-cn.com/1c293ff53eca509924287431408b5dcfa8a2ad6a884a746f00d16fb13333c894-image.png)
```py
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        def reverse_clock(matrix):
            new_matrix=[[0]*len(matrix) for _ in range(len(matrix[0]))]
            for i in range(len(matrix)):
                for j in range(len(matrix[0])):
                    new_matrix[j][i]=matrix[i][j]
            new_matrix.reverse()
            return new_matrix
        res=[]
        while matrix:
            for e in matrix[0]:
                res.append(e)
            matrix.pop(0)
            if matrix:
                matrix=reverse_clock(matrix)
        return res
```
当然还有更Python的做法便是使用zip函数代替上面的reverse_clock函数,用时差不多
![image.png](https://pic.leetcode-cn.com/a9b4f439515087aeb80acb95337707fd79a5e43f63da86e3f9fc747649a5f762-image.png)

```py
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        while matrix:
            res += matrix.pop(0)
            matrix = list(zip(*matrix))[::-1]
        return res
```
