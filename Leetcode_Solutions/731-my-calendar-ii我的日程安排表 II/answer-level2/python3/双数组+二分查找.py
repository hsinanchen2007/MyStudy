
-   双数组记录+二分查找

```
设置两个数组，分别记录出现一次的范围以及出现两次的范围

判断流程：
- 判断当前范围是否在出现2次的数组中有交叉，有交叉则返回False
- 没有交叉
    - 更新出现一次的数组
    - 将在一次数组中重复出现的范围更新在出现两次的数组
```

>    这里为了查询方便，出现一次的范围分别保存了首部和尾部



```python
from bisect import bisect_right


class MyCalendarTwo:

    def __init__(self):
        self.first_starts = []
        self.first_ends = []
        self.second_starts = []
        self.second_ends = []

    def update_first(self, start, end):

        first_index = bisect_right(self.first_starts, end)
        temp_index = first_index - 1
        if first_index == 0 or self.first_ends[temp_index] < start:
            self.first_starts.insert(first_index, start)
            self.first_ends.insert(first_index, end)
        else:
            overlap_left = max(start, self.first_starts[temp_index])
            overlap_right = min(end, self.first_ends[temp_index])
            self.update_second(overlap_left, overlap_right)
            if end > overlap_right:
                self.first_ends[temp_index] = end

            if overlap_left - 1 >= start:
                self.update_first(start, overlap_left - 1)

    def update_second(self, start, end):
        second_index = bisect_right(self.second_starts, end)
        if second_index == 0 or self.second_ends[second_index - 1] < start:
            self.second_starts.insert(second_index, start)
            self.second_ends.insert(second_index, end)
        else:
            if end > self.second_ends[second_index - 1]:
                self.second_ends[second_index - 1] = end

            if start < self.second_starts[second_index - 1]:
                self.update_second(start, self.second_starts[second_index - 1] - 1)

    def book(self, start: int, end: int) -> bool:
        end = end - 1

        second_index = bisect_right(self.second_starts, end)
        if second_index > 0 and self.second_ends[second_index - 1] >= start:
            return False

        first_index = bisect_right(self.first_starts, end)

        if first_index == 0 or self.first_ends[first_index - 1] < start:
            self.first_starts.insert(first_index, start)
            self.first_ends.insert(first_index, end)
        else:
            self.update_first(start, end)

        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# param_1 = obj.book(start,end)
# obj = MyCalendarTwo()

```




