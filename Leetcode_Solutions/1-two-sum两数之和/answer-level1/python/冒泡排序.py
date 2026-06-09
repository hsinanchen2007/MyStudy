### 解题思路
此处撰写解题思路
使用了冒泡排序，第一个和之后的每一个作比较，第二次轮训第二个和之后的作比较，这样下去就可以两两比较，得到想要的结果
### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums)-1):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
```