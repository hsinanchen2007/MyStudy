看题[自动变颜色2333]，首先思路就是dp或者贪心，但是感觉又忘了咋做的了【太菜】。
看了评论，发现就是[198打家劫舍](https://leetcode-cn.com/problems/house-robber/)
点过去发现我做过小偷的题。。
好久没做动态规划，还是得多练习啊。。

 空间复杂度为O（1），时间复杂度O（n）
```
class Solution:
    def rob(self, nums: List[int]) -> int:        
        last,now=0,0
        for num in nums:
            last,now=now,max(last+num,now)
        return now
```
