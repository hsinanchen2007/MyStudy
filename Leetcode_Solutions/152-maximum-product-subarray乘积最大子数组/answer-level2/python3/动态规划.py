
**测试用例：**

* 功能测试：\[1,2,2,3\], \[3,-4,3,-3\], \[3,2,-2,1\], \[3,2,0,3\]
* 边界测试：\[1\], \[-1\], \[0\]
* 负面测试：\[\]

## 方法：动态规划

由于存在负数，因此定义两个状态转移矩阵，它们之间存在交互。

- f\_max(i)表示以第i个数字结尾的序列的连续子序列最大乘积
- f\_min(i)表示以第i个数字结尾的序列的连续子序列最小乘积
- 当nums\[i\]为非负数时：
	- f\_max(i)=max(f\_max(i-1) * nums\[i\], nums\[i\])，即当前最大乘积等于，前一步最大乘积与第i个数的乘积，与第i个数，二者最大的那一个
	- f\_min(i)=min(f\_min(i-1) * nums\[i\], nums\[i\])，即当前最小乘积等于，前一步最小乘积与第i个数的乘积，与第i个数，二者最小的那一个
- 当nums\[i\]为负数时：
	- f\_max(i)=max(f\_min(i-1) * nums\[i\], nums\[i\])，即当前最大乘积等于，前一步最小乘积与第i个数的乘积，与第i个数，二者最大的那一个
	- f\_min(i)=min(f\_max(i-1) * nums\[i\], nums\[i\])，即当前最小乘积等于，前一步最大乘积与第i个数的乘积，与第i个数，二者最小的那一个

上述的原理用一句话概括：正数与越大的数字（无论正负）相乘越大；负数与越小的数字（无论正负）相乘越大。

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return nums[0]
        dp_max, dp_min = [0] * n, [0] * n
        dp_max[0], dp_min[0] = nums[0], nums[0]
        for i, num in enumerate(nums[1:], 1):
            if num >= 0:
                dp_max[i] = max(dp_max[i-1] * nums[i], nums[i])
                dp_min[i] = min(dp_min[i-1] * nums[i], nums[i])
            if num < 0:
                dp_max[i] = max(dp_min[i-1] * nums[i], nums[i])
                dp_min[i] = min(dp_max[i-1] * nums[i], nums[i])
        return max(dp_max)
```

**复杂度分析：**

* 时间复杂度：O(n)
* 空间复杂度：O(n)