
![微信截图_20190919145118.png](https://pic.leetcode-cn.com/b4b4076dce3382289cc62ef75f12ef0168f8aa9d3cd988346c83901102b0b905-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190919145118.png)
class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num<0:
            return False
        num=bin(num)[2::]
        if num.count('1')==1 and len(num)%2!=0:
            return True
        return False
        

