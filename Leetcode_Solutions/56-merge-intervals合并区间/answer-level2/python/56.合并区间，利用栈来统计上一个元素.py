### 解题思路
根据题意，先对基本intervals进行排序，可以发现只需要两个相邻的元素比较是否重合，因为如果intervals[0]与intervals[1]不重合那么intervals[0]与后续的都不可能重合，假设元素是n个，那么最多比较n-1次，用堆栈记录上一个元素或者重合的元素，具体流程如下：
先把intervals第一个元素弹出入栈stack，intervals中还有n-1个元素
stack[-1]（最后一个元素）和intervals.pop(0)（第一个元素比较），如果不重合，就将intervals中的元素压入stack，如果重合弹出stack最顶上元素，计算新的融合区间，再压入stack。
按照这种思路，反复从intervals弹出第一个元素和stack最顶上的元素比较，直到intervals为空
### 代码

```python
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        #其实考察的也是检索数组的 对素组排序的过程
        if not intervals:
            return intervals
        intervals.sort() #把原数组排序 
        stack=[]
        stack.append(intervals.pop(0))
        while intervals:
            item=stack.pop()
            item2=intervals.pop(0)
            if item[1]<item2[0]:#不相交
                stack.append(item)
                stack.append(item2)

            else:
                last=max(item[1],item2[1])
                stack.append([item[0],last])
        return stack



                 





```