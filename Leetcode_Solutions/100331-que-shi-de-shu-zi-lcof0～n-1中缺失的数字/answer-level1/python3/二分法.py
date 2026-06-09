- 终止条件 二分法 nums[left]>left   nums[right]==right
```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        # return int(n*(n+1)/2) - sum(nums)
        left = 0
        right = n-1
        while left<=right:
            # print(left,right)
            # 终止条件：nums[left] > left 说明left缺失
            # nums[right]应该==right+1 ==的话说明不缺失right+1
            if nums[left] > left:
                return left
            if nums[right] == right:
                return right+1
            mid = (left+right)//2
            if nums[mid]==mid:
                left = mid+1
            else:
                right = mid
```
