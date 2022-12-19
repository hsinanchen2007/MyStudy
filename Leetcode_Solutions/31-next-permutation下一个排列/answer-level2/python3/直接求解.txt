### 解题思路
此处撰写解题思路

### 代码

```python3

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        len1 = len(nums)
        if len1 == 0:
            return
        for i in range(len1 - 1, 0, -1):
            if nums[i] > nums[i - 1]:
                min_i = i
                for j in range(len1 - 1, i, -1):
                    if nums[min_i] > nums[j] > nums[i - 1]:
                        min_i = j
                        nums[min_i], nums[i - 1] = nums[i - 1], nums[min_i]
                        break
                else:
                    nums[min_i], nums[i - 1] = nums[i - 1], nums[min_i]

                # 排序
                while True:
                    flag = True
                    for k in range(i, len1 - 1):
                        if nums[k] > nums[k + 1]:
                            nums[k], nums[k + 1] = nums[k + 1], nums[k]
                            flag = False
                    if flag:
                        break
                break
        else:
            left, right = 0, len1 - 1
            while left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1

```