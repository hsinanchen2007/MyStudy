其实思想很简单：
- 计算每个任务出现的次数并根据键值排序
- 计算最少时间，即最多任务出现次数并且刚好间隔冷冻时间 - （最多任务次数-1）*（冷冻时间+1），很好理解：间隔数为最多任务次数减一，每个间隔冷冻时间加该任务执行的一个时间。
- 找出次数同样最多的任务，最少时间变长，取决于序列末尾添加的该任务执行时间，举个例子：       A-冷冻-冷冻-A-冷冻-冷冻-A，最少时间为（3-1）*（2+1）= 6，注意最后一个A会在之后加上
- 遍历每个任务，在最少时间上加上所有任务次数最多的任务数：A-B-冷冻-A-B-冷冻-A-B，6+2=8
- 注意，还未结束，考虑若还有很多次数少于最多次数的任务，此时没有冷冻时间，直接返回数组长度。可以看上一条例子中，剩余的任务可以在冷冻时间随意添加，就不再有冷冻时间。所以比较数组长度与计算出的最少时间，返回较大者。
```
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        mapping = Counter(tasks).most_common()
        max_num = mapping[0][1]
        min_time = (max_num - 1) * (n + 1)
        for task in mapping:
            if task[1] == max_num:
                min_time += 1
        return min_time if min_time >= len(tasks) else len(tasks)
```
参考于[@jalan](/u/jalan/)