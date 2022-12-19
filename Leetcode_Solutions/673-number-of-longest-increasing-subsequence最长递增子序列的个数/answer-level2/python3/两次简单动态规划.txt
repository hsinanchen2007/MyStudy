本题第一个dp，表示到达当前节点的最长子序列长度。
比如输入数组：1，2，4，3，5，4，6
对应dp：     1，2，3，3，4，4，5
第二个dp2表示到达当前节点有几条路径，判断是用dp数组，比如当前是第5个结点，值也为5，对应dp[4]=4，然后看dp=3的并且该节点值小于5的有几个，数一下一共有两个，把对应节点的dp2的数加过来，所以到达该节点的路径有两条。同理最后一个节点值为6，dp=5，dp=4的有两个，且都小于6，所以把他们两个的dp2都加过来，一共为3。
所以对应dp2：1，1，1，1，2，1，3
然后把dp最大的结点，因为有可能有多个，把他们对应的dp2相加起来，最后得出结果。
```
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        lenk=len(nums)
        if lenk==0:return 0
        dp=[1 for i in range(lenk)]
        for i in range(1,lenk):
            if nums[i]==nums[i-1]:
                dp[i]=dp[i-1]
                continue
            else:
                for j in range(i-1,-1,-1):
                    if nums[i]>nums[j] and dp[j]+1>dp[i]:
                        dp[i]=dp[j]+1
        # print(dp)
        mindp=min(dp)
        maxdp=max(dp)
        if maxdp==mindp:return lenk
        dp2=[1 for i in range(lenk)]
        for i in range(1,lenk):
            if dp[i]==mindp:
                dp2[i]=1
                continue
            count=0
            for j in range(i):
                if dp[j]==dp[i]-1 and nums[j]<nums[i]:
                    count+=dp2[j]
            dp2[i]=count
        res=0
        for i in range(lenk):
            if dp[i]==maxdp:res+=dp2[i]
        return res
```
![B9222C80-EE60-46ED-BC4A-7306B32FE24C.png](https://pic.leetcode-cn.com/7f7c59aec2bf147abdac650afd216222fd82c24d0d36668dda441f99396d3b4c-B9222C80-EE60-46ED-BC4A-7306B32FE24C.png)
