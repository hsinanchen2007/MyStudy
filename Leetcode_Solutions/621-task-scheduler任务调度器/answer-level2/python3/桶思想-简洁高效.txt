#### 解题思路：

我们设计桶的大小为 `n+1`，则相同的任务恰好不能放入同一个桶，最密也只能放入相邻的桶。

对于重复的任务，我们只能将每个都放入不同的桶中，因此桶的个数就是重复次数最多的任务的个数。

一个桶不管是否放满，其占用的时间均为 `n+1`，这是因为后面桶里的任务需要等待冷却时间。最后一个桶是个特例，由于其后没有其他任务需等待，所以占用的时间为桶中的任务个数。

最终我们得到：

`总排队时间 = (桶个数 - 1) * (n + 1) + 最后一桶的任务数`

最后，当任务重复率很低时，计算得到的桶个数很少。但由于任务很多，可能出现桶不够用的情况。此时可以假想在最后一桶之后又补充了很多个桶，且所有的桶均装满，因此任务的总等待时间即为任务的总个数。

#### 代码：

```python [-Python]

from collections import Counter

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        ct = Counter(tasks)
        nbucket = ct.most_common(1)[0][1]
        last_bucket_size = list(ct.values()).count(nbucket)
        res = (nbucket - 1) * (n + 1) + last_bucket_size
        return max(res, len(tasks))
```
