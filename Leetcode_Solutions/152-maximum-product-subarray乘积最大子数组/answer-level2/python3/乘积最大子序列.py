### 解题思路
假设第`k+1`个整数`nums[k]`在最大子序列中，如`[nums[k1],nums[k2],...,nums[k],nums[k+1],...]`，那么`nums[k1]*nums[k1+1]*...*nums[k]`的乘积要么是最大正数，要么是最小负数；

考虑整数数组`nums[:k]`与整数`nums[k]`的关系；
1. 以`nums[k]`结尾的子序列的乘积要么是最大的正数，要么是最小的负数；
2. 为了求step1中的两种情况，需要将以`nums[k-1]`结尾的子序列的乘积的最大数与最小数保存；
3. 考虑相乘结果与`nums[k]`本身，即`max_p*nums[k], min_n*nums[k], nums[k]`，取这三个数中的最大数，最小数保存，即子序列以`nums[k]`结尾的乘积为最大正数或最大负数；


### 代码

```python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        # max_product保存返回结果， tmp是整数数组nums[:k]中包含nums[k-1]的子序列的乘积为最大正数和最小负数的列表；
        max_product, tmp = nums[0], [nums[0]]
        
        for i in range(1, len(nums)):
            l = [nums[i]]
            # 将tmp中的元素分别与nums[i]相乘并保存到l中
            for j in tmp:
                l.append(j*nums[i])
            # 如果l中的最大与最小分别为正负数，则包含nums[i]的子序列的乘积即可以为正数，也可以为负数
            # 则将最大正数与最小负数保存到tmp中
            # 否则只保存最大正数或最小负数
            tmp1, tmp2 = min(l), max(l)
            if tmp1*tmp2 < 0:
                tmp = [tmp1, tmp2]
            elif tmp1 >= 0 and tmp2 >= 0:
                tmp = [tmp2]
            else:
                tmp = [tmp1]
                
            max_product = max(max_product, tmp2)
            
        return max_product
```