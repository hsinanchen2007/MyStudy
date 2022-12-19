### 解题思路
以行循环，依次计算每一列。
如果不在对角线和横纵轴无效的节点的范围内，则添加，继续向下一行递归，递归完成，回溯一步；否则计算下一列

### 代码

```python3
class Solution:
    def totalNQueens(self, n: int) -> int:
        def compute_invalid(coor, n, invalid_coors):
            """
                根据坐标计算并添加无效的节点坐标
            """
            # 计算横轴，纵轴
            for i in range(n):
                for j in range(n):
                    invalid_coors.add((coor[0], j))
                    invalid_coors.add((i, coor[1]))
            i = 1
            # 计算右对角线
            while (coor[0] + i < n) and (coor[1] + i < n):
                invalid_coors.add((coor[0] + i, coor[1] + i))
                i += 1

            i = 1
            while (coor[0] - i >= 0) and (coor[1] - i>= 0):
                invalid_coors.add((coor[0] - i, coor[1] - i))
                i += 1

            #计算左对角线
            i = 1
            while (coor[0] - i >= 0) and (coor[1] + i < n):
                invalid_coors.add((coor[0] - i, coor[1] + i))
                i += 1

            i = 1
            while (coor[0] + i < n) and (coor[1] - i >= 0):
                invalid_coors.add((coor[0] + i, coor[1] - i))
                i += 1


        def dfs(i, invalid_coors, path, n, res):
            if i == n - 1:
                for k in range(n): # 如果行号为n -1，表示最后一行，循环该行所有j列
                    if (i, k) not in invalid_coors: # 坐标不在无效的坐标集里，添加该坐标，添加路径，并回溯
                        path.append((i, k)) # 路径添加该坐标
                        res.append(path[:]) # 结果添加这条路径的备份
                        path.pop()  # 路径回溯一步
            elif i < n - 1: # 如果行号 < n-1
                for k in range(n): # 循环该行所有j列
                    if (i, k) not in invalid_coors: # 坐标不在无效的坐标集里，添加该坐标，计算无效节点，递归下一行，回溯无效节点和路径
                        path.append((i, k)) # 路径添加该坐标
                        temp = list(invalid_coors)[:] # 记录无效节点的备份
                        compute_invalid((i, k), n, invalid_coors) # 根据当前坐标计算无效节点
                        dfs(i + 1, invalid_coors, path, n, res) # 递归下一行
                        invalid_coors = set(temp[:]) # 回溯无效节点
                        path.pop() #回溯一步

        res = list(list())
        invalid_coors = set()
        path = []
        dfs(0,  invalid_coors, path, n, res)
        return len(res)
```