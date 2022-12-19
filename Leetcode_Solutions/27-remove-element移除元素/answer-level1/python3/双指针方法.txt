### 解题思路
此处撰写解题思路
前后指针遍历，符合条件的就交换两个数字
### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if len(nums)==0:
            return 0
        l = len(nums)-1
        i, j = 0, l
        while i < j:
            while i<=l and nums[i]!=val:
                i+=1
            while j>=0 and nums[j]==val:
                j-=1
            if i >= j:
                break
            nums[i], nums[j] = nums[j], nums[i]
        res = 0
        for n in nums:
            if n == val:
                break
            res += 1
        return res
```