### 解题思路
    流程：
        ①二分查找，确定target的位置
        ②在target的位置，分别向后向前查找其他的target
![下载 (6).png](https://pic.leetcode-cn.com/4995f21e4be491ee519e0ae78e7f4f97f8916a560e7ae5b4fdc9a4e75c4a1a13-%E4%B8%8B%E8%BD%BD%20\(6\).png)



### 代码

```py
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0
        end = len(nums)-1
        start = 0
        times = 0
        while start <= end:                                 #二分查找
            mid = int((end+start)/2)
            if nums[mid] < target :
                start = mid + 1
            elif nums[mid] >  target:
                end = mid - 1
            else:
                times += self.searchbothsides(start,end,mid,target,nums)
                break
        return times

    def searchbothsides(self,start,end,mid,target,nums):
        times = 0
        tem = mid
        if mid == start and mid ==end:                  #处理list的长度为1的情况
            if nums[mid] ==target:
                times +=1
            return times
        while tem<=end and nums[tem] == target:         #向后搜寻其他target
            times += 1
            tem += 1
        while mid > start and nums[mid-1] == target:    #向前搜寻其他target
            times += 1 
            mid -= 1
        return times
```