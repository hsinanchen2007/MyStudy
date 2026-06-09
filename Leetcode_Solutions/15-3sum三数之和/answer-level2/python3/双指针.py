### 解题思路
这道题如果先取中间的数字，再用双指针去求解的话，去重的部分会很难做。本想着可以简单粗暴地用set来去重，发现list是无法hash的。但是如果先取小数，两个大数再用双指针去做的话，就比较好做了，小数往右边挪的时候，跳过相同的数字即可。

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        nums_len = len(nums)
        answer = []
        for i in range(0, nums_len - 2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j = i + 1
            k = nums_len - 1
            while j < k:
                total = nums[i] + nums[j] + nums[k]
                if total == 0:
                    answer.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
                    while j < k and nums[k] == nums[k+1]:
                        k -= 1
                elif total > 0:
                    k -= 1
                    while j < k and nums[k] == nums[k+1]:
                        k -= 1
                else:
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
        return answer

```