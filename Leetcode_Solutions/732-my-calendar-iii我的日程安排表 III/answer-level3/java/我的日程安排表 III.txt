####  方法：边界计数
**算法：**
- 当我们预定一个新的日程安排 `[start, end)`，则执行 `delta[start]++` 和 `delta[end]--`。其中 `delta` 是按照 `key` 值从小到大排序的结构，我们用 `active` 来记录当前正在进行的日程安排数，然后动态记录  `active` 的最大值。
- 在 python 中我们每次对数据进行排序，因为没有 TreeMap。

```Python [ ]
class MyCalendarThree(object):

    def __init__(self):
        self.delta = collections.Counter()

    def book(self, start, end):
        self.delta[start] += 1
        self.delta[end] -= 1

        active = ans = 0
        for x in sorted(self.delta):
            active += self.delta[x]
            if active > ans: ans = active

        return ans

```

```Java [ ]
class MyCalendarThree {
    TreeMap<Integer, Integer> delta;

    public MyCalendarThree() {
        delta = new TreeMap();
    }

    public int book(int start, int end) {
        delta.put(start, delta.getOrDefault(start, 0) + 1);
        delta.put(end, delta.getOrDefault(end, 0) - 1);

        int active = 0, ans = 0;
        for (int d: delta.values()) {
            active += d;
            if (active > ans) ans = active;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$。$N$ 指的是日程安排的数量。对于每个新的日程安排，我们遍历 `delta` 需要 $O(N)$ 的时间，在 python 中，由于额外的排序步骤使时间复杂度是 $O(N^2 \log N)$ 。
* 空间复杂度：$O(N)$，`delta` 所使用的空间。