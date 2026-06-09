### 解题思路
解题思路：
我要找到什么？我要在nums中找到val
1. 如果val在nums中存在，进入循环
2. 找到val在nums中的位置，弹出
3. 重复第一部操作

### 代码

```python3
class Solution:
    def removeElement(self, nums, val):
        while val in nums:
            x = nums.index(val)
            nums.pop(x)
        return len(nums)
```