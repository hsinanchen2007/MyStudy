刚写的时候没看到不能修改原数组。。不好意思

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if nums[i] == i + 1:
                continue

            # 如果num[i] != i + 1，说明数字不在对应的位置上。
            # 按照抽屉理论，如果没有重复的数的话，每个数nums[i]=i+1（数的范围是1-n嘛）
            # 如果有重复，那么势必两个数字会占到同一个坑位
            while nums[i] != i + 1:
                # 如果当前nums[i]和它应该去的坑位上的数nums[nums[i] - 1]相等，说明就找到这个数了
                if nums[i] == nums[nums[i] - 1]:
                    return nums[i]

                # 不然，直接交换两个数的位置，继续让数字归位
                nxt, tmp = nums[i] - 1, nums[i]
                nums[i], nums[nxt] = nums[nxt], tmp
```
均摊时间复杂度是O(n)，理论上比官方那个龟兔的更优一点