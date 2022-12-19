### 解题思路
区间位置关系包括三种情况：交叉、包含和相离，如下图所示：（图片来自官方题解）
![图片来自本题官方题解](https://pic.leetcode-cn.com/46587347a049564342a7b0172145248a258e52f43c8161daf0ff84a52694684c-%E6%97%A0%E9%87%8D%E5%8F%A0%E5%8C%BA%E9%97%B4.png)
首先，对区间按照起始位置进行排序，然后顺序遍历区间，当前区间记为`cur`，下一个区间记为`next_`。如果不重叠就继续遍历；如果重叠，就删除尾巴比较大的区间。

1. 如果`cur`的尾巴在`next_`的头前面，不重叠，继续遍历
2. 如果`cur`的尾巴在`next_`区间内，删除`next_`区间
3. 如果`cur`的尾巴在`next_`尾巴后面，删除`cur`区间

### 代码

```python3
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:[x[0], -x[1]])
        cur, next_ = 0, 1
        count = 0
        while next_ < len(intervals):
            if intervals[cur][1] <= intervals[next_][0]:
                cur, next_ = next_, next_+1
                continue
            elif intervals[cur][1] > intervals[next_][0] and intervals[cur][1] < intervals[next_][1]:
                count += 1
                del intervals[next_]
                continue
            elif intervals[cur][1] >= intervals[next_][1]:
                count += 1
                del intervals[cur]
                continue
        return count

```