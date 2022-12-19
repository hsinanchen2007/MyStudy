### 解题思路
主要思想就是确定什么时候应该转换移动的方向：1）当移动到边界或该点已经访问过，则需要移动方向  2）有了1）的思想就可以找寻
边界移动方向的条件
具体方法如下代码非常详细

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        if m == 0:
            return []
        n = len(matrix[0])
        orient = 3  # 读数移动方向0：向上 1：向下 2：向左 3：向右【默认方向】
        nums = []
        flags = [[False for _ in range(n)] for _ in range(m)]
        i, j = 0, 0
        for _ in range(m*n):
            nums.append(matrix[i][j])
            flags[i][j] = True  # 标记该点已经访问过
            # 根据移动方向确定下标的变化
            if orient == 0:
                i -= 1
            elif orient == 1:
                i += 1
            elif orient == 2:
                j -= 1
            else:
                j += 1
            # 向右移动到达边界或者当前点已经访问过了，则向下移
            if j > n-1 or (orient==3 and flags[i][j] == True):
                orient = 1
                j -= 1  # 为什么 i，j会变化，因为上面我已经i，j产生过变化了（已经进行了移动）
                i += 1
            # 向下移动到达边界或者当前点已经访问过了，则向左移
            elif i > m-1 or (orient == 1 and flags[i][j] == True):
                orient = 2
                i -= 1
                j -= 1
            # 同理分析
            elif j < 0 or (orient == 2 and flags[i][j] == True):
                orient = 0
                j += 1
                i -= 1
            # 同
            elif i < 0 or (orient == 0 and flags[i][j] == True):
                orient = 3
                i += 1
                j += 1
        return nums
```