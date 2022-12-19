### 解题思路
直接根据题意分析
如果n内有一个数i不在列表中
输出i

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        for i in range(0,len(nums)+1):
            if i not in nums:
                return i
```