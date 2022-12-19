### 解题思路
先排序，从最小的开始，保存最后一次选到该点的最大收益。

### 代码

```python3
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        #思路：动态规划，先排序，再计算每一个的最大值
        if nums == []:
            return 0
        if len(nums) == 1:
            return nums[0]
        a = collections.Counter(nums)
        nums = list(set(nums))
        q_table = [0] * len(nums)
        q_table[0] = nums[0] * a[nums[0]]
        if nums[1] - 1 == nums[0]:
            q_table[1] = nums[1] * a[nums[1]]
        else:
            q_table[1] = nums[1] * a[nums[1]] + q_table[0]
        for i in range(2,len(nums)):
            if nums[i] - 1 == nums[i-1]:
                q_table[i] = nums[i] * a[nums[i]] + max(q_table[0:i-1])
            else:
                q_table[i] = nums[i] * a[nums[i]] + max(q_table[0:i])
        return max(q_table)




```