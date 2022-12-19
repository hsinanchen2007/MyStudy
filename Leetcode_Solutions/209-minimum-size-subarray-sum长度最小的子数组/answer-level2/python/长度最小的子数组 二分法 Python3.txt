### 解题思路
执行用时 :92 ms, 在所有 Python3 提交中击败了41.99%的用户
内存消耗 :15.3 MB, 在所有 Python3 提交中击败了70.63%的用户

思路：
尝试O(nlogn)时间复杂度的解法，出现logn想到二分法
用二分法确定最小长度num_long，然后依次扫描整个nums，确定是否有长度为num_long的连续数组和大于s

### 代码

```python3
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        # 找不到返回0
        if sum(nums) < s:
            return 0
        
        left = 0
        right = min_long = len(nums)
        while left < right:
            # 二分法计算长度
            num_long = (left + right ) // 2  
            # 滑动计算长度为num_long的连续子数组
            cnt = sum(nums[0: num_long])
            if_cnt = cnt >= s
            for i in range(num_long, len(nums)):
                cnt = cnt + nums[i] - nums[i-num_long]
                if cnt >= s:
                    if_cnt = True  # 如果数组和大于s
                    break
            if if_cnt:
                right = num_long  # 如果num_long满足条件减少数组长度
                min_long = min(min_long, num_long)
            else:
                left = num_long+1  # 否则增加数组长度

        return min_long
```