![搜狗截图20年02月01日2312_1.png](https://pic.leetcode-cn.com/ca0c74f17f1ecacb6df08cd29de9177ed546eff13ad96dfba5d7a1027b76b546-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B402%E6%9C%8801%E6%97%A52312_1.png)
# 前提摘要：
198.打家劫舍：解法为main函数（思路见198题官方题解）
# 主要思想：
由于首尾相连，所以nums[0]和nums[-1]是相邻的，因此实际符合的情况是nums[0]~numms[-2]和nums[1]~nums[-1]，涵盖了所有情况
所以只需将上述两段送入main之后取二者最大值即得到本题答案
***注意：长度为0~2的特例特殊考虑***

```
class Solution:
    def rob(self, nums: List[int]) -> int:
        def main(nums):
            n=len(nums)
            if n==0:return 0
            if n==1:return nums[0]
            pre=nums[0]
            cur=max(nums[0],nums[1])
            for i in range(2,n):
                temp=cur
                cur=max(pre+nums[i],cur)
                pre=temp
            return cur
        n=len(nums)
        if n==0:return 0
        if n==1:return nums[0]
        if n==2:return max(nums[0],nums[1])
        return max(main(nums[:n-1]),main(nums[1:n]))
```
