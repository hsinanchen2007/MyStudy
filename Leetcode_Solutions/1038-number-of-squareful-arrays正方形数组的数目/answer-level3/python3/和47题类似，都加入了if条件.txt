### 解题思路
和47的思路很像，这里需要做的是如果不满足sqrt的要求，就不进入下一个递归函数

### 代码
```python
class Solution:
    def numSquarefulPerms(self, nums: List[int]) -> int:
        if not nums: return []
        res = []
        nums.sort()
        n = len(nums)
        visited = [False]*n
        self.dfs(res, [], visited, nums)
        return len(res)

    def dfs(self, res, unit, visited, nums):
        if len(unit) == len(visited):
            res.append(unit[:])
        else:
            for i in range(len(visited)):
                # 用来去重，当前元素和前一个元素相同时，直接continue
                if i > 0 and nums[i] == nums[i-1] and not visited[i-1]:
                    continue 
                # 当前unit为空，或者不为空时，当前的i和前一个元素unit[i]构成sqrt的要求，并且当前元素未被访问，则递归
                if not unit or math.sqrt(unit[-1]+nums[i])%1==0 and not visited[i]:
                    visited[i] = True
                    self.dfs(res, unit+[nums[i]], visited, nums)
                    visited[i] = False
                # else: #不能提前终止，当前元素nums[i]不满足要求，直接break，会让下一个元素没办法获得
                # [1,17,8] 17breek的话，直接无法尝试8了。导致空值
                #     break
```