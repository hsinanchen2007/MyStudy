### 解题思路

使用sign记录1的位置，当往左边添加一个数时，判断一下这个数是0还是1，如果是0，则与sign的位置互换，sign+1，如果是1，则不做任何处理。
![image.png](https://pic.leetcode-cn.com/8349b2da66c71a5d818228007b06bc9bf9f164ab22272bcbb789676fb4bc8ce6-image.png)

### 代码
```

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        sign = -1
        left = 0
        right = len(nums)-1
        while(left<=right):
            while left<right and nums[right]>1:
                right -= 1
            while left<right and nums[left]<=1:
                if nums[left] == 1 and sign == -1:

                    sign = left
                if nums[left] == 0 and sign != -1:
                    nums[sign] = 0
                    nums[left] = 1
                    sign += 1
                left += 1
            temp = nums[right]
            nums[right] = nums[left]
            nums[left] = temp
            if nums[left] == 1 and sign == -1:
                sign = left
            if nums[left] == 0 and sign != -1:
                nums[sign] = 0
                nums[left] = 1
                sign += 1
            right -= 1
            left += 1
```
```
