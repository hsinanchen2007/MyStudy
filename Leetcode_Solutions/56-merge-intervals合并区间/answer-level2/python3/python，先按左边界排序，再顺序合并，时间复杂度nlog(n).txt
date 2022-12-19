注释都在代码里了哈，请参阅
```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        '''
        执行用时 :68 ms, 在所有 Python3 提交中击败了79.04%的用户
        内存消耗 :14.3 MB, 在所有 Python3 提交中击败了100.00%的用户
        '''
        if intervals==None or len(intervals)==0:
            return []
        if len(intervals)==1:
            return intervals
        ans=[]
        #整个算法是nlog(n)的复杂度
        #因为题目没说集合是否有序，所以先按左边界排序
        intervals = sorted(intervals,key=lambda x:x[0])
        for i in range(len(intervals)-1):
            #下一个区间的左边界在当前区间的左边，在上述排序的前提下，这种情况不存在
            if intervals[i][0]>intervals[i+1][0]:
                intervals[i+1][1] =max(intervals[i+1][1],intervals[i][1]) 
            #    下一个区间的左边界和当前区间的左边重合
            elif intervals[i][0]==intervals[i+1][0]:
                intervals[i+1][1] = max(intervals[i][1],intervals[i+1][1])
            #下一个区间的左边界在当前区间内
            elif intervals[i][0]<intervals[i+1][0] and intervals[i][1]>=intervals[i+1][0]:
                intervals[i+1][0] = intervals[i][0]
                intervals[i+1][1] = max(intervals[i+1][1],intervals[i][1])
            #两个区间不重合
            elif intervals[i][1]<intervals[i+1][0]:
                ans.append(intervals[i])
        #补充最后一个
        ans.append(intervals[-1])
        return ans
```
