分析：
假定n=10,首先考虑最后一步的情况,要么从第九级台阶再走一级到第十级,要么从第八级台阶走两级到第十级,因而,要想到达第十级台阶,最后一步一定是从第八级或者第九级台阶开始.也就是说已知从地面到第八级台阶一共有X种走法,从地面到第九级台阶一共有Y种走法,那么从地面到第十级台阶一共有X+Y种走法.
即F(10)=F(9)+F(8)
     分析到这里,动态规划的三要素出来了.
        边界:F(1)=1,F(2)=2
        最优子结构:F(10)的最优子结构即F(9)和F(8)
        状态转移函数:F(n)=F(n-1)+F(n-2)
引用自：https://www.cnblogs.com/liuyicai/p/10182262.html
代码：
class Solution:
    def climbStairs(self, n: int) -> int:
        climb = {}
        climb[0] = 0
        climb[1]=1
        climb[2]=2
        for i in range(3,n+1):
            climb[i] = climb[i-1] + climb[i-2]
        return climb[n]