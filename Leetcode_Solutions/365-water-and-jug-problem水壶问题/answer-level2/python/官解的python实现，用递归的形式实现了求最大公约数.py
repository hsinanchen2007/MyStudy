还在leetcode继续学习的菜鸡，写出来不怕献丑，希望能得到大家的建议：

官解链接：https://leetcode-cn.com/problems/water-and-jug-problem/solution/shui-hu-wen-ti-by-leetcode-solution/

附官解中对该数学法的解释：“而贝祖定理告诉我们，ax+by=z 有解当且仅当 z 是 x,y 的最大公约数的倍数。因此我们只需要找到 x,y 的最大公约数并判断 z 是否是它的倍数即可。”

class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        res = False
        # 用于处理 0, 0, 0 时的结果, 否则在 z % gcd(x, y) 会有 division 0 错误
        if x == 0 and y == 0 and z == 0:
            res = True
            return res
        # 辗转相除法: 求得最大公约数
        def gcd(x, y):
            if y == 0:
                return x
            else:
                # 此处一开始遇到阻碍, 因为 python 使用递归时必须在递归处加上 return ,否则返回值为 None
                return gcd(y, x%y)
        # 如果能够满足: 贝祖定理
        # ax+by=z 有解, 当且仅当 z 是 x, y 的最大公约数的倍数.
        # 因此我们只需要找到 x, y 的最大公约数并判断 z 是否是它的倍数即可.
        return res or (x + y >= z and z % gcd(x, y) ==0)
