### 解题思路
缓存每一个节点的邻接节点的路径深度，缓存路径以字典形式保存，key是"当前节点值_邻接节点值"，value是"邻接节点的最大深度"

如[0,3][1,3][2,3],[3,4],[4,5]中，key：3-4的值是2，表示以3为节点，3的邻接节点4的子路径深度是2，这样缓存每次走过的路径，下次走之前先查一下，没有缓存则dfs；

效率不高，直接dfs会超时。

### 代码

```python3
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if not edges or not n:
            return [0]
        if 1 == n:
            return [1]
//转化的邻接链表
        adjacency = [[] for _ in range(n)]
        output = []
//用来存每一个节点作为起始点时，他的子路径最大深度
        max_vals = [0 for _ in range(n)]

        for u, v in edges:
            adjacency[u].append(v)
            adjacency[v].append(u)

//缓存路径
        path_dic = {}
//dfs
        def helper(cur: int, pre: int) -> int:
            cur_adjacency = adjacency[cur]
            max_sub_depth = 0
            for vertex in cur_adjacency:
// 去掉之前的点，由于无向图，所以做邻接链表的时候1-2，2-1这种都算上了
               if vertex == pre:
                    continue
//缓存路径的key，值是子路径的长度，如[0,3][1,3][2,3],[3,4],[4,5]中，key：3-4的值是2，表示以3为节点，3的邻接节点4的子路径深度是2，这样缓存每次走过的路径，下次走之前先查一下，没有缓存则dfs
                key = str(cur) + '-' + str(vertex)
                if key in path_dic:
                    level = path_dic[key]
                else:
                    level = helper(vertex, cur)
                    path_dic[key] = level

                if level > max_sub_depth:
                    max_sub_depth = level

            return max_sub_depth + 1

 
        for i in range(n):
            max_vals[i] = helper(i, -1)

        min_val = min(max_vals)
        for index, val in enumerate(max_vals):
            if val == min_val:
                output.append(index)
        return output

```