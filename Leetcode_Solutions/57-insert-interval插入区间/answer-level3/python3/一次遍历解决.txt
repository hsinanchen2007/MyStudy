### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        begin, end = newInterval[0], newInterval[-1]

        merged = []
        flag = True
        for interval in intervals:
            if flag and begin <= interval[0]:
                merged.append(newInterval)
                flag = False

            if flag and begin <= interval[-1]:
                merged.append([interval[0], max(interval[-1], end)])
                flag = False

            if flag:
                merged.append(interval)
            else:
                if end < interval[0]:
                    merged.append(interval)
                elif end > interval[-1]:
                    pass
                else:
                    merged[-1][-1] = interval[-1]

        if flag:
            merged.append(newInterval)

        return merged

```