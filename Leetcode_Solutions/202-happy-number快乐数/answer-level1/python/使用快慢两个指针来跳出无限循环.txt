```
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        #思路：这道题的难点在于如何处理无限循环的情况
        #使用快慢两个指针，快的一次走两步，慢的一次走1步，一旦快的追上慢的，说明存在无限循环
        slow = get_num(n)        
        fast = get_num(get_num(n))
        if slow == 1:
            return True
        while fast != slow:            
            slow = get_num(slow)        
            fast = get_num(get_num(fast))
            print "slow: ",slow," fast: ",fast
            if slow == 1:
                return True
        return False

#算出一个数的平方和
def get_num(n):
    sum = 0
    while n >= 10:
        shang = n / 10
        yushu = n % 10
        sum += yushu**2
        n = shang
    sum += n**2
    return sum


```
