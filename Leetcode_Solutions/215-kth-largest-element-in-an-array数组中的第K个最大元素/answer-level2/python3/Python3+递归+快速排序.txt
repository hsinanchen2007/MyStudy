```
from typing import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        #初始化左右两个指针
        start = 0            #首指针
        end = len(nums) - 1  #尾指针
        return self.QuickSelect(nums, k, start, end)

    #快速排序,降序
    def QuickSelect(self,nums: List[int], k: int,start:int ,end:int)->int:
        left = start
        right = end

        if(left < right):
            tmp = nums[left] #默认选取第一个元素为基准元素
            while(left != right):
                #目标降序排列
                #滑动右指针，找到第一个 > tmp 的元素
                while(left < right and nums[right] <= tmp ):
                    right -= 1
                nums[left] = nums[right]
                #滑动左指针，找到第一个 < tmp 的元素
                while(left < right and nums[left] >= tmp ):
                    left += 1
                nums[right] = nums[left]
            #endwhile
            #将基准元摆放到排序位置
            nums[left] = tmp
            #降序中的第k大元素，索引为k-1
            if(k-1==left):
                return nums[left]
            elif( k-1 < left ):
                return self.QuickSelect(nums, k, start, left-1)
            else:
                return self.QuickSelect(nums, k, left+1, end )

        elif(left==right and left == k-1):  #如果数组内只有一个元素
            return nums[left]
```
