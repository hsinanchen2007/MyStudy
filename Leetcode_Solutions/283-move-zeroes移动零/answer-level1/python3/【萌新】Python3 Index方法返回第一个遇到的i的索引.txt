### 解题思路
方法：Index方法返回第一个I的索引
遍历nums，找到0，把0弹出，放在最后

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in nums:
            if i==0:
                a=nums.pop(nums.index(i))
                nums.append(a)
        
```