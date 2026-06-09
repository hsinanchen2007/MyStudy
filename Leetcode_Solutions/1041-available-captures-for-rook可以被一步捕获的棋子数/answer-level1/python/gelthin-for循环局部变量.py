### 解题思路
读懂题意：车一次移动可以四个方向都走一遍，大杀四方。其四个方向上的第一个子如果是敌对卒，都会被吃掉。

首先，考虑遍历 board，找出车的位置 (x,y)

#### python for 循环是无法使用 内部语句的变量的

但我在 spyder 测试居然可以用，在这里leetcode 上测试不可以用!!?

```python
for i in range(8):
    for j in range(8):
        if i+j == 2:
            x, y = i, j
            break
print(i, j)
print(x, y)

def test():
    for i in range(8):
        for j in range(8):
            if i+j == 2:
                x, y = i, j
                break
    print(i, j)
    print(x, y)
```





### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        
        x, y = -1,-1 # 若无此, x,y 算局部变量， 后续无法使用
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    x, y = i, j  # 不要直接用 i,j 局部变量
                    break
        dx, dy = [1,-1,0,0], [0,0,-1,1]
        
        count = 0
        for i in range(4):  # 大杀四方：朝四个方向都走一次，算一次移动
            nx, ny = x+dx[i], y+dy[i]
            while 0 <= nx < 8 and 0 <= ny < 8:
                if board[nx][ny] == 'B':
                    break
                if board[nx][ny] == 'p':
                    count += 1
                    break
                nx += dx[i]
                ny += dy[i]

        return count
```