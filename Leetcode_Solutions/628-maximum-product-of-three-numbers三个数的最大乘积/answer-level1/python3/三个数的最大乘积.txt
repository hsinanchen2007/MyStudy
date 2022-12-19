### 解题思路
![image.png](https://pic.leetcode-cn.com/09a9523bbd882f4f361dd8566dc00a4c704a29f853c646b7a9db7806961f383b-image.png)

数组`nums`中三个数的最大乘积有下面两种情况：
1. `nums`中最大三个整数的乘积
2. `nums`中最小两个整数和最大整数三个数的乘积（考虑到负数的情况）

因此将上述两种情况中的最大值输出即可；

时间复杂度：`O(nlogn)`；排序的时间复杂度
空间复杂度：`O(1)`；

### 代码

```python3
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return 0
        elif len(nums) == 3:
            return nums[0]*nums[1]*nums[2]
        
        nums.sort()
        tmp1 = nums[-1]*nums[-2]*nums[-3]
        tmp2 = nums[0]*nums[1]*nums[-1]
        return max(tmp1, tmp2)
```