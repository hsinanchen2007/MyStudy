
### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if len(nums) == len(set(nums)):
            return False

        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    if (j - i) <= k:
                        return True
                else:
                    continue
        return False
        # for i in range(len(nums) - k):
        #     kWin = []
        #     for j in range(i, i + k):
        #         if nums[j] in kWin:
        #             return True
        #         else:
        #             kWin.append(nums[j])
        #             continue
        # return False
```