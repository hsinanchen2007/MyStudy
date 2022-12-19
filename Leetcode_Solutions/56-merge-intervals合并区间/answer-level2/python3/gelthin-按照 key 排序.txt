### 解题思路
参照了官方题解的思路
使用了 python3 的语法 A.sort(key = lambda x: x[0])
这个要记牢。

如果不用此，自己也要会写。定义一个额外的比较函数 cmp (compare) 即可


### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if intervals and len(intervals[0]) == 2:  # [[]] 算非空
            intervals.sort(key=lambda x: x[0])
        merged = []
        for interval in intervals:
            if not merged or merged[-1][-1] < interval[0]:
                merged.append(interval)
            else:
                merged[-1][-1]= max(merged[-1][-1], interval[-1])

        return merged

```