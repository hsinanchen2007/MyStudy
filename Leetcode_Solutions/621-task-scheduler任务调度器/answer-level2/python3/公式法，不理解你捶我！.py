### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        """
        思路：贪心策略，我们先找出出现次数最多的任务记为MT(其出现次数为p)。可以想想，如果想要尽可能短的任务时间，我们
        要把这最多的任务先安排上，然后把其他任务安排在两个任务MT之间（这段时间我称为冷却时间）。这个时候我们可以算出
        总冷却时间为(p-1)*n，但任务MT本身执行也要占时间，所花时间为p，所以公式为(p-1)*n + p。但有个问题，如果有好几
        个任务（假设有m个）和任务MT出现的次数一样多（比如题目中描述的A和B任务一样多），这个时候这m个任务肯定是
        逐一排在任务MT之后的(换句话说，最后一个任务MT执行完后还有任务[t_1,t_2,...,t_m]需要执行)，所以需要把这
        段执行时间加起来，最后的公式为 (p-1)*n + p + m
        """
        if len(tasks) <= 1:
            return len(tasks)
        task_map = defaultdict(int)
        for task in tasks:
            task_map[task] += 1
        st = sorted(task_map.items(), key=lambda x: x[1], reverse=True) # 从大到小排序
        # 选择出现次数最多的任务
        max_task = st[0][1]
        # 公式为（p-1)*n + p
        res = (max_task - 1) * n + max_task
        for it in st[1:]:
            if max_task == it[1]:
                res += 1
        return max(res,len(tasks))
            
        
```