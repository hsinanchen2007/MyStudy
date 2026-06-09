### 解题思路
借鉴了别人的写法，包含了自己看书的一些个人理解吧
审题：本质上就是一个求一个带权树的最大路径

最关键的就是
>1.建立manager-->员工的映射关系或者有向图，方便后面的无论loop还是recursion
>2.自顶而下递归比较简单，自己写循环就必须手动管理保存,当前节点（无论底部还是顶部出发)走过的路径长度。stack里可以通过元组来存储当前节点以及当前节点到根节点长度stack.append((member, cost + informTime[member]))--我感觉就是这里卡住了，想不出来怎么去做这个iteration

***三种思路***
1. 自底而上，从叶子节点开始最简单，不用建上:下的映射关系，manager包含这种下:上的映射关系，但是重复运算比较多耗时比较长4996 ms
1. 用递归这个自己想出来的，就是写一个最简单递归函数求任意一个节点到叶结点最长加权路径， 836 ms,加了个缓存 提速了一点784 ms
1. 自顶而下使用栈或者队列来做，关键是要记录什么可以是当然最简单的是保留一个变量，每走完路径就比较一下，最后返回这个最大值或者每个节点通知花费的时间返回所有几点的最大值 简单数据结构速度更快，列表队尾操作（pop）明显更快使用queue耗时5，6倍 

### 代码

```python3 
# 4996ms 
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        res = 0
        for i, v in enumerate(informTime):
            if v == 0:
                tem = 0
                while i != -1:
                    tem += informTime[i]
                    i = manager[i]
                res = max(res, tem)
        return res
```

```python3 
# 784ms
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        from collections import defaultdict
        from functools import lru_cache
        d = defaultdict(list)
        for i, v in enumerate(manager):
            d[v].append(i)
        @lru_cache(64)
        def rec(index):
            cost = informTime[index]
            if cost == 0:
                return 0
            return cost + max(map(rec, d[index]))
        return rec(headID)
```
```python3 
# 460ms
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        from collections import defaultdict
        d = defaultdict(list)
        for i, v in enumerate(manager):
            d[v].append(i)
        stack = []
        stack.append((headID, informTime[headID]))
        max_cost = 0
        while stack:
            id_num, cost = stack.pop()
            if informTime[id_num]==0:
                max_cost = max(max_cost,cost)
            for member in d[id_num]:
                stack.append((member, cost + informTime[member]))
        return max_cost
```
