1. 暴力解法：用map记录每个节点入节点set和出节点set求解
```
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        out_dict = {}
        in_dict = {}
        if len(trust) == 0: return 1
        for item in trust:
            in_item, out_item = item[0], item[1]
            if out_item not in out_dict: out_dict[out_item] = {in_item}
            else: out_dict[out_item] |= {in_item}
            if in_item not in in_dict: in_dict[in_item] = {out_item}
            else: in_dict[in_item] |= {out_item}
        for i in range(1,N+1):
            if i in out_dict and i not in in_dict and len(out_dict[i]) == N-1:return i
            
        return -1
```

3. 图解法：用一个二位数组记录每个节点的入度和出度，如果存在入度为0，出度为N-1，则该节点为法官；反之，法官不存在。
```
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        grid = [[0,0] for i in range(N)]
        for item in trust:
            grid[item[0]-1][0] +=1
            grid[item[1]-1][1] +=1
        for i,item in enumerate(grid):
            if item[0] == 0 and item[1] == N-1: return i+1
                        
        return -1
        
```
