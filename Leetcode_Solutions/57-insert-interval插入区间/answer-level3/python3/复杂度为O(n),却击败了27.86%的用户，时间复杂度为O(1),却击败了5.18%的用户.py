![图片.png](https://pic.leetcode-cn.com/7f2c7bf409a6efa676549c48afee0f00e8bd0eeb4ed09c529f480ac084064ef4-%E5%9B%BE%E7%89%87.png)
先上图。
我的思路是这样的，
1、进行边界检测，就是排除为空的可能行
2、从左开始遍历，根据该不等式找到i，i < n and intervals[i][0] < newInterval[0]
3、从右边开始遍历，根据该不等式找到j，j >= 0 and intervals[j][1] > newInterval[1]
这样就找到了newIntervals的合适的插入点，然后插入，最后结果，将其拼接即可。
另外找到插入点后，还需要判断一下。代码中有详细解释。
```
def insert(intervals: List[List[int]],
           newInterval: List[int]) -> List[List[int]]:
    n = len(intervals)
    if not newInterval:
        return intervals
    if n==0:
        return newInterval
    i, j = 0, n - 1
    while i < n and intervals[i][0] < newInterval[0]:
        i += 1
    while j >= 0 and intervals[j][1] > newInterval[1]:
        j -= 1
    start = newInterval[0]
    end = newInterval[1]
    #对中间需要合并的数组进行处理
    if i > 0:
        if intervals[i - 1][1] >= start:
            i -= 1
            start = intervals[i][0]

    if j < n - 1:
        if intervals[j + 1][0] <= end:
            j += 1
            end = intervals[j][1]
    return intervals[0:i] + [[start, end]] + intervals[j + 1:]
```
