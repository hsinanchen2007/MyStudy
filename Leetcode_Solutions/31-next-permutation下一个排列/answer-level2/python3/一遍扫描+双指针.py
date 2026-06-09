


## 思路
1. 从右向左找 nums[i] > nums[i-1]
    a) 如果没有找到, 说明已经是最大的序列, 直接对序列进行reverse (比如[3,2,1])
    b) 如果找到说明存在更大的序列(比如:[4, 8, 5, 2, 1]中数字4和8的位置), 按如下操作 
        1. 从nums[i](数字8)的右侧查找比nums[i-1](数字4)大的值里面最小的一个(假如索引为j, 此处应为数字5), 将i-1(数字4)和j(数字5)两个位置的值交换
        2. 因为交换后, nums[i-1](数字5)右侧([8,4,2,1])的值是按从大到小排列的, 所以进行reverse后([5,1,2,4,8])就是我们要的结果

```python
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        L = len(nums)
        for i in range(1, L)[::-1]:
            if nums[i] > nums[i-1]:
                if i == L - 1:
                    nums[i], nums[i-1] = nums[i-1], nums[i]
                    return
                else:
                    # 向右找
                        # 找到<=自己的, 则和它的前一个位置交换
                        # 未找到比自己小的, 则和最后一个交换
                    j = i+1 # 因为i的位置一定比i-1大, 所以从i+1开始找起
                    while j < L:
                        if nums[j] <= nums[i-1]:
                            nums[i-1], nums[j-1] = nums[j-1], nums[i-1]
                            nums[i:] = nums[i:][::-1]
                            return
                        if j == L - 1:
                            nums[i-1], nums[L - 1] = nums[L - 1], nums[i-1]
                            nums[i:] = nums[i:][::-1]
                            return
                        j += 1
        nums.reverse()
```
