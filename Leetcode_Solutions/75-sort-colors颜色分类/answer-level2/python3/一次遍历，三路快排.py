### 解题思路
- 三路快排
    - r0 指向左侧第一个不为 0 的位置，即连续 0 的右侧
    - l2 指向右侧第一个不为 2 的位置，即连续 2 的左侧
    - c 指向当前待处理的位置
    - 如果 nums[c] == 2，和 l2 交换
        - 注意，换来的可能是 0 或 1
        - l2 左移
    - 如果 nums[c] == 0，和 r0 交换
        - 如果 r0 和 c 重合，则可能换来的是 0
        - 否则，换来的一定是 1
        - 两种情况，r0 和 c 都需要右移
    - 如果 nums[c] == 1
        - c 右移

### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        思路：
            三路快排
                r0 指向左侧第一个不为 0 的位置，即连续 0 的右侧
                l2 指向右侧第一个不为 2 的位置，即连续 2 的左侧
                c 指向当前待处理的位置
            如果 nums[c] == 2，和 l2 交换
                注意，换来的可能是 0 或 1
                l2 左移
            如果 nums[c] == 0，和 r0 交换
                如果 r0 和 c 重合，则可能换来的是 0
                否则，换来的一定是 1
                两种情况，r0 和 c 都需要右移
            如果 nums[c] == 1
                c 右移
        """
        n = len(nums)
        r0, l2 = 0, n-1
        while r0 < n-1 and nums[r0] == 0:
            r0 += 1
        while l2 >= 0 and nums[l2] == 2:
            l2 -= 1
        c = r0
        while c <= l2:
            if nums[c] == 0:
                nums[c], nums[r0] = nums[r0], nums[c]
                r0 += 1
                c += 1
            elif nums[c] == 2:
                nums[c], nums[l2] = nums[l2], nums[c]
                l2 -= 1
            else:
                c += 1
```