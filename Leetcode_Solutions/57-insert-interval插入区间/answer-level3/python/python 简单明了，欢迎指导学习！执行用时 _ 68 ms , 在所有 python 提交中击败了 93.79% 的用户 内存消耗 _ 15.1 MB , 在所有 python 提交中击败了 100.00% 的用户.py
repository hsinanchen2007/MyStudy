```
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        # intervals 
        # 无重叠 按照排序
        if not intervals:
            return [newInterval]
        n=len(intervals)
        j=-1
        res=[]
        index=-1
        for i in range(0,n):
            # 无重叠
            if newInterval[0]>intervals[i][1] or newInterval[1]<intervals[i][0]:
                # 重叠之后➡不重叠
                if index!=-1:
                    # 记录重叠结束的位置
                    j=i
                    res.append(newInterval)
                    break
                # 一直没重叠
                else:
                    # newInterval小于intervals[i]一旦出现这种情况 则break
                    if newInterval[1]<intervals[i][0]:
                        res.append(newInterval)
                        j=i
                        break
                    res.append(intervals[i])
                    # newInterval与所有的区间都不重叠 此时的出口操作
                    if i==n-1:
                        res.append(newInterval)
                        j=n
            # newInterval与当前的intervals[i]有重叠
            # 1.包含
            # 2.交叉
            else:
                # 一旦有重叠 记录该位置
                index=i
                # 合成新的插入区间
                newInterval[0]=min(intervals[i][0],newInterval[0])
                newInterval[1]=max(intervals[i][1],newInterval[1])
                # newInterval与最后一个区间仍然重叠 此时的出口操作
                if i==n-1:
                    res.append(newInterval)
                    j=n
        # 将最后有序的区间加入res
        for k in range(j,n):
            res.append(intervals[k])
        return res


```
