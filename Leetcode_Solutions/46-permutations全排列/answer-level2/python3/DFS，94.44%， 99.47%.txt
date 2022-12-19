把每个元素当成节点，全排列相当于搜索所有路径。画出树状图以后可以发现适用基于树的深度优先搜索。
需要稍微修改：单个路径中已经生成过的节点不可以再次生成。
```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def DFS(candidates, start, pathes):
            frontier = [[start]]
            while frontier:
                nodes = frontier.pop(0)
                if len(nodes) == len(candidates):
                    pathes.append(nodes)
                else:
                    for n in candidates:
                        if n not in nodes:
                            tmp = nodes.copy()
                            tmp.append(n)
                            frontier.append(tmp)
        
        pathes = []
        for i in nums:
            DFS(nums, i, pathes)
        return pathes
```
执行用时 :40 ms, 在所有 Python3 提交中击败了94.44%的用户
内存消耗 :12.7 MB, 在所有 Python3 提交中击败了99.47%的用户