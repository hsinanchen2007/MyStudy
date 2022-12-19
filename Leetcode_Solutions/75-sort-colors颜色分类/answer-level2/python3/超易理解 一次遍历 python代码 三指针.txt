### 解题思路
分析问题考虑到数组中仅可能存在0，1，2三个数，因此我们在一次遍历中可以采取0向前挪 2向后挪 1保持并跳过的原则。

![image.png](https://pic.leetcode-cn.com/be3a556a3028246c0bf03e70475ad6e4abbda61dbc7a120a0c763dee8e14db8b-image.png)
采取l，r作为数组最终排序后中间所有1的左右边界。初始化l=0, r=len(nums)，遍历指针i=0。
开始遍历，保持0在左边界l的左面，2在右边界r的右面，当遍历指针i到达右边界时，循环结束。
当nums[i]==1时 左边界l 保持不变 i+=1。

![image.png](https://pic.leetcode-cn.com/279d82f8ab0d6b1f3335eb83b4c3a0135a2c9c904db3867bb6f5b3285ea479f9-image.png)
当nums[i]==0时，交换nums[l+1]与nums[i]值 l+=1，i+=1。

![image.png](https://pic.leetcode-cn.com/f52b4d9405396f14e3f4ad06ab14c28a850c3137462fcb25c5c28f86b74fea61-image.png)
当nums[i]==2时，交换nums[r-1]与nums[i]值 r-=1, 此时由于并未扫描到nums[r-1]是否也为2，因此在此i的值保持不变


### 代码

```python
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        l = -1
        r = len(nums)
        i = 0
        while i < r:
            if nums[i] == 1:
                i += 1
                continue
            elif nums[i] == 0:
                nums[i] = nums[l+1]
                nums[l+1] = 0
                l += 1
                i += 1
                continue
            else:
                nums[i] = nums[r - 1]
                nums[r - 1] = 2
                r -= 1
        print(nums)
        return nums
```