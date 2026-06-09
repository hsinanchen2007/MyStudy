目标：在最接近自己startime的endtime里得到最大的proft前缀
1. 维护一个递增的endtime序列
2. 该序列同时记录在此endtime下的最大profit
3. 按递增endtime遍历工作
4. 如果本次工作后profit比更早的endtime下的更多，就把这个工作记进去，不然做个p
5. 因为升序，所以还能二分查找。exciting！
```python
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        # 目标：在最接近自己startime的endtime里得到最大的proft前缀
        # 1. 维护一个递增的endtime序列
        # 2. 该序列同时记录在此endtime下的最大profit
        # 3. 按递增endtime遍历工作
        # 4. 如果本次工作后profit比更早的endtime下的更多，就把这个工作记进去，不然做个p
        # 5. 因为升序，所以还能二分查找。exciting！
        job=sorted(zip(startTime,endTime,profit), key=lambda v:v[1])
        res=[[0,0]]
        for s,e,p in job:
            # bisect对一维数组和二维数组的表现不同，所以s-1.要是分成两个一维数组记录的话就不用减了
            i=bisect.bisect(res, [s+1])-1
            if res[i][1]+p>res[-1][1]:
                res.append([e, res[i][1]+p])
        return res[-1][1]
```