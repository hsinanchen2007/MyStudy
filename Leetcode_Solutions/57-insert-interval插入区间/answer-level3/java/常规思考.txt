## 思路:

先考虑三种极端情况

1. `intervals`为空
2. `newInterval[1] < intervals[0][0]`,直接插入第一个位置
3. `newInterval[0] > intervals[-1][1]`,直接插入最后一个位置

下面就要考虑重叠情况了

我们目标就是找到和`newInterval`相关那几个区间.

首先,左边,当`newInterval[0] > intervals[i][1]`说明没有和该区间没有重叠部分,继续遍历下一个区间,比如`intervals = [[1,3],[6,9]], newInterval = [2,5]`

然后,再看右边,这里有个情况,就是 当`intervals[i][0] > newInterval[1]`说明`newInterval`没有和任何区间重合,比如`intervals = [[1,3],[6,9]], newInterval = [4,5]`,直接插入即可.

接下来我们要找右边重合区域,当`while i < n and newInterval[1] >= intervals[i][0]`说明有重叠部分,记录左边最大值!

最后把数组拼接一下即可!

上面就是我们思考过程,

接下来我们可以把过程简化,直接看代码,很好理解的

------


## 代码:

复杂版:

```python
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals: return [newInterval]
        if newInterval[1] < intervals[0][0]: return [newInterval] + intervals
        if newInterval[0] > intervals[-1][1]: return intervals + [newInterval]
        i = 0
        n = len(intervals)
        while i < n and newInterval[0] > intervals[i][1]:
            i += 1
        left = min(intervals[i][0], newInterval[0])
        tmp = i
        if intervals[i][0] > newInterval[1]:
            return intervals[:tmp] + [newInterval] + intervals[tmp:]
        #print(tmp)
        right = newInterval[1]
        while i < n and newInterval[1] >= intervals[i][0]:
            right = max(right, intervals[i][1])
            i += 1
        #print(i)
        return intervals[:tmp] + [[left, right]] + intervals[i:]
```

简化版
```python [2]
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        i = 0 
        n = len(intervals)
        res = []
        # 找左边重合区域
        while i < n and newInterval[0] > intervals[i][1]:
            res.append(intervals[i])
            i += 1
        tmp = [newInterval[0], newInterval[1]]
        # 找右边重合区域
        while i < n and newInterval[1] >= intervals[i][0]:
            tmp[0] = min(tmp[0], intervals[i][0])
            tmp[1] = max(tmp[1], intervals[i][1])
            i += 1
        res.append(tmp)
        while i < n :
            res.append(intervals[i])
            i += 1
        return res
```


```java [2]
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
       List<int[]> res = new ArrayList<>();
        int i = 0;
        while (i < intervals.length && newInterval[0] > intervals[i][1]) {
            res.add(intervals[i]);
            i++;
        }
        int[] tmp = new int[]{newInterval[0], newInterval[1]};
        while (i < intervals.length && newInterval[1] >= intervals[i][0]) {
            tmp[0] = Math.min(tmp[0], intervals[i][0]);
            tmp[1] = Math.max(tmp[1], intervals[i][1]);
            i++;
        }
        res.add(tmp);
        while (i < intervals.length) {
            res.add(intervals[i]);
            i++;
        }
        return res.toArray(new int[0][]); 
    }
}
```

