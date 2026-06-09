### 解题思路
巧妙两次二分法，时间复杂度O(logn)
![捕2获.PNG](https://pic.leetcode-cn.com/401837810a04c3d9e4a6610057797056c30b90c6925f0a968967b57139b307b9-%E6%8D%952%E8%8E%B7.PNG)

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        if target not in nums:
            return -1
        first = 0
        end = len(nums)-1
        
        nums[0]
         #第一次二分法，因为知道发生了反转，利用nums[0]找出发生反转的那个点，也就是最大值和最小值的连接处，这样分割点前后都是升序
        while first<end:
            mid = (first+end)//2

            if nums[0]<=nums[mid]:
                first=mid+1
            else:
                end = mid
            
            if first==end:
                break
        #第二次 0-->分割点
        if target in nums[:first]:
            left =0
            right =len(nums[:first])-1
            while left<=right:
                mid = (left+right)//2
                if target==nums[:first][mid]:
                    return mid
                elif target>nums[:first][mid]:
                    left =mid+1
                else:
                    right = mid-1
        #分割的-->结尾
        if target in nums[first:]:
            
            left =0
            right =len(nums[first:])-1
            while left<=right:
                mid = (left+right)//2
                if target==nums[first:][mid]:
                    return mid+len(nums[:first])
                elif target>nums[first:][mid]:
                    left =mid+1
                else:
                    right = mid-1