解题思路：
记录当前元素nums[i],当前序列的最大值result_temp,总的最大值result
1.如果元素全为负数，则选出最大的负数，并返回。
2.如果元素内有正数也有负数，则：
    1.  如果遇到负数，有两种情况。第一种，此负数对当前序列最大值可能有贡献，例如：2，-1，3.此时保留该负数。如果，当前子序列的和result_temp+负数>0（当后面的数为正数时，该负数可以保留），将result_temp更新为result_temp+该负数。第二种，比如：2，-3，4.此时，该负数不可能对当前的子序列有贡献，舍弃该负数，并将result_temp更新为0，计算下一个子序列的和。
    2. 如果遇到正数，则当前子序列和一定会变大。此时更新reuslt_temp += 该正数，更新result为result_temp。
    3. 返回最终的最大值result.
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return
        if len(nums) == 1:
            return nums[0]
        result = nums[0] 
        result_temp = nums[0]
        for i in range(1,len(nums)):
            if nums[i] < 0 :
                if result < 0:
                    if nums[i] > result:
                        result = nums[i]
                        continue
                if nums[i] +result_temp <= 0:
                    result_temp = 0
                    continue
                else:
                    result_temp += nums[i]
                    if result_temp > result:
                        result = result_temp
            else:
                if result < 0:
                    result = 0
                    result_temp = 0
                result_temp += nums[i]
                if result_temp > result:
                    result = result_temp
        return result
```
时间复杂度O(n),空间复杂度O(1)

我的方法看起来比较复杂，看到官方的方法写的更为简洁，不过思想是差不多的。

官方方法：
```
class Solution:
    def maxSubArray(self, nums: 'List[int]') -> 'int':
        n = len(nums)
        curr_sum = max_sum = nums[0]

        for i in range(1, n):
            curr_sum = max(nums[i], curr_sum + nums[i])
            max_sum = max(max_sum, curr_sum)
            
        return max_sum
```
