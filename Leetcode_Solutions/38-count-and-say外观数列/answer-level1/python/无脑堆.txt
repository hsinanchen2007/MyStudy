题解：
1.f(n)是根据f(n-1)推算出来的；
2.f(x)中两个相邻的数字，第一个代表个数，第二个代表数字本身，举例：1123，念做1个1，2个3；
3.可以从前往后遍历，相同的数字/字母，个数加一；
4.最后一个不进行遍历（主要还是因为我这的代码中用到了index与index+1做对比）；
5.最后一个数字/字母已经在result[index] == result[index+1]中做了对比，也就是说num变化了，所以最后直接堆上num和result[-1]即可；
```
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """

        #傻瓜式破解
        
        def count(result):
            num = 1
            res = ""
            for index in range(len(result) - 1):
                if result[index] == result[index+1]:
                    num += 1
                else:
                    res += str(num)
                    res += result[index]
                    num = 1
            res += str(num)
            res += result[-1]
            return res
        
        result = '1'
        for i in range(1,n):
            result = count(result)

        return result
```
