### 解题思路
1、该题类似于26题
2、倒序遍历list，遇到等于val的就删除
3、返回最终list长度
注意坑：之前写的range(len(nums)-1, 0, -1)，删除不了第一个元素，故改成下边这种形式。

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if len(nums) == 0:
            return 0
        for i in range(len(nums), 0, -1):
            if nums[i-1] == val:
                nums.pop(i-1)
        return len(nums)
```