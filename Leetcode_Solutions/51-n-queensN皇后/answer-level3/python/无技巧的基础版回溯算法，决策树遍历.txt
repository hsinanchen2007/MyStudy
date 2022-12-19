### 解题思路
见代码注释

### 代码

```python
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        使用最基础的回溯算法，决策树遍历
        """
        import copy

        if n == 0: return []
        res = []
        path = [['.' for _ in range(n)] for _ in range(n)]  # 申请列表，python字符串不能直接修改某个字符
        direction = [[-1, -1, -1, 0, 0, 1, 1, 1],
                     [-1, 0 ,1, -1, 1, -1, 0, 1]]  # 上下左右 左上 左下 右上 右下

        # 判断当前位置是否合法
        def can(i, j):
            for biger in range(1, n+1):  # 一层一层向8个方向扩展，像泛起的水花
                for k in range(8): 
                    nexti = i + direction[0][k]*biger
                    nextj = j + direction[1][k]*biger
                    if nexti >= 0 and nexti < n and nextj >= 0 and nextj < n:
                        if path[nexti][nextj] == 'Q':
                            return False
            return True


        # 判断第i层情况 i从0开始
        def back_track(path, i):
            # 结束条件
            if i == n:
                res.append(copy.deepcopy(path))  # 注意使用深拷贝
                return

            for j in range(n):  # 遍历当前层的所有选择
                if can(i, j) == False:  # 判断第i层的j位置是否合法
                    continue
                path[i][j] = 'Q'  # 做选择
                back_track(path, i+1)  # 回溯
                path[i][j] = '.'  # 撤销选择

        back_track(path, 0)
        str_res = [[''.join(line) for line in m] for m in res]
        return str_res


# s = Solution()
# print(s.solveNQueens(4))

# 小实验用于测试
# path = [['.', '.' , '.'], ['.', '.' , '.']]
# a = path[:][:]
# path[1][0] = 'O'
# print(a)
# a = '....'
# a[1] = 'o'
# print(a)


```