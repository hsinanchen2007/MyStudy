![image.png](https://pic.leetcode-cn.com/aa6823bdd3da431c6f8fbeea98172cc0bff28982452b0f32b3b49d071a0b139e-image.png)

### 解题思路
排序后依次添加合并区间子元素

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        if(not intervals):return res
        intervals.sort()
        subint = intervals[0]
        for i in range(1,len(intervals)):
            if(intervals[i][0]<=subint[1]):
                subint[1]=max(intervals[i][1],subint[1])
            else:
                res.append(subint)
                subint = intervals[i]
        res.append(subint)
        return res
```