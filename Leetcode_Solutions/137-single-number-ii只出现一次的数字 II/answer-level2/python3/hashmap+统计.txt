```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        '''
        思路：主要是利用到了hashmap的方式进行查找，然后统计，最后得到value=1的key就是答案了。
        有个大神的思路是：我们知道异或运算等价于二进制相加不进位计算！那么我们只要设置一个三进制
        相加不进位的同样计算法则，就可以解决此题。
        '''
        d = {}
        for n in nums:
          if n in d:
            d[n] += 1
          else:
            d[n] = 1
        for k in d:
          if d[k] == 1:
            return k
```
