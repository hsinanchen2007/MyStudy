**思路一：借助额外空间**
```python
from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        NoneZeroNums = []
        
        # 遍历数组，将所有非零元素添加到新数组中
        for i in nums:
            if i != 0:
                NoneZeroNums.append(i)
        # 将新数组中的元素复制给 nums 数组的前 len(NoneZeroNums) 项       
        for i in range(len(NoneZeroNums)):
            nums[i] = NoneZeroNums[i]
        # 将 nums 数组 len(NoneZeroNums) 之后的项用零替换
        for i in range(len(NoneZeroNums), len(nums)):
            nums[i] = 0

        return nums
```
时间复杂度：O(n)
空间复杂度：O(n)

**思路二：在原数组上操作，将非零元素依次复制到前 k 项**

```python
from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        k = 0
        # nums 中，[0,...,k) 的元素均为非零项
        # 遍历到第 i 个元素后，保证 [0,...,i] 中所有非零元素都按照顺序排列到 [0,...,k) 中

        while i <len(nums):
            if nums[i] != 0:
                nums[k] = nums[i]
                k += 1
            i += 1
        
        # 将 k 之后的元素用零替换
        for j in range(k,i):
            nums[j] = 0
            
        return nums
```
时间复杂度：O(n)
空间复杂度：O(1)

**思路三：在原数组上操作，将非零元素与零元素交换位置**

```python
from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        k = 0
        # nums 中，[0,...,k) 的元素均为非零项
        # 遍历到第 i 个元素后，保证 [0,...,i] 中所有非零元素都按照顺序排列到 [0,...,k) 中
        # 同时 [k,...,i]的元素均为零

        while i < len(nums):
            if nums[i] != 0:
                # 避免当 nums 中元素全为非零元素时，自身的交换
                if i != k:
                    nums[i],nums[k] = nums[k],nums[i]
                else:
                    pass
                k += 1
            i += 1

        return nums
```
时间复杂度：O(n)
空间复杂度：O(1)