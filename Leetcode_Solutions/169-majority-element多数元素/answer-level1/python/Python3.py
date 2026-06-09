### 解题思路
1. 出现次数超过一半的数一定是中位数, 使用快速选择法找出多数元素, 但最坏情况O(n^2), 超时
2. 摩尔投票法

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # 1. partition超时
#         def partition(nums, k):
#             pivot = nums[0]
#             l, r = 0, len(nums)-1
#             while l < r:
#                 while l < r and nums[r] >= pivot:
#                     r -= 1
#                 nums[l] = nums[r]
#                 while l < r and nums[l] <= pivot:
#                     l += 1
#                 nums[r] = nums[l]
#             nums[l] = pivot
#             # l为pivot的索引, 同时也表示有l个数比pivot小
#             # 要找第k小的数, pivot为第l+1小的数
#             if l + 1 == k:
#                 return pivot
#             # 第k小的数在右侧, 排除了l+1个数字, 改为找右侧第k-(l+1)小
#             elif l + 1 < k:
#                 return partition(nums[l+1:], k-l-1)
#             # 第k小的数在左侧, 右侧的数字大于k个, 继续在左侧找第k小的数
#             elif l + 1 > k:
#                 return partition(nums[:l], k)

#         if not nums:
#             return None

#         # 出现次数大于n/2, 那么一定是中位数, 即第n//2小的数
#         res = partition(nums, len(nums)//2+1)
#         # 但中位数不一定是出现次数超过n/2的数, 要验证
#         count = 0
#         for num in nums:
#             if num == res:
#                 count += 1
#         return res if count > len(nums)//2 else None
        
        # 2. 投票法
        
        if not nums:
            return None
        res, count = 0, 0
        for i in nums:
            if not count:
                res, count = i, 1
            else:
                if i == res:
                    count += 1
                else:
                    count -= 1
        # 小于等于0一定没有多数元素, 大于0要验证
        if count > 0:
            count = 0
            for i in nums:
                if i == res:
                    count += 1
        return res if count > len(nums) // 2 else -1
        
```