### 解题思路
- 遍历数组，索引i一开始为0；
- 当数字不等于val时，复制到nums的i位置上，i再自增；
- 当数字等于val时，跳过该层循环；
这样，就将数组中不等于val的数，复制到了nums的前i位数中。

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        for j in range(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
            else: 
                continue
        return i



```