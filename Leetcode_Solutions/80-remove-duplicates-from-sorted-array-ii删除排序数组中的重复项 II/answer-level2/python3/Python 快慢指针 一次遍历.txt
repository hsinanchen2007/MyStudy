设定快慢指针`slow = 1, fast = 2`
其中`slow` 指向需要更改的位置 `fast`用于遍历数组
如果快指针指向的元素和慢指针的前一个元素相同, 由于数组排好序, 说明慢指针指向的数字也和快指针指向的数字相同, 此时只让快指针向前走, 下一个数组应该填在当前慢指针之后的一个位置

如果快指针指向的元素和慢指针的前一个元素不同, 那么将慢指针向后移动, 将当前快指针指向的元素放到慢指针指向的位置即可. 

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return len(nums)
        slow, fast = 1, 2
        n = len(nums)
        while fast < n:
            if nums[fast] != nums[slow - 1]:
                slow += 1
                # slow 始终指向更改后的位置
                nums[slow] = nums[fast]
            fast += 1
        # 返回的是元素个数, 数组索引 + 1 即可
        return slow + 1
```