### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        flag = 0
        if len(nums) == 0:
            return flag
        for i in range(1,n):
            if nums[i] != nums[flag]:
                flag += 1
                nums[flag] = nums[i]
        return flag+1
```
答案是列表，返回是int型我困惑了很久后来发现是系统会处理，只用求列表个数就好了
flag加1是以为flag从0开始