### 解题思路
python区间排序后， 一次遍历即可

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        i = 1
        res = []
        L = len(intervals)
        if L <= 1:
            return intervals
        tempList = sorted(intervals, key=lambda x:x[0])
        # print(tempList)
        headN = tempList[0][0]
        tail = tempList[0][1]
        while i < L:
            if tempList[i][0] <= tail:
                tail = max(tail, tempList[i][1])
            else:
                res.append([headN, tail])
                headN = tempList[i][0]
                tail = tempList[i][1]
            i += 1
        res.append([headN, tail])
        return res
        
```