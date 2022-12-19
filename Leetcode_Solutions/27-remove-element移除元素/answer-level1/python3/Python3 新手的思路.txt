原地使用List，那我们可以考虑这样一个思路：
    1，如果不等于val就在List后面加入
    2，List反转
    3，hou-yuan
PS:之所以yuan和hou开始是相等的是因为防止[]的出现导致编译错误

```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        yuan=len(nums)
        hou=len(nums)
        for i in range(0,yuan):
            if val!=nums[i]:
                nums.append(nums[i])
        hou=len(nums)
        nums.reverse()
        return (hou-yuan)
```

