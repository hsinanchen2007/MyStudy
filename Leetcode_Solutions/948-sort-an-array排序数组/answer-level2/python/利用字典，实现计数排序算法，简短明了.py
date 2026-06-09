### 解题思路
见代码

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        dic, j = collections.Counter(nums), -50000

        for i in range(len(nums)):
            while dic.get(j, 0) == 0:
                j += 1
            nums[i] = j
            dic[j] -= 1
        
        return nums

```