### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        length = len(nums)
        if length < 4:
            return []

        res = []

        nums.sort()

        i = 0
        while i < length - 3:
            num1 = nums[i]
            target2 = target - num1

            j = i + 1
            while j < length - 2:
                num2 = nums[j]
                target3 = target2 - num2

                m = j + 1
                n = length - 1
                while m < n:
                    if nums[i] + nums[j] + nums[m] + nums[n] < target:
                        m += 1

                    elif nums[i] + nums[j] + nums[m] + nums[n] > target:
                        n -= 1

                    else:
                        res.append([nums[i],nums[j],nums[m],nums[n]])
                        num3 = nums[m]
                        num4 = nums[n]
                        # 去重
                        while m < n and num3 == nums[m]:
                            m += 1
                        while m < n and num4 == nums[n]:
                            n -= 1

                # num2去重
                while j < length - 2 and num2 == nums[j]:
                    j += 1

            # num1去重
            while i < length - 3 and num1 == nums[i]:
                i += 1

        return res

```