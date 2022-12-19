### 解题思路
思路是dfs+剪枝。首先将不太适应的manager结构转化为领导->员工的哈希结构，这样就可以看成一棵树了，另外manager元素种类的个数-1是树的层数，可用来剪枝。

### 代码

```python3
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        def dfs(total_time,head,count):
            nonlocal res,length,tree
            if informTime[head]==0:
                res=max(total_time,res)
                return
            for workerID in tree[head]:
                count+=1
                dfs(total_time+informTime[head],workerID,count)
                if count>=length: #剪枝，达到最低层，可以结束dfs
                    return
                else:
                    count-=1
        res = 0
        # 将manager这种从下向上的结构转化为从上向下的结构
        tree = collections.defaultdict(list)
        for i in range(n):
            if manager[i]==-1:
                continue
            tree[manager[i]].append(i)
        length = len(set(manager))-1 #树共有几层
        dfs(0,headID,0)
        return res
```