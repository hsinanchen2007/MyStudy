### 解题思路
由于数组是有序的，遍历一遍按照大小原地赋值就好了
留一个值表示当前的最大值的序号i，遇到比当前最大值大的数就给i+1赋值，i+1就变为了最大值，遍历一遍后就达到了去除重复值的目的
最后返回i+1即可，留下数组为空的特殊情况单独处理

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        i = 0
        for item in nums:
            if item > nums[i]:
                nums[i+1] = item
                i += 1
        return i+1
```