    def findNthDigit(self, n: int) -> int:
        '''
        1. 确定所要求的数字在哪个10的幂空间：比如 n=13处于[10,100)的空间内
        2. 规律：每一个10的幂空间有规律的，1-9为10-1,10-99为（100-10）*2
            100-999为（1000-100）*3 ....以此类推
        3. 确定搜索空间后，此空间内所有数字位数相同，整除上取整确定数字，求余确定第几位
        :param n:
        :return:
        '''
        e,count = 0,0
        while count < n:
            e+=1
            count += (pow(10,e)-pow(10,e-1))*e
        count -= (pow(10,e) - pow(10,e-1))*e
        return str(pow(10, e-1) - 1+math.ceil((n - count) / float(e)))[(n-count)%e-1]
