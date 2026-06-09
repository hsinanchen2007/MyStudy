### 解题思路
用列表记录前面有多少个偶数，找到对应的加一相乘

### 代码

```python3
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        res = 0
        num1 = [0]
        num2 = [0]
        index = 0
        for i in range(len(nums)):
            if nums[i]%2 == 1:
                num1[index] = num1[index] + 1
                index = index + 1
                num1.append(0)
                num2.append(0)
            else:
                num2[index] = num2[index] + 1
        if index < k:
            return 0
        else:
            for i in range(index + 1 - k):
                res = (num2[i] + 1) * (num2[i + k] + 1) + res
            return res
```