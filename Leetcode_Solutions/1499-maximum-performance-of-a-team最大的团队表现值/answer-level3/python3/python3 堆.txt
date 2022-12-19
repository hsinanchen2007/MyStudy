因为有速度和效率两个变量，刚开始会觉得摸不着头脑。
但是如果我们把每个人的效率值从大到小排序，我们就能轻松的计算出在给定效率的情况下，团队效率的最大值（时间总和取最大即可）。

具体的我们从n-k这位员工开始分析，因为取到他的时候，团队里刚好有k个人。
很明显此时团队效率最大值就是这个k个员工各自速度和效率的和，因为每个人都会被取到。

我们接着看n-k-1这位员工，此时我们规定团队效率等于该员工的效率，那么我们要考虑的只有时间。
因为n-k-1这位员工的速度一定会被计入团队总速度（因为我们已经选定了这名员工的效率作为团队效率），
所以他必定会挤掉团队中的一人，挤掉谁会使得团队速度和最大呢？很明显答案是速度最小的那个人。

因此我们首先将每个员工的速度和效率一起按效率进行降序排序。
然后维护一个堆，这样可以利用heappop减少弹出速度和最小值时所用的时间。
同时使用sum这个变量存储团队速度和，因为每次弹出对象的大小都是明确的，这样做也可以节约时间。
```
from heapq import heappush,heappop
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        bond=sorted(list(zip(speed,efficiency)),key=lambda x:-x[1])
        sum=0
        ans=0
        q=[]
        for x,y in bond:
            if len(q)==k:
                b=heappop(q)
                sum-=b
            sum+=x
            heappush(q,x)
            ans=max(ans,sum*y)
        return ans%1000000007
```
代码是参考排行榜大佬的，我对堆结构还不熟悉，所以当时没想到。


