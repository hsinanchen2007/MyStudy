### 解题思路
j指针是非零元素和零元素的分界
顺着i指针从左往右走, 遇到0就del, 然后append到最后.

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j = len(nums) - 1 # 第一个非0位置
        while j >= 0:
            if nums[j] != 0:
                break
            j -= 1
        i = 0
        while i <= j:
            if nums[i] == 0:
                # print("i", i)
                del nums[i]
                nums.append(0)
                j -= 1
            else:
                i += 1  

```