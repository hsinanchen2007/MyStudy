### 解题思路
假设跳过的预约个数为n,那么1<=n且n<=2,n永远不会到3及以上
可能等于2是因为选择第i个的预约时间的方案远比选择第i-1个预约时间的方案更优，所以连跳两个
不能达到3是因为如果达到3那么我们完全可以把中间的那个预约时间加上去，结果肯定比没加要来的大
所以就可以采用动态规划的方法，最后的最大值不是存储在nums[len(nums)-1]就是在nums[len(nums)-2]中

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        n=len(nums)
        if n==0:return 0
        if n==1:return nums[0]
        if n==2:return max(nums[0],nums[1])
        nums[2]=nums[0]+nums[2]
        for i in range(3,n):
            nums[i]=max(nums[i-2],nums[i-3])+nums[i]
        return max(nums[n-1],nums[n-2])

```