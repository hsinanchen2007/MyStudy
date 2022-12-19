注意
self.time(piles, m) = H必须放到“<=”判断中
因为 当珂珂吃的比用时H的速度稍微慢一点，就有可能所用时间大于H；
但如果珂珂吃的比用时H的速度稍微快一点，用时可能与用时H的速度所用时间相同，例如8只香蕉珂珂一小时吃4只与一小时吃5只用时相同，所以如果珂珂速度为5时，我们希望他慢下来，所以放到<=里。

使用左中位数

class Solution(object):
    def time(self, piles, speed):
        result = sum((p-1) / speed + 1 for p in piles)
        return result
    
    def minEatingSpeed(self, piles, H):
        """
        :type piles: List[int]
        :type H: int
        :rtype: int
        """ # 二分查找K的值
        max_k = max(piles)
        i, j = **1**, max_k
        while i < j:
            m = (i + j)/2
            if self.time(piles, m) <= H: # 速度可能太快 等于号只能归到这里
                j = m
            else:
                i = m + 1
        return i

1. 注意：i如果从0开始，会出现 m=i=0 的情况。time函数中有除法
2. 注意：需要判断 输出为 i-1 还是i。因为等号下j = m，所以return i。


使用右中位数时：

class Solution(object):
    def time(self, piles, speed):
        result = sum((p-1) / speed + 1 for p in piles)
        return result
    
    def minEatingSpeed(self, piles, H):
        """
        :type piles: List[int]
        :type H: int
        :rtype: int
        """ # 二分查找K的值
        max_k = max(piles)
        i, j = **0**, max_k
        while i < j:
            m = (i + j + 1)/2
            if self.time(piles, m) <= H: # 速度可能太快 等于号只能归到这里
                j = m - 1
            else:
                i = m
        return i + 1

1. 注意：i如果从1开始，会出现边界条件的错误，例如当只有一堆香蕉时
2. 注意：需要判断 输出为 i+1 还是 i。因为等号下j = m - 1，所以return i + 1。

总结：
1. 建议使用左中位数
2. 判断最后的输出是left还是right