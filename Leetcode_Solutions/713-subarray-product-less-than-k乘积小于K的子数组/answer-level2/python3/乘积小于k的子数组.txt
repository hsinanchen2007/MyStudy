### 解题思路
![image.png](https://pic.leetcode-cn.com/3f5d2ff3e4c3c2ac6ab6d852397a87489eb15e55f528c6f8fe7e0ce06d6ea169-image.png)

对于数组`nums`而言，乘积小于`k`的子数组的可以分成两部分：
1. 数组`nums[:-1]`中的乘积小于`k`的子数组
2. 以`nums[-1]`结尾的乘积小于`k`的连续子序列

按照上述方法拆分，可以用动态规划进行计算，假设当前遍历到整数`nums[i]`，令`tmp`表示以`nums[i]`结尾的乘积小于`k`的子序列，其长度用`length`表示，另外`count`为数组`nums[:i+1]`中满足条件的子序列个数；现在考虑第`i+1`个整数，存在下述三种情况：
1. `nums[i+1]>=k`，此时，不可能存在包含`nums[i]`的满足条件的子序列，因此跳过当前整数，初始化`tmp, length`参数；
2. `nums[i+1]*tmp<k`，此时以`nums[i+1]`结尾的满足条件的子序列有`length+1`个，因此更新`count+=length+1, length+=1, tmp*=nums[i+1]`；进入下一个循环；
3. `nums[i+1]*tmp>=k`，即是子序列`nums[i+1-length:i+1+1]`这个子序列的乘积，并不满足条件；将该子序列的开始整数`nums[i+1-length]`去掉，即更新参数`tmp//=nums[i+1-length],length-=1`；仍然进入当前循环；

算法的初始化参数：`tmp, count, length = 1, 0, 0`；

时间复杂度：`O(n)`；
空间复杂度：`O(1)`；

### 代码

```python3
class Solution:
    """
    遍历整数数组nums，假设遍历到nums[i]
    令length表示以nums[i]结尾且满足条件的子序列长度，tmp表示该子序列的乘积，count为数组nums[:i+1]的满足条件的子数组的个数；接下来考虑第i+1个整数nums[i+1]，则有以下几种情况：
    1. tmp*nums[i+1]<k，此时count要增加所有以nums[i+1]结尾的满足条件的子序列，即count+=length+1；更新tmp*=nums[i],length+=1；
    2. tmp*nums[i+1]>=k，更新length-=1, tmp /= nums[i+1-length]，count不变；再重要考虑tmp*nums[i+1]的情况；
    3. nums[i+1]>=k，则tmp=1, count不变，length=0，进入下一个循环；
    """
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if len(nums) == 0:
            return 0
        i, tmp, count, length = 0, 1, 0, 0

        while i < len(nums):
            # 需要先考虑nums[i]是否大于k，如果大于k，相当于将数组分成两半，
            # 分别是nums[:k]和nums[k+1:]这两个数组的结果这和，因此将tmp和length参数重置；
            if nums[i] >= k:
                tmp, length = 1, 0
                i += 1
            elif tmp*nums[i] < k:
                count += length+1
                length += 1
                tmp *= nums[i]
                i += 1
            else:
                tmp //= nums[i-length]
                length -= 1
        return count
```