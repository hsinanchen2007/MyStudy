"""
转化成选择分类问题
首先两种特例，n = 0   n = 1  直接先return掉
后续的分类讨论：
1、全是1步
2、全是2步（n为奇数和n为偶数两种情况）
3、按照两步走的数量遍历，转化为选择分类问题
    把两步打包，计算一共走的次数，总次数中选出两步个数就是总的可能，例如：
    n = 11 两步走的情况是2，那么一共会走的次数是  11 - 4 + 2 = 9
    那么 求出 C 9 2  就是这种情况的所有可能
"""





class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1

        # 情况1：全1
        total_step = 1
        # 情况2：单数 全2
        if n % 2 != 0:
            double_num = int(n/2)
            total_step += (double_num + 1)
        # 情况3：双数 全2
        else:
            double_num = int(n/2)
            total_step += 1
        # 情况4：全2  一直  递减到 2
        for i in range(1, double_num):
            bottom = n - 2 * i + i
            numerator = 1
            denominator = 1
            for j in range(i):
                numerator *= bottom
                bottom -= 1
                denominator *= (j+1)
            total_step += (numerator/denominator)
        
        return int(total_step)