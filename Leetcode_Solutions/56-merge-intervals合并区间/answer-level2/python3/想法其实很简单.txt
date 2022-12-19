### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/562f7bdbd945098eec088ef8b00d925e6a17d28b53b4089d6e4ecf74a504fd60-image.png)

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1:
            return intervals
        intervals.sort()
        left = 0
        right = len(intervals)-1
        res = []
        new = intervals[left]
        while left < right:
            if new[1] >= intervals[left+1][0]:
                new = [min(new[0],intervals[left+1][0]),max(new[1],intervals[left+1][1])]
                left = left + 1
            else:
                res.append(new)
                left += 1
                new = intervals[left]
                
        res.append(new)
        return res
```