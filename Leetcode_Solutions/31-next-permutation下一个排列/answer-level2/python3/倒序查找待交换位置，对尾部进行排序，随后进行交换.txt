### 解题思路
首先从列表的倒数第二个数进行查找，判断当前该数尾部列表中是否存在大于当前该数的数。
- 如果存在，那么当前该数即为待交换数；
    - 此时对该数尾部列表进行升序排序，遍历升序排序后的尾部序列，找到大于当前待交换数的最小数，与待交换数进行交换，即可完成程序。   
- 如果不存在，则继续查找；
- 若遍历完列表仍然未查找到待交换数，则对列表进行升序排列。

![image.png](https://pic.leetcode-cn.com/6323ab97a25cf01a3fd30edec3fb05c620024b6b09532f760e373e048e3c8af9-image.png)

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 1:
            return None
        max_last_num = nums[-1]
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] >= max_last_num:
                max_last_num = nums[i]
            else:
                # 找到了待交换的位置
                # 先对尾部数据进行排序
                nums[i+1:] = sorted(nums[i+1:])
                for j in range(i+1, len(nums)):
                    # 找到排序后的尾部序列中大于待交换数的最小值并完成交换
                    if nums[j] > nums[i]:
                        nums[i], nums[j] = nums[j], nums[i]
                        return None
        nums[:] = sorted(nums[:])
        return None
```