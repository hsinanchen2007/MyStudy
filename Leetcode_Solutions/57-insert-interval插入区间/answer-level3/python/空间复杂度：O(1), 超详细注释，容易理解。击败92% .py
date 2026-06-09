超详细注释，容易理解。击败92% 直接使用上一题的方法，要从头遍历，且要用新的数组保存，浪费时间空间复杂度。 根据本题已经知道确切插入的index的特点，直接从index向左向右合并。 并且不立即插入，而是更新好新的下界和上界之后，最后分情况讨论，统一在原数组进行修改。 效率更高，思路简单。
时间复杂度：O(N)
空间复杂度：O(1)
```
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        #首先二分查找到index。
        #往左往右判断要不要合并。
        #要合并的index删除，插入。
        index = self.binsearch(intervals,newInterval)
        #先插入，后合并。
        #合并的过程就跟上一题一样了。
        #但是这样是要重新从头扫描，比较浪费时间空间，这里应该可以利用index已经知道，进行改进。
        #由题意可以推导出，向左最多合并一个，向右，只要新区间的右值足够大，可以合并无限个。
        #先看向左合并。
        flagleft = 0
        L,R = newInterval[0],newInterval[1]
        if index-1>=0 and intervals[index-1][1]>=L:
            #合并新区间和左边的区间
            flagleft = 1
            L = intervals[index-1][0]
            R = max(intervals[index-1][1],R)
        #这里可以做一个判断，如果进行了合并并且左边合并的右区间为index-1的右值，那么说明R<r1,而r1肯定小于r2，所以新区间和其右边的区间不可能合并
        if flagleft==1 and R!=newInterval[1]: 
            intervals[index-1]=[L,R] 
            return intervals
        
        #接下来考虑向右合并
        #更新R值
        flagright = 0
        i = index
        while i<=len(intervals)-1 and R>=intervals[i][0]:
            flagright = 1
            R = max(intervals[i][1],R)
            i+=1
        #这是i是指向的合并之后的下一个区间

        #最后进行删减替换。
        #如果左右都没有进行合并，直接插入在index处
        # if flagright==0 and flagleft==0:
        #     intervals.insert(index,newInterval)

        # elif flagleft==0 and flagright==1:
        #     #删除index:i
        #     #在index处插入新区间
        #     for i in range(index,i):
        #         del intervals[i]
        #     intervals.insert(index,newInterval)
        #写到这里发现这两种情况可以合并，所以优化一下代码
        if flagleft==0:
            for j in range(i-1,index-1,-1):
                del intervals[j]
            intervals.insert(index,[L,R])

        #左边合并了的两种情况的代码也可以合并
        else:
            intervals[index-1]=[L,R] 
            #删除要从后往前删，不然每删一个，数组的长度也变了。逻辑不对
            for j in range(i-1,index-1,-1):
                del intervals[j]         

        return intervals
        




    #如果有相等的，返回那个相等的index
    #如果没有相等的，返回比target大的index
    def binsearch(self,intervals,newInterval):
        i,j = 0,len(intervals)-1
        target = newInterval[0]

        while i<=j:
            mid = (i+j)//2
            if intervals[mid][0]==target:
                return mid
            if intervals[mid][0]<target:
                i = mid+1
            else:
                j = mid-1
            
        return i
```
