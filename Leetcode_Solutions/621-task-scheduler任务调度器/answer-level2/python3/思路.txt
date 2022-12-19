### 解题思路
- 首先，若n足够大，则最大任务量决定最少用时。最后一轮任务之前的用时为(least=(n+1)*(s_most-1))；除数量最大的任务之外，其余任务均可以插入相同任务中的空隙之中，以此达到省时的目的；若有多个最大任务，则需要加上相应的时长，即(least+count)；
- 若n不够大，则即便插满空隙，也无法达到省时的目的，因此此时的最小时长只能为任务数量*执行用时(总有办法使任务完美安排，没有多余的待命时间)；
综上，任务用时为max(longest+count,len(tasks))
### 代码

```python3
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        tops = collections.Counter(tasks)
        most = tops.most_common()
        s_most = most[0][1]
        least = (n+1)*(s_most-1)
        count = 0
        for i in most:
            if i[1] == s_most:
                count += 1
        return max(least+count,len(tasks))


```