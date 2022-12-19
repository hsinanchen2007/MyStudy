### 解题思路
采用滑动窗口的思想，设置两个指针left和right，预想存储前缀和在sums，方便后续写代码，但这样内存开销较大，可以优化，随后通过计算left到right之间的和，看是否满足题目要求,大于等于s，若满足要求即可移动left指针，不满足要求移动right指针，记录每次符合要求时的最小值。

### 代码

```python3
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        sums = []
        temp = 0
        for s1 in nums:
            temp += s1
            sums.append(temp)
        left, right = 0, 0
        ans = 0x3f3f3f
        while right < len(nums):
            res1 = sums[right]-sums[left]+nums[left]
            while res1 >= s and left+1 < len(nums):
                # print(left,right)
                ans = min(ans, right - left + 1)
                # print(ans)
                left += 1
                # print(left, right)
                res1 = sums[right]-sums[left]+nums[left]
                # print(res1)
            # print('*')    
            right += 1
        ans = 0 if ans == 0x3f3f3f else ans
        return ans
            

```