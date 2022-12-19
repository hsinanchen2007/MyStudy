### 解题思路
此处撰写解题思路
[41](https://leetcode-cn.com/problems/first-missing-positive/)   一样的思路，利用索引作为键，nums[i]作为值，自行构建hash来解决。
### 代码

```python3
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        n = len(nums)

        for i in range(n):
            while 1<=nums[i]<=n and nums[i]!=nums[nums[i]-1]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        
        print(nums)
        ans = []
        for i in range(n):
            if i+1!=nums[i]:
                ans.append(nums[i])
        return ans

```