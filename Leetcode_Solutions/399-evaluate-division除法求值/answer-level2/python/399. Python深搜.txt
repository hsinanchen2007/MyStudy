### 解题思路
思路：首先定义一张二维表用来记录目前已经知道的两个变量的商，然后利用深搜进行搜索，在搜索的过程中对表进行补全而不是直接尝试对所有的空位进行补全，这样可以避免对不必要的商的求解，下面的实现就是基于这种思路。

### 代码

```python
class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        
        # 第一次遍历统计变量个数，并生成var->ind字典
        var2ind = {}
        ind2var = []
        var_num = 0
        for x, y in equations:
            if x not in var2ind:
                var2ind[x] = var_num
                ind2var.append(x)
                var_num += 1
            if y not in var2ind:
                var2ind[y] = var_num
                ind2var.append(y)
                var_num += 1
        # 第二次遍历，对除法表进行初始化
        res_map = [[float('inf')] * var_num for _ in range(var_num)]
        for (x, y), z in zip(equations, values):
            i = var2ind[x]
            j = var2ind[y]
            res_map[i][j] = z
            if z:
                res_map[j][i] = z ** -1
        # 对于查找的每个结果使用深搜，并将过程值填写到
        ind_set = set([i for i in range(var_num)])
        def get_res(temp, i, j, res, mem_set):
            # 当前位置是(i, temp)
            res_map[i][temp] = res
            if res != 0:
                res_map[temp][i] = res ** -1
            if temp == j:
                return True
            for k in ind_set - mem_set: # 倒序遍历
                if res_map[temp][k] != float('inf'):
                    if get_res(k, i, j, res * res_map[temp][k], set(list(mem_set) + [k])):
                        return True
            return False

        res_list = []
        for x, y in queries:
            if x not in var2ind:
                res_list.append(-1.0)
                continue
            i = var2ind[x]
            if y not in var2ind:
                res_list.append(-1.0)
                continue
            j = var2ind[y]
            # 确保i <= j
            if j < i:
                temp = i
                i = j
                j = temp
            get_res(i, i, j, 1, set([i]))
            i = var2ind[x]
            j = var2ind[y]
            if res_map[i][j] != float('inf'):
                res_list.append(res_map[i][j])
            else:
                res_list.append(-1.0)
        return res_list
```