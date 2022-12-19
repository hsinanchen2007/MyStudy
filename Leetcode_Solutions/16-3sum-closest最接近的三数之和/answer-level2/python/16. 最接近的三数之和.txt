### 解题思路
![image.png](https://pic.leetcode-cn.com/77e4adde05a480b50b1c4756e36cd49e201f810b2e04574f4fc01e50b855afb2-image.png)
### 代码

```python
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        if n <= 3: return sum(nums)

        nums.sort()
        
        min_sum = sum(nums[:3])
        if target <= min_sum: return min_sum
        max_sum = sum(nums[-3:])
        if target >= max_sum: return max_sum

        ans = min_sum
        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            L, R = i + 1, n - 1
            while L < R:
                tmp_sum = nums[i] + nums[L] + nums[R]
                if tmp_sum == target: return target
                if abs(target - tmp_sum) < abs(target - ans):
                    ans = tmp_sum
                if tmp_sum > target:
                    # while L < R and nums[R] == nums[R-1]:
                    #     R -= 1
                    R -= 1
                else:
                    # while L < R and nums[L] == nums[L+1]:
                    #     L += 1
                    L += 1
        return ans




```