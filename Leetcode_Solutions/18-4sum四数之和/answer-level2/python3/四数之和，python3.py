### 解题思路
在三数之和的基础上，加一层循环
在第一层循环内添加限制条件：
```
if nums[start] + 3*nums[start+1] > target: break
if nums[start] + 3*nums[-1] < target: continue
```


### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []
        for start in range(len(nums)-3):
            if nums[start] + 3*nums[start+1] > target: break
            if nums[start] + 3*nums[-1] < target: continue
            if start > 0 and nums[start] == nums[start-1]:continue
            for i in range(start+1, len(nums)-2):
                if i > start+1 and nums[i] == nums[i-1]:continue
                L = i + 1
                R = len(nums) - 1
                while(L<R):
                    if (nums[i]+nums[L]+nums[R]==target-nums[start]):
                        res.append([nums[start], nums[i], nums[L], nums[R]])
                        while(L<R and nums[L]==nums[L+1]):
                            L=L+1
                        while(L<R and nums[R]==nums[R-1]):
                            R=R-1
                        L=L+1
                        R=R-1
                    elif (nums[i]+nums[L]+nums[R])>target-nums[start]:
                        R -= 1
                    else:
                        L += 1
        return res
```