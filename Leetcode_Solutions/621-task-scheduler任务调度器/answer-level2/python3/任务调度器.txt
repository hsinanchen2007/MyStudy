### 解题思路
题解的实质是：计算最短时间的逻辑，整理出公式来，然后用程序获取公式中各个数，得出结果。跟队列数据结果没有必然联系。

### 代码

```python3
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        length = len(tasks)
        if length <= 1:
            return length

        dictType = {}
        for task in tasks:
            times = dictType.get(task)
            if times is None:
                dictType[task] = 1
            else:
                dictType[task] += 1
        sortedDict = sorted(dictType.items(),key = lambda x:x[1],reverse = True)

        max_task_count = sortedDict[0][1] # 获取最多次数多任务的次数
        # 至少需要的最短时间
        res = (max_task_count - 1) * (n + 1)
        
        for sort in sortedDict:  # 统计有多少个任务出现的次数是max_task_count
            if sort[1] == max_task_count:
                res += 1
                # res = (max_task_count - 1) * (n + 1) + 出现次数为max_task_count的任务数
        
        # 计算得到的最短时间res和任务数量对比，取更大的数值
        return max(res, length)


# from collections import Counter
# class Solution:  # 作者：hzhu212
#     def leastInterval(self, tasks: List[str], n: int) -> int:
#         ct = Counter(tasks)
#         nbucket = ct.most_common(1)[0][1]
#         last_bucket_size = list(ct.values()).count(nbucket)
#         res = (nbucket - 1) * (n + 1) + last_bucket_size
#         return max(res, len(tasks))




            
```