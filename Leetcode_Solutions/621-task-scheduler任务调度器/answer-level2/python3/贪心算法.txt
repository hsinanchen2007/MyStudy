解法：首先找到完成次数最多的任务，完成这个任务需要时间为 (count - 1) * (n + 1) + 1，接着找到相同任务次数（count）的其他任务，每个任务+1。但是有个意外情况，会导致任务总时间小于数组长度，例如（任务种类-1）> n, [A,A,B,B,C,C,D], n=2，这时可以依次完成任务 ABCDABC。
```
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        if not tasks:
            return 0
        dict1 = {}
        for i in tasks:
            dict1[i] = dict1.get(i, 0) + 1
        min_time = 0
        max_task = max(dict1, key=dict1.get)
        # 完成次数最多的任务需要的任务时间为 (count - 1) * (n + 1) + 1
        min_time = (dict1[max_task] - 1) * (n + 1) + 1
        for k, v in dict1.items():
            # 找到相同任务次数的其他任务
            if v == dict1[max_task] and k != max_task:
                min_time += 1
        # 任务总时间必须大于数组长度，如果 任务种类-1>n，说明可以直接依次完成任务，例如ABCDABC
        if min_time < len(tasks):
            min_time = len(tasks)
        return min_time
```
