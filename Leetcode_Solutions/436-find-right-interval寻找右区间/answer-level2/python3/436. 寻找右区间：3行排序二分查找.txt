首先先把数列把【区间起点坐标，下标】组合起来，按起点坐标大小进行排序；

然后遍历原数列，取出终点坐标，用Python的二分查找函数，在之前排好序的数组里找到能够在左边插入的坐标。

最后输出时，如果插入坐标在末尾就输出-1，其他就正常输出对应的区间对应的数组下标。


```py
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        p = sorted([[j, i] for i, (j, _) in enumerate(intervals)])      
        #【区间起点坐标，下标】组合并排序
        q = [bisect.bisect_left(p, [j, 0]) for _, j in intervals]       
        #用【终点坐标，0】查找可以往左插入的坐标，写成这样是为了对应数组P的形式
        return [(p[i][1] if i < len(intervals) else -1) for i in q]     
        #如果下标没有越界就输出下标，否则输出-1
```

扩写版：

```py
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        p = [[j, i] for i, (j, _) in enumerate(intervals)]
        p.sort()
        q = [bisect.bisect_left(p, [j, 0]) for i, j in intervals]
        return [(p[i][1] if i < n else -1) for i in q]
```
