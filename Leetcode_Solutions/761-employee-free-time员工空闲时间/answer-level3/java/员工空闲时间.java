####  方法一：事件（扫描线）[通过]
如果某个区间与任一区间重叠，则该区间不会出现在答案中。所以我们可以将问题转换为：给定一组区间，找出所有员工都不包含的区间。

我们可以使用区间问题中的 “事件” 方法。对于每个区间 `[s, e]`，我们可以看作有两个事件：当 `time = s` 时，`balance++`；当 `time = e` 时，`balance--`。我们只关心 `balance == 0` 的区间。

**算法：**

对于每个区间，创建如上所述的两个事件，并对事件进行排序。在事件 `t` 发生的每个事件，如果 `balance == 0`，则说明 `[prev，t]` 是所有员工都不包含的区间，其中 `prev` 是 `t` 的前一个值。

```python [solution1-Python]
class Solution(object):
    def employeeFreeTime(self, avails):
        OPEN, CLOSE = 0, 1

        events = []
        for emp in avails:
            for iv in emp:
                events.append((iv.start, OPEN))
                events.append((iv.end, CLOSE))

        events.sort()
        ans = []
        prev = None
        bal = 0
        for t, cmd in events:
            if bal == 0 and prev is not None:
                ans.append(Interval(prev, t))

            bal += 1 if cmd is OPEN else -1
            prev = t

        return ans
```

```java [solution1-Java]
class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> avails) {
        int OPEN = 0, CLOSE = 1;

        List<int[]> events = new ArrayList();
        for (List<Interval> employee: avails)
            for (Interval iv: employee) {
                events.add(new int[]{iv.start, OPEN});
                events.add(new int[]{iv.end, CLOSE});
            }

        Collections.sort(events, (a, b) -> a[0] != b[0] ? a[0]-b[0] : a[1]-b[1]);
        List<Interval> ans = new ArrayList();

        int prev = -1, bal = 0;
        for (int[] event: events) {
            // event[0] = time, event[1] = command
            if (bal == 0 && prev >= 0)
                ans.add(new Interval(prev, event[0]));
            bal += event[1] == OPEN ? 1 : -1;
            prev = event[0];
        }

        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(C\log C)$，其中 $C$ 是所有员工的区间数。
* 空间复杂度：$O(C)$。



####  方法二：优先队列 [通过]
假设在某个时间段没有员工工作，这个时间段将持续到某个员工要工作时为止。

我们维护员工下一次要工作的数据。当处理完当前工作时，我们为该员工添加下一次的工作。

**算法：**

我们跟踪最新的时间 `anchor`。当我们处理尚未处理的工作时，时间为 `t`，员工 `e_id`，是该员工的第 `e_jx` 个工作。如果 `anchor < t`，则存在一个空闲区间 `Interval(anchor, t)`。

```python [solution2-Python]
class Solution(object):
    def employeeFreeTime(self, avails):
        ans = []
        pq = [(emp[0].start, ei, 0) for ei, emp in enumerate(avails)]
        heapq.heapify(pq)
        anchor = min(iv.start for emp in avails for iv in emp)
        while pq:
            t, e_id, e_jx = heapq.heappop(pq)
            if anchor < t:
                ans.append(Interval(anchor, t))
            anchor = max(anchor, avails[e_id][e_jx].end)
            if e_jx + 1 < len(avails[e_id]):
                heapq.heappush(pq, (avails[e_id][e_jx+1].start, e_id, e_jx+1))

        return ans
```

```java [solution2-Java]
class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> avails) {
        List<Interval> ans = new ArrayList();
        PriorityQueue<Job> pq = new PriorityQueue<Job>((a, b) ->
            avails.get(a.eid).get(a.index).start -
            avails.get(b.eid).get(b.index).start);
        int ei = 0, anchor = Integer.MAX_VALUE;

        for (List<Interval> employee: avails) {
            pq.offer(new Job(ei++, 0));
            anchor = Math.min(anchor, employee.get(0).start);
        }

        while (!pq.isEmpty()) {
            Job job = pq.poll();
            Interval iv = avails.get(job.eid).get(job.index);
            if (anchor < iv.start)
                ans.add(new Interval(anchor, iv.start));
            anchor = Math.max(anchor, iv.end);
            if (++job.index < avails.get(job.eid).size())
                pq.offer(job);
        }

        return ans;
    }
}

class Job {
    int eid, index;
    Job(int e, int i) {
        eid = e;
        index = i;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(C\log N)$，其中 $N$ 是员工的数量，$C$ 是所有员工的区间数，数据堆的最大大小为 $N$，每个 `pop` 和 `push` 操作需要 $O(\log N)$，有 $O(C)$ 个这样的操作。
* 空间复杂度：$O(N)$，使用了一个一维数组 dp。