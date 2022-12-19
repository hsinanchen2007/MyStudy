```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        """
           首先对数据做排序
        """
        nums.sort()
        margin = float("inf")
        left, middle, right = 0, 0, 0
        
        size = len(nums)
        if size < 3:
            return 0

        for k in range(size - 2):
            if k > 0 and nums[k] == nums[k-1]:
                continue

            i, j = k+1, size-1

            while i < j:
                tmp_res = nums[k] + nums[i] + nums[j]
                if abs(tmp_res-target) < margin:
                    left, middle, right = k, i, j
                    margin = abs(tmp_res-target)
                if tmp_res-target < 0:
                    i += 1
                    while i < j and nums[i] == nums[i-1]:
                        i += 1
                elif tmp_res-target == 0:
                    left, middle, right = k, i, j
                    break
                else:
                    j -= 1
                    while i < j and nums[j] == nums[j+1]:
                        j -= 1

                
        return nums[left] + nums[middle] + nums[right]
```
