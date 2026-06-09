```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        nums_len = len(nums)
        best_sum, best_dist = 0, float('inf')  # best_sum记录最接近的加和结果，best_dist记录与target的差值
        for i in range(nums_len - 2):
            l, r  = i+1, nums_len-1 
            while l < r:
                tmp_sum = nums[i] + nums[l] + nums[r]
                if abs(target - tmp_sum) < best_dist:  # 如果tmp_sum与target的距离较之前更小，那么更新best_dist与best_sum
                    best_dist, best_sum = abs(target - tmp_sum), tmp_sum
                if tmp_sum < target:  # 小于target需要增加相应值，故l++
                    l += 1
                elif tmp_sum > target:
                    r -= 1
                else:  # 与target相等
                    return target

        return best_sum
```