首先找出所有的奇数项，把位置索引存在res数组中，判断如果len(res) < k,直接返回-1，否则在res前面添加0，末尾添加len(nums)-1,
然后使用滑窗或者双指针都行，从res[1]开始依次计算，注意分情况讨论
```
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        res = []
        for i in range(len(nums)):
            if nums[i] % 2 == 1:
                res.append(i)
        if len(res) < k:
            return 0
        ans = 0
        res.insert(0, 0)
        res.append(len(nums)-1)
        for i in range(1, len(res) - k):
            start = i
            end = i + k - 1
            #处理左边界
            if start == 1 and end != len(res) - 2:
                ans += (res[end + 1] - res[end]) * (res[start] - res[start - 1] + 1)
            elif start == 1 and end == len(res) - 2:
            #处理左、右边界
                ans += (res[end + 1] - res[end] + 1) * (res[start] - res[start - 1] + 1)
            #处理一般情况
            elif start != 1 and end != len(res) - 2:
                ans += (res[end + 1] - res[end]) * (res[start] - res[start - 1])
            #处理右边界
            elif start != 1 and end == len(res) - 2:
                ans += (res[end + 1] - res[end] + 1) * (res[start] - res[start - 1])
        return ans
```
