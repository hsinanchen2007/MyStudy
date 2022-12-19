### 解题思路
官方代码，优雅简洁，这里给二维数组排序的技巧，学到了。

### 代码

```python3
class Solution:
    def merge(self, intervals):
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