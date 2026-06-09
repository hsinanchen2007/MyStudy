//分治的思想
```python []
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        
        if nums is None or len(nums) == 0:
            return 
        low, high = 0, len(nums)-1   #low和high为了定位数组的长度，这两个为不变量
        self.quicksort(nums, low, high)
        return nums
    
    def quicksort(self, nums, low, high):
        if low < high:
            mid = self.Partition(nums, low, high) #返回基准元素的位置
            self.quicksort(nums, low, mid-1)
            self.quicksort(nums, mid+1, high)
                            #partition为划分基准函数
    
    def Partition(self, nums, low, high):
        i,j = low, high
        pivot = nums[low]   #基准元素
        while i<j:
            while i<j and nums[j] > pivot: #向左扫描
                j=j-1
            if i<j:
                nums[i],nums[j] = nums[j] ,nums[i]
                i = i+1
            while i<j and nums[i] <= pivot: #向右扫描
                i = i+1
            if i<j:
                nums[i],nums[j] = nums[j] ,nums[i]
                j = j-1
        return i #返回最终划分完成后基准元素所在的位置  模型为 (比pivot小) i (比pivot大)
#时间复杂度O（nlogn）
            