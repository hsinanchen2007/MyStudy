
![截屏2020-02-22下午3.23.18.png](https://pic.leetcode-cn.com/886c638308a21c958a14dafd3e55c6334872cf677fe7b4c736676dab9976f0fc-%E6%88%AA%E5%B1%8F2020-02-22%E4%B8%8B%E5%8D%883.23.18.png)
### 解题思路
遍历每个interval
选下个interval的开头和现有interval结尾比较，如果符合条件就合并

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        n = len(intervals)
        if n == 0:
            return []
        if n == 1:
            return intervals
        intervals.sort()
        res =[]
        tmp_start = intervals[0][0]
        tmp_end = intervals[0][1]
        for index in range(n-1):
            cur_left = intervals[index][0]
            cur_right = intervals[index][1]
            next_left = intervals[index + 1][0]
            next_right = intervals[index + 1][1]
            if next_left <= tmp_end:
                tmp_start = min(cur_left,tmp_start,next_left)
                tmp_end = max(cur_right,next_right,tmp_end)
            else:
                res.append([tmp_start,tmp_end])
                tmp_start = next_left
                tmp_end = next_right
        res.append([tmp_start,tmp_end])
        return res
```