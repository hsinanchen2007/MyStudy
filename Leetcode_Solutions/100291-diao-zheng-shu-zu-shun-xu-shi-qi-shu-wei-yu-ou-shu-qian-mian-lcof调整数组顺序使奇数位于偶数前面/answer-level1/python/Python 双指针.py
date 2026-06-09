![image.png](https://pic.leetcode-cn.com/62bfc02b8a2d06ca0c471a048059d0b10390d5bd15e299014ea1d0da2d982d5b-image.png)

### 解题思路
* 指针`i`遍历数组找出奇数
* 指针`j`找出坑，把奇数放进去

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        j = 0
        for i in range(len(nums)):
            if nums[i] & 1:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
        return nums
```