### 解题思路
...就先在前面插个眼。。
### 代码

```python3
class Solution:
    def findMin(self, nums: List[int]) -> int:
        pre = -1
        for item in nums:
            if pre == -1:
                pre = item
            elif pre > item:
                return item
        return nums[0]

```