1.首先注意首元素和末元素的左右都默认为0
2.计算列表的和存入一个变量
3.根据问题描述，可以理解为从索引0开始，
找到第一组某索引左边之和的2倍等于
列表和和该索引元素的差，存在跳出遍历
并且返回该索引，否则遍历完列表后返回-1
```
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if len(nums)==0:
            return -1
        p=sum(nums)
        i=0
        s=0
        while i<len(nums):
            if 2*s==p-nums[i]:
                break
            s=s+nums[i]
            i=i+1
        if i==len(nums):
            return -1
        else:
            return i

