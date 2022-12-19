### 解题思路
用字典表示树，每一项的表示为（父节点：[子节点们]，用时，到该点概率））。遍历时直接注意更新节点三个属性值，及时跟target比对（判断条件想得要全面：达到target之后，用时刚好为t或者target为叶子的话用时不少于t，此时才能输出该点的概率；否则不会在该点停留，输出概率为0）。

### 代码

```python3
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        if target == 1:
            return 1 if n == 1 else 0
        dic = dict().fromkeys(range(1,n+1))
        for key in dic.keys(): dic[key] = [[],0,1]
        for edge in edges:
            if edge[0]<edge[1]:
                dic[edge[0]][0].append(edge[1])
            else:
                dic[edge[1]][0].append(edge[0])
        queue,level = [], 0
        queue.append(1)
        while queue:
            nextL,level = [], level + 1
            for node in queue:
                for son in dic[node][0]:
                    nextL.append(son)
                    dic[son][1], dic[son][2] = level, dic[node][2] / len(dic[node][0])
                    if son == target:
                        return dic[son][2] if t == dic[son][1] or (t > dic[son][1] and len(dic[son][0])==0) else 0
            queue = nextL
```