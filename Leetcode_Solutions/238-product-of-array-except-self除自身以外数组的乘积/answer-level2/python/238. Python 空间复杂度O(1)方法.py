### 解题思路
如果没有限制不能使用除法，那么这道题最简单的方法是先计算所有的数字的乘积，然后除以当前数字。（有0另做处理）
如果不能使用除法，那么可以使用两个数组分别记录当前数字左边的数字的乘积和右边的乘积，这时的时间复杂度和空间复杂度都是O(n)。此时应该有察觉其实其中的一个数组并不需要提前计算出来，因为在遍历nums时，可以同时计算，而题目又说答案数组并不计算在空间复杂度内。
那么此时O(1)的空间复杂度的处理方法就很明显了，使用一个数组保存单向的乘积，另一个方向的乘积在遍历过程中计算即可。

### 代码

```python
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        data = [0] * length 
        temp = 1
        # 先令data存储乘积，即data[i]为nums[i + 1:]的乘积
        for i in range(length - 1, -1, -1):
            data[i] = temp
            temp *= nums[i]
        
        # 动态计算左侧乘积和答案
        temp = 1
        for i in range(length):
            data[i] = temp * data[i]
            temp *= nums[i]

        return data
```