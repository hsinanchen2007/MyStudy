### 解题思路


一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

实质是动态规划  dp 问题 
从后往前搞


### 代码

```python
class Solution(object):
    def __init__(self):
        self.arr = [0 for _ in range(1000)]


    def getmax(self,nums):
        self.arr[len(nums)-1] = nums[-1]
        self.arr[len(nums)-2] = nums[-2]
        self.arr[len(nums)-3] = nums[-3]+ nums[-1]
        for index in range(len(nums)-3,-1,-1):
            # print('self.arr',self.arr)
            if self.arr[index] !=0:
                continue
            else:
                self.arr[index] = nums[index]+max(self.arr[index+2],self.arr[index+3])
        
    def massage(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0],nums[1])    
        if len(nums) == 3:
            return max(nums[0]+nums[2],nums[1])
        
        self.getmax(nums)

        return max(self.arr[0],self.arr[1])

```