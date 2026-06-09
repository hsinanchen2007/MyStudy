### 解题思路
常规思路：
1. 对于每个坐标位置，都统计其周边活细胞个数（记为`cnt`），并以此作为其下轮生死依据：
2. 生存定律给了4条，实际上只有以下3种情形：
    - 当`cnt=2`时，保持上轮状态不变：即之前活则下轮活、之前死则下轮死
    - 当`cnt=3`时，下轮无条件的活，无论之前生死
    - 其余情况，即`cnt<2`或`cnt>3`，下轮无条件的死，无论之前生死
3. 为了确保不会在更新前一个细胞状态时影响后续判断（即题目要求的同步更新），这里考虑用列表推导式实现同时赋值(实际上相当于占用了内存作为临时空间)
4. 当然，如果用一个`copy.deepcopy(board)`副本其效果是一样的，只不过没有列表推导来得爽！

注：对于嵌套列表，在inplace更新赋值时要加冒号，即用`board[:]=……`而不能用`board=……`
类似还有这个题：[48.旋转图像，一行代码两次翻转](https://leetcode-cn.com/problems/rotate-image/solution/python-zipliang-ci-fan-zhuan-ji-ke-by-luanz/)

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return
        def isValid(x, y):#判断给定坐标是否在区间内
            return 0<=x<m and 0<=y<n
        m, n = len(board), len(board[0])
        delt = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        def isAlive(i, j):#根据给定坐标判断其下轮生死
            cnt = sum([board[i+di][j+dj] for di, dj in delt if isValid(i+di, j+dj)])
            return board[i][j] if cnt == 2 else (1 if cnt == 3 else 0)
        board[:] = [[isAlive(i,j) for j in range(n)] for i in range(m)]
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)