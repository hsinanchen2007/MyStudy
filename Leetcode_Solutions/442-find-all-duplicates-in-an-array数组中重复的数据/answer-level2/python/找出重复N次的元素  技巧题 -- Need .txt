### 解题思路
1. 题意非常好理解，让人费解的是限制条件：你可以**不用到任何额外空间**并在O(n)时间复杂度内解决这个问题吗？
    - **返回值数组属于额外空间吗？  --- 应该不计算在内的，属于stdout **
    - 遍历数组时，使用的变量算作额外空间吗？  -- 严格来说属于额外空间的

2. 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次
    - **1 ≤ a[i] ≤ n，整数数组**
    - 题解1：由于数组元素具有1 ≤ a[i] ≤ n，当每次经过一个元素时，给他加上n； 再次遍历，数值超过2n的元素对应的idx+1，就是出现两次的元素，**通用**
    - 题解2：元素作为idx正负值表示，**不通用**，但此法仅仅遍历一次

3. **推理：1 ≤ a[i] ≤ n （n为数组长度），可以计算出现N次的元素**

### 代码

```python3
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = list()
        nsize = len(nums)
        if nsize < 1:
            return None
        elif nsize  == 1:
            return None
        else:
            pass 
        '''
        for num in nums:
            if nums[abs(num)-1] < 0:
                res.append(abs(num))
            nums[abs(num)-1] *= -1
        '''

        for num in nums:
            nums[(num-1) % nsize] += nsize 
        
        i = 0
        while i < nsize:
            if nums[i] > 2*nsize:
                res.append(i+1)
            i += 1

        return res 
```