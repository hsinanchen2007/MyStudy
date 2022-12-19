class Solution:
    def climbStairs(self, n: int) -> int:
        # DP需考虑如下几点：
        # 1）如何分为子问题 ：本题中每个楼梯高i都对应着各自的方案总数Si
        # 2）如何将大问题与前边已解决的子问题联系起来，即找到递推式：
        # 当楼高n时，可以粗略的分为两种方案，即 先爬n-1阶，再爬1阶；先爬n-2阶，再爬2阶
        # 所以Sn = Sn-1 + Sn-2

        S = [0,1,2] # 初始n=1和n=2时，各自的方案数, 0元素只是为了保证各元素的索引与n值相对应
        for i in range(3,n+1):
            a = S[i-1] + S[i-2]
            S.append(a)
        return S[n]