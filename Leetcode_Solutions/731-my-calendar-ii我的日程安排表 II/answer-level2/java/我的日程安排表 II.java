####  方法一：暴力法
维护一重预订列表和双重预订列表。当预订一个新的日程安排 `[start, end)` 时，如果它与双重预订列表冲突，则会产生三重预定。

**算法：**
- 当且仅当事件 `[s1, e1)` 在另一个事件` [s2, e2)` 结束后开始，两个事件不冲突，也就是说满足 `e1<=s2` 或 `e2<=s1` 时，两个事件不冲突。这意味着当 `s1<e2` 和 `s2<e1` 时，事件发生冲突。
- 如果新的日程安排与双重预订冲突，则返回 `false`。否则，我们会将与一重预定列表冲突的时间添加到双重预订列表中，并将该预定添加到一重预定列表中。

```Python [ ]
class MyCalendarTwo:
    def __init__(self):
        self.calendar = []
        self.overlaps = []

    def book(self, start, end):
        for i, j in self.overlaps:
            if start < j and end > i:
                return False
        for i, j in self.calendar:
            if start < j and end > i:
                self.overlaps.append((max(start, i), min(end, j)))
        self.calendar.append((start, end))
        return True
```

```Java  [ ]
public class MyCalendarTwo {
    List<int[]> calendar;
    List<int[]> overlaps;

    MyCalendarTwo() {
        calendar = new ArrayList();
    }

    public boolean book(int start, int end) {
        for (int[] iv: overlaps) {
            if (iv[0] < end && start < iv[1]) return false;
        }
        for (int[] iv: calendar) {
            if (iv[0] < end && start < iv[1])
                overlaps.add(new int[]{Math.max(start, iv[0]), Math.min(end, iv[1])});
        }
        calendar.add(new int[]{start, end});
        return true;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$。$N$ 指的是日程安排的数量。对于每个新的日程安排，我们会遍历已预定的每个日程安排，以决定是否可以预订新的日程安排。这需要 $\sum_k^N O(k) = O(N^2)$ 的时间。
* 空间复杂度：$O(N)$，`calendar` 所使用的空间。


####  方法二：边界计数
**算法：**
- 当我们预定一个新的日程安排 `[start, end)`，则执行 `delta[start]++` 和 `delta[end]--`。其中 `delta` 是按照 `key` 值从小到大排序的结构，我们用 `active` 来记录当前正在进行的日程安排数，当 `active>=3` 时，说明产生了三重预定。
- 此方法不包括 python 实现，因为没有 TreeMap。
```Java [ ]
class MyCalendarTwo {
    TreeMap<Integer, Integer> delta;

    public MyCalendarTwo() {
        delta = new TreeMap();
    }

    public boolean book(int start, int end) {
        delta.put(start, delta.getOrDefault(start, 0) + 1);
        delta.put(end, delta.getOrDefault(end, 0) - 1);

        int active = 0;
        for (int d: delta.values()) {
            active += d;
            if (active >= 3) {
                delta.put(start, delta.get(start) - 1);
                delta.put(end, delta.get(end) + 1);
                if (delta.get(start) == 0)
                    delta.remove(start);
                return false;
            }
        }
        return true;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$。$N$ 指的是日程安排的数量。对于每个新的日程安排，我们遍历 `delta` 需要 $O(N)$ 的时间
* 空间复杂度：$O(N)$，`delta` 所使用的空间。