### 解题思路
单独创建一个0~n的List，然后从0开始遍历，遍历过程中查找当前元素是否出现在nums中，如果没有出现过就返回False

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)+1):
            if i not in nums:
                return i
```