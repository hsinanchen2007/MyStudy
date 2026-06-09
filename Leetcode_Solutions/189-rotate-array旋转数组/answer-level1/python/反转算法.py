这里主要是采用一种巧妙的方法

输入：1 2 3 4 5 6 7  , k = 3
首先截断成左边和右边倒数K项得到
     1 2 3 4 | 5 6 7 
然后分别逆转得到：
    4 3 2 1  | 7 6 5
最后整体逆转得到：
    5 6 7 1 2 3 4 

```
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        length = len(nums) 
        k %= length   #避免k 大于长度
        self.reverse(nums,0,length - k -1) 
        self.reverse(nums,length-k,length-1)
        self.reverse(nums,0,length-1)
        
    def reverse(self,nums,start,end):
        for i in range(0,(end-start)/2+1): #这里注意是左闭又开区间，要加1
            tmp = nums[start+i]
            nums[start+i] = nums[end-i]
            nums[end-i] = tmp
            
```
