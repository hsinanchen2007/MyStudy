### 解题思路
1、增加辅助数组result，记录递增序列（最后得出的结果不一定是实际的最长子序列，但最长子序列的个数是正确的）。
2、遍历一遍输入数组，遇到nums[i]大于栈顶元素，则加入result；若小于栈顶元素，则寻找该元素（nums[i]）第一次小于等于result数组中元素的位置，替换该值（这样不会改变已有最大子序列长度，只是对应位置替换成较小的值）。
3、返回的result长度即可。

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)
        result = [nums[0]]
        for i in range(len(nums)):
            if nums[i] > result[-1]:
                result.append(nums[i])
            else:
                count = 0
                for j in range(len(result)):
                    if nums[i] <= result[j]:
                        count += 1
                        if count == 1:
                            result[j] = nums[i]
                            break
        return len(result)
```