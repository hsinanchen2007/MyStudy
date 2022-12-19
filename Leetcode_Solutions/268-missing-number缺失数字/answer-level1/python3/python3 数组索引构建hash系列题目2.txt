### 解题思路
此处撰写解题思路
此处撰写解题思路
[41](https://leetcode-cn.com/problems/first-missing-positive/)
[442](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)
[448](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)
同样的都是利用数组索引作为键，来构建hash,均摊复杂度分析。
### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 0<=nums[i]<n and nums[i]!=nums[nums[i]]:
                nums[nums[i]],nums[i]=nums[i],nums[nums[i]]
        
        for i in range(n):
            if nums[i]!=i:
                return i
        return n

```