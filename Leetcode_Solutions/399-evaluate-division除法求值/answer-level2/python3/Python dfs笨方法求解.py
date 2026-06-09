一样是dfs，和树不同的在于这里应该是一个双向有环图，需要定义一个used_set来记录，避免循环递归。
```
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        # 定义基本的邻接表矩阵
        str_lyst = []
        for equation in equations:
            for str_ele in equation:
                if str_ele not in str_lyst:
                    str_lyst.append(str_ele)
        n = len(str_lyst)
        str_num = {}
        adjacency = [['#'] * n for _ in range(n)]
        for i in range(n):
            str_num[str_lyst[i]] = i
            adjacency[i][i] = 1.0
        n_val = len(values)
        # 创建基本的邻接边
        for i in range(n_val):
            start_index = str_num[equations[i][0]]
            end_index = str_num[equations[i][1]]
            adjacency[start_index][end_index] = values[i]
            adjacency[end_index][start_index] = 1 / values[i]
        res = []
        idx_set = set(range(n))

        # 这里应该有一个基本的dfs，来获取所有不是直接连接的两个点的除法关系
        def dfs(root, start, end, cur_val, used_set):
            if used_set == idx_set:
                return
            cur_val *= adjacency[start][end]
            adjacency[root][end] = cur_val
            adjacency[end][root] = 1 / cur_val
            used_set.add(end)
            for new_end in range(n):
                if new_end in used_set:
                    continue
                if adjacency[end][new_end] == '#':
                    continue
                dfs(root, end, new_end, cur_val, used_set)

        for i in range(n):
            dfs(i, i, i, 1.0, {i})

        for query in queries:
            start_index = str_num[query[0]] if query[0] in str_num else -1
            end_index = str_num[query[1]] if query[1] in str_num else -1
            if start_index < 0 or end_index < 0:
                res.append(-1.0)
            else:
                if adjacency[start_index][end_index] == '#':
                    res.append(-1.0)
                else:
                    res.append(adjacency[start_index][end_index])
        return res
```
