根据上述规律，先算出，对于一个数a，幂次为n时，回到原数a。
之后计算数字b的值，对幂次n取余
最后求a的余数次幂

class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        a %= 1337
        tmp = a
        cnt = 0
        while tmp!=a or cnt==0:
            tmp = (tmp*a)%1337
            cnt += 1

        num = 0
        for i in b:
            num = (num*10+i)%cnt
        
        res = 1
        for i in range(num):
            res = (res*a)%1337
        
        return res
