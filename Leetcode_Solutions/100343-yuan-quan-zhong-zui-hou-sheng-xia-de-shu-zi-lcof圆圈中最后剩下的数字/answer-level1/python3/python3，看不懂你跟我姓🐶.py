# 首先，记f(n)为游戏结束后最后一个数字的index，那么关键在于找到f(n,start=0)和f(n-1,start=0)的关系。显然，第一次扔出去的元素是(m-1)%n，记作k，那么根据游戏规则f(n,start=0)=f(n-1,start = k+1)。接下来我们可以看到f(n-1,start = k+1) = (f(n-1,start=0)+k+1)%n。有了这个中间桥梁，可知f(n,start=0) =  (f(n-1,start=0)+k+1)%n =  (f(n-1,start=0)+m)%n。然后从f(1)=0推广过去即可。

# 这类问题凭空很难找到规律，建议记住f(n) = (f(n-1)+m)%n的大概形式，再去推导会比较有方向。数学归纳法都是扯淡，都是有了公式强行去归纳，要是不知道递推公式怎么能从n=1,n=2,n=3找到取模规律，反正我不行🐶！

# ```python
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        res = 0
        for i in range(2,n+1):
            res = (res+m)%i
        return(res)
# ```