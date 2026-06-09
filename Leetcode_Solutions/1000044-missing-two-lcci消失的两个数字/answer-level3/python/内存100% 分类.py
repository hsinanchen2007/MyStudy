### 解题思路
建立新的表进行对比

### 代码

```python3
class Solution:
    def missingTwo(self, nums: List[int]) -> List[int]:
        result = []
        if len(nums) != 1:
            list1 = [i for i in range(1,len(nums)+3)]
            nums = sorted(nums)
            nums = nums + [0]*2
            for i in range(len(list1)):
                if list1[i] != nums[i]:
                    nums.insert(i,0)
                    result.append(i+1)
            return result
        else:
            list1 = [1,2,3]
            list1.remove(nums[0])
            return list1
```