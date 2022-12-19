### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 最简单的思路，把从前往后遍历数组，遇到非0 的数，就往前移动，记录好非零的个数，此时出现非0的数据冗余存储
        # 总数-非零的个数即为0的个数，将数组后面的数字强制修改为0即可
        start = 0
        for n in nums:
            if n != 0:
                # 从0开始拷贝后面的，冗余存储
                nums[start] = n
                start += 1
        # 将后面强制修改为0
        for i in range(start, len(nums)):
            nums[i] = 0

```