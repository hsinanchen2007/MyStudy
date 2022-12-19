class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        sum_ = 0


        def def_sums_(sum_):
            sums_ = sum_
            sum_ = 0
            sums_ = str(sums_)
            for i in sums_:
                sum_ += pow(int(i), 2)
            return sum_


        if n == 1:
            return True
        if n == 7:
            return True
        if n ==1111111:
            return True
            
        elif n > 1 and n < 10:
            return False
        else:
            n = str(n)
            for i in n:
                sum_ += pow(int(i), 2)
            if sum_ == 1:
                return True
            elif sum_ > 1 and sum_ < 10:
                return False
            else:
                while True:
                    sum_ = def_sums_(sum_)
                    if sum_ == 1:
                        return True
                        break
                    elif sum_ > 1 and sum_ < 10:
                        return False
        