整形反转可以转化到字符型反转，再处理一下符号即可
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if -10 < x < 10:
            return x
        result = []
        if x > 0:
            flag = 0
        else:
            flag = 1
        for i in range(len(str(abs(x))), 0, -1):
            result.append(str(abs(x))[i-1])
        res = int(''.join(result))
        if flag:
            res *= -1
        if -2**31<res<2**31-1:
            return res
        else:
            return 0