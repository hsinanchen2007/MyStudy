有一种取巧的方法：
4，5，6，7的比特计位可以看作0+4，1+4，2+4，3+4。
将初始数组nums设置为【0，1，1，2】即0到3的比特位计数。
如果输入的num在0到3直接直接返回nums【：num+1】
如果输入的num不在，这将nums的每个值+1后再放回nums。
直到 num在nums中。

时间复杂度O(n)，空间复杂度O(n) 

附上代码：
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        a = [0,1,1,2]
        while num >= len(a):
            a = a + [i + 1 for i in a]
        return a[:num+1]