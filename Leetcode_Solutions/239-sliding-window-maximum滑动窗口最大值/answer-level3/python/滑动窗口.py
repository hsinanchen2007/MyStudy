### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        j = 0
        temp_arr = []
        res = []
        while j<=len(nums):
            if len(temp_arr)<k:
                temp_arr.append(nums[j])
                j+=1
            elif len(temp_arr)==k:
                res.append(max(temp_arr))
                if j == len(nums):
                    break
                temp_arr.append(nums[j])
                j+=1
            else:
                temp_arr.pop(0)
        return res 

```