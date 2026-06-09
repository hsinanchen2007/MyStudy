### 解题思路
先对列表以区间左端进行排序，然后根据栈的思想每次弹出一个区间与result列表最后一个区间进行对比， 如果重合则合并，否则就将该区间放入result中作为最后一个元素
![批注 2020-01-24 154235.jpg](https://pic.leetcode-cn.com/5b6607e8b982ff6aa1053c11637354f147f301be8fe314692c12e126477d20aa-%E6%89%B9%E6%B3%A8%202020-01-24%20154235.jpg)

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals)==0:
            return []
        if len(intervals) == 1:
            return intervals
        intervals.sort(key=lambda x:x[0])
        result = [intervals[0]]
        for i in range(1, len(intervals)):
            if result[-1][1] >= intervals[i][0]:
                result[-1] = [result[-1][0], max(result[-1][1], intervals[i][1])]
            else:
                result.append(intervals[i])
        return result


```