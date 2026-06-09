### 解题思路
从头开始遍历，如果是0，则挪到头部，如果是2则挪到尾部，1跳过。一共操作n次
### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        p = 0 # 列表位置

        for i in range(len(nums)):
            if nums[p] == 0:
                nums.pop(p)
                nums.insert(0, 0)
                p += 1
                continue

            if nums[p] == 1:
                p += 1
                continue
            
            if nums[p] == 2:
                nums.pop(p)
                nums.append(2)
        
        return nums


```