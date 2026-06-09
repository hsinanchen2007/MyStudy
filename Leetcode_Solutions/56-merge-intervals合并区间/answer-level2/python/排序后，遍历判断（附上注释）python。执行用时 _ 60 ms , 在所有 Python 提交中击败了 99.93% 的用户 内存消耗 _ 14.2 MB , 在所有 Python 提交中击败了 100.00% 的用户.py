```
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        # 原始思想：排序后，从第一个区间的右边点开始与下一个的区间的左边点比较判断是否重叠
        # 重叠了就将当前区间的左点与下一个元素的右边组合成新的区间
        # 不重叠 就将两个区间看作不同的两个区间
        
        # 特殊情况
        size=len(intervals)
        if size<2:
            return intervals
        res=[]
        intervals.sort()
        left=intervals[0][0]
        right=intervals[0][1]
        
        for i in range(1,size):
            # 重叠
            # if  (intervals[i][0]<=left and intervals[i][1]>=left) or left<=intervals[i][0]<=right:
            if intervals[i][0] <= right:
                # 改变left 无需判断
                # if intervals[i][0]<left:
                    # left=intervals[i][0]
                # 改变right
                if intervals[i][1]>right:
                    right=intervals[i][1]
            # 不重叠 
            else:
                res.append([left,right])
                left=intervals[i][0]
                right=intervals[i][1]
        res.append([left,right])
        return res
        
        
                                
```
