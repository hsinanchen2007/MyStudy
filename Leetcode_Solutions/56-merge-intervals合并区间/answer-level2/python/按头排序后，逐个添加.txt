### 解题思路
(1)对输入区间数组进行排序（**按照头结点排序**）;
(2)首先把排序后的第一个区间加入到result中;
(3)依次判断当前区间的头结点是否比当前result中最后一个区间元素的尾结点大;
(4)如果当前区间的头结点 >= 当前result中最后一个区间的尾结点，说明当前区间**不在**result区间范围内，则把当前区间加入到result中;
(5)如果当前区间的头结点 < 当前result中最后一个区间的尾结点，说明当前区间**在**result区间范围内，这时就需要判断当前区间的尾结点与result区间的尾结点的大小，大则更新result区间的尾结点，否则则说明当前区间完全在result区间范围内，则直接跳过，判断下一个区间范围。

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        result = []
        intervals.sort()
        for interval in intervals:
            if not result or result[-1][1] < interval[0]:
                result.append(interval)
            else:
                result[-1][1] = max(interval[1],result[-1][1])
        return result
```