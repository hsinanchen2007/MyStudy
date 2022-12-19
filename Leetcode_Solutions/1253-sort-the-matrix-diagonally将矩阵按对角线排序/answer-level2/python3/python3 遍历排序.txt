### 解题思路
按顺序遍历即可

### 代码

```python3
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        #直接遍历不行咩
        #对第一行
        m = len(mat)#行数
        n = len(mat[0]) #列数
        for j in range(n-1):
            x = 0
            y = j
            localtion = []
            numbers = []
            while x <= m-1 and y <= n-1:
                localtion.append((x,y))
                numbers.append(mat[x][y])
                x += 1
                y += 1
            numbers = sorted(numbers)
            # print(localtion)
            # print(numbers)
            for (x,y),num in zip(localtion,numbers):
                mat[x][y] = num
        if m > 2:
            for i in range(1,m-1):
                x = i
                y = 0
                localtion = []
                numbers = []
                while x <= m-1 and y <= n-1:
                    localtion.append((x,y))
                    numbers.append(mat[x][y])
                    x += 1
                    y += 1
                numbers = sorted(numbers)
                # print(localtion)
                # print(numbers)
                for (x,y),num in zip(localtion,numbers):
                    mat[x][y] = num
        return mat



                
            

```