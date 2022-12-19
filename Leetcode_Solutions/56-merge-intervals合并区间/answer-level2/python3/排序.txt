![image.png](https://pic.leetcode-cn.com/40fd8236cbf8728155a5bb499f0ce5e4be2d698197d75d743baed1d8f874cd30-image.png)

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda x:x[0])
        res = []
        for temp in intervals:
            if not res or res[-1][1] < temp[0]:
                res.append(temp)
            else:
                res[-1][1] = max(res[-1][1], temp[1])
        return res

```

### WRONG SOLUTION
```
class Solution:
    def merge(self, intervals):
        intervals.sort(key = lambda x:x[0])
        print(intervals)
        res = []
        s, e = 0, 1
        while e < len(intervals):
            e, l, rt = self.temp(intervals, s, e)

            print(e)
            res.append([intervals[s][0], rt])
            e -= 1
            print(res)
        
    def temp(self, intervals, l, r):
        while intervals[l][1] >= intervals[r][0]:
            print(intervals[l][1],intervals[r][0])
            l += 1
            r += 1
        return r, l, intervals[r-1][1]
```