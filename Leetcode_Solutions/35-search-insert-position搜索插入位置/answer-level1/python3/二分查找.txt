- - 有序数组，二分查找比较快。
      class Solution:
          def searchInsert(self, nums: List[int], target: int) -> int:
              def two_search(left,right,target,nums):
                  c = 0
                  while left <=right:
                      mid = (left+right) //2
                      if target == nums[mid]:
                          c = 1
                          return mid
                      else:
                          if target > nums[mid]:
                              left = mid + 1
                          else:
                              right = mid - 1
                  if c == 0:
                      if target > nums[right]:
                          return right+1
                      else:
                          if target < nums[left]:
                              if left == 0:
                                  return left
                              else:
                                  return left-1
                          else:
                              if target>(nums[right]+nums[left])/2:
                                  return right
                              else:
                                  return left
              return two_search(0,len(nums)-1,target,nums)
- 不断优化：
      
- 自我分析：
  - 虽然第一反应还是暴力解法，细想一下可以用二分查找法，这样时间复杂度会降低

