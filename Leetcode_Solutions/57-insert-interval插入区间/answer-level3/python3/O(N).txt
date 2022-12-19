设插入区间的左边界和右边界分别是left，right
遍历一遍整个区间，对于当前的区间[s, e]
- 如果e < left, 说明没有插入点，直接把[s, e]放到结果集中
- 如果e >= left, 找到了插入点，更新left为left和s的较小值
- 如果right <= e, 这时候可以插入合并后的区间
    - 需要判断right和s的大小关系
    - 如果right < s, 说明right不在s和e之间
    - right >= s, right在s, e之间


```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        left, right = newInterval
        for i, (s, e) in enumerate(intervals):
            if e < left:
                res.append([s, e])
                continue

            if left <= e:
                left = min(left, s)
            
            if right <= e:
                if right < s:
                    res.append([left, right])
                    res.append([s, e])
                else:
                    res.append([left, e])
                return res + intervals[i+1:]
            
        return res + [[left, right]]
```