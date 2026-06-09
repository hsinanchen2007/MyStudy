### 解题思路
思路很直接：直接用count函数得到元素出现次数，返回出现次数不为1的元素
时间复杂度：O(n)

### 代码

```python3
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for i in nums:
            if nums.count(i)!=1:
                return i
            
```