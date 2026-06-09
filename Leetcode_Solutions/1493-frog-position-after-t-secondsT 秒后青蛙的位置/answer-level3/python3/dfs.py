将路径转为图，直接深度优先遍历 记录跳到当前节点的概率：
```
import collections


class Solution(object):
    def frogPosition(self, n, edges, t, target):
        """
        :type n: int
        :type edges: List[List[int]]
        :type t: int
        :type target: int
        :rtype: float
        """
        dirc = collections.defaultdict(list)
        for i, j in edges:
            dirc[i].append(j)
            dirc[j].append(i)

        def dfs(current, t, temp):
            if current == target and (t==0 or len(dirc[current])==0): # 终止条件 没有步数或者没有路可以走
                return temp
            if t == 0 or len(dirc[current]) == 0:
                return 0
            nextPath = list(dirc[current])
            res = 0.0
            num = 1 / len(nextPath)
            for path in nextPath:
                dirc[current].remove(path)
                dirc[path].remove(current)
                res += dfs(path, t - 1, temp * num)
                dirc[current].append(path)
                dirc[path].append(current)
            return res

        return dfs(1, t, 1)
```

