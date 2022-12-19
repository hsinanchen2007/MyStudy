
```
class Solution:
    def depthSumInverse(self, nestedList: List[NestedInteger]) -> int:
        
        if len(nestedList) == 0:
            return 0
        maxDepth = -1
        res = []    # 保存每个节点及其深度 
        
        def dfs(L, depth):
            nonlocal maxDepth
            maxDepth = max(depth, maxDepth)
            for item in L:
                if item.isInteger():
                    res.append((item.getInteger(), depth))
                else:
                    dfs(item.getList(), depth+1)
        
        dfs(nestedList, 1)
        total = 0
        # 得到每个节点的深度和最大深度后，就可以计算加权了
        for num, depth in res:
            total += (num * (maxDepth - depth + 1))
        
        return total
```
