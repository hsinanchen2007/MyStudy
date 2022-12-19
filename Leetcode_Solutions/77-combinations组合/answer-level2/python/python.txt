### 解题思路
执行速度好慢

### 代码

```python3
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        nums = [i for i in range(1,n+1)]
        def backtrade(nums,temp):
            if len(temp) == k:
                result.append(temp)
                return
            else:
                for i in range(len(nums)):
                    backtrade(nums[i+1:],temp+[nums[i]])
        backtrade(nums,[])
        return result
```