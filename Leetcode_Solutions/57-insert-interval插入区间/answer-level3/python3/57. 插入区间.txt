### 解题思路
把newInterval加入intervals，接下来就是合并区间的事情了，跟上一题代码一致。

### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # 添加新的interval
        intervals.append(newInterval)
        # 按每个区间的左端点升序
        intervals.sort(key=lambda x: x[0])

        merged = []
        for interval in intervals:
            # 第一个区间，或当前区间的左端点比前一个合并区间的右端点大
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
            # 有重合，那就取最大的右端点
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged
```