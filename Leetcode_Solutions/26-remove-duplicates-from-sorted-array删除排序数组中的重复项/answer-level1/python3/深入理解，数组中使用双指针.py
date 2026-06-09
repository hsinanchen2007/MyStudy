**思路：由于必须要原地删除，就不考虑用其他数据结构储存。然后可以想到，用指针变量来辅助存储**。

双指针思想：相当于从原地，得到了一个与原数据结构有关联新数据结构。

题目特征和需要注意的地方：
1.输入空列表
如果不加上前提条件，会出现空列表错误
2.给出的是有序列表（？）
无序列表无法用此种方法解题


```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        i = 0
        for j in range(1, len(nums)):
            if nums[i] != nums[j]:
                i += 1
                nums[i] = nums[j]
        return i+1
```


