思路
（1）若空余时间大于0，则总时间为任务数+空余时间
（2）空余时间为0，说明不需要额外时间，总时间即任务数
实现
```
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = [0] * 26
        for task in tasks:
            count[ord(task) - ord('A')] += 1
        count.sort(reverse=True)  # 降序
        max_val = count[0] - 1
        res = max_val * n  # 空余时间
        for i in range(1, len(count)):
            if count[i] > 0:
                res -= min(max_val, count[i])  # 其余任务能安排到空余时间段里 空余时间减小
        return res + len(tasks) if res > 0 else len(tasks)
```
