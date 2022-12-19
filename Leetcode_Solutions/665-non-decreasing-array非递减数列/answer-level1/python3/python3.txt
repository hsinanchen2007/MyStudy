### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        if len(nums) <= 2:
            return True
        count = 0
        for i in range(len(nums) - 1):
            # 当当前数比后一个数大，就需要调整
            if nums[i] > nums[i + 1]:
                count += 1
                if count == 2:
                    return False
                # 万一前一数比后一个数大，需要后一个数等于当前数
                # 否则当前数等于后一个数即可
                if i >= 1 and nums[i - 1] > nums[i + 1]:
                    nums[i + 1] = nums[i]
                else:
                    nums[i] = nums[i + 1]
        return True
```