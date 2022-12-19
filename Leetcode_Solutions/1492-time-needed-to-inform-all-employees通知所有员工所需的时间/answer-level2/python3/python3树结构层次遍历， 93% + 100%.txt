### 解题思路
注意几个点：
1. n == 1的时候的特殊情况
2. 最耗时的未必在最后一层
这题比较类似于代价最长的路径
### 代码

```python3
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        if n == 1:
            return 0
        direct_sub = self.buildTree(headID, n, manager)
        # print(direct_sub)
        total_time = self.bfs(headID, informTime, direct_sub)
        return total_time


    def buildTree(self, headID, n, manager):
        direct_sub = [[] for i in range(n)]
        for i in range(n):
            if i == headID:
                continue
            direct_sub[manager[i]].append(i)
        return direct_sub
    
    def bfs(self, headID, informTime, direct_sub):
        temp_level = [(headID, 0)]
        total_time = 0
        while temp_level:
            # print(temp_level)
            next_level = []
            for item, pre_time in temp_level:
                total_time = max(total_time, pre_time)
                for sub in direct_sub[item]:
                    next_level.append((sub, informTime[item] + pre_time))
            temp_level = next_level
        return total_time
```