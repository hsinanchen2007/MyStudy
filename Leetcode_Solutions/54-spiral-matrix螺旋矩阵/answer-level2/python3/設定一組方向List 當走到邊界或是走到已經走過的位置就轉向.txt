### 解题思路
設定一組方向List 當走到邊界或是走到已經走過的位置就轉向
直到 最後儲存的 List數量與 matrix 像素一樣多就結束

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        M = len(matrix)
        N = len(matrix[0])
        dirs = [[ 0,  1], [ 1,  0], [ 0, -1], [-1,  0]]
        
        vec = []
        vec.append(matrix[0][0])
        matrix[0][0] = float('inf')
        position = [0, 0]
        dir_flag = 0
        while True:
            print([position[0]], [position[1]])
            new_start = position.copy()
            new_start[0] += dirs[dir_flag][0]
            new_start[1] += dirs[dir_flag][1]
            if 0<=new_start[0]<M and 0<=new_start[1]<N and matrix[new_start[0]][new_start[1]] != float('inf'):
               position = new_start
               vec.append(matrix[new_start[0]][new_start[1]])
               matrix[new_start[0]][new_start[1]] = float('inf')
            else:
                dir_flag = (dir_flag + 1) % 4

            if len(vec) == M*N:
                break

        return vec                



        
```