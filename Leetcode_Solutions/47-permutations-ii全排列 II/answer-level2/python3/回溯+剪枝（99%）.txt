### 解题思路
![39573cec65dc566ce1107dd985e0761.png](https://pic.leetcode-cn.com/3a2e86b5b7f7f76ff6a062aa071cdc6876ad149a5ce97d2cde8260aa6685d78d-39573cec65dc566ce1107dd985e0761.png)

关键点：相同的数字在同一层只需要处理一次

### 代码

```python3
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)        
        def dfs(tmp,nums):    
            if len(tmp) == n:
                res.append(tmp)
                return
            used = set()
            for i in range(len(nums)):
                if nums[i] in used: # 剪枝，去除重复解
                    continue
                used.add(nums[i])
                dfs(tmp+[nums[i]],nums[:i]+nums[i+1:])    
        dfs([],nums)  
        return res
```