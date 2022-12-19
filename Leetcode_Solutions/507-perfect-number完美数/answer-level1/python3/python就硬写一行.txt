写，就硬写。
```
class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return sum([item for inner in [[i, num/i] for i in range(2, int(math.sqrt(num)) + 1) if num % i == 0] for item in inner]) + 1 == num if num > 2 else False
```
原代码：超过94%时间 空间50%...
思路分析：
    利用python的math包中的求平方根函数
    1.列表求出所有因子
    2.只需要遍历到平方根（因子成对出现）
    3.找到一个因子 利用num/因子 就可以得到另一个因子
    4.求和判断
```
class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """    
        import math
        yinzi_list = [1]
        if num <= 2:
            return False
        for i in range(2, int(math.sqrt(num)) + 1):
            if num % i == 0:
                # 避免重复录入
                if i != num / i:
                    yinzi_list.extend([i, num / i])
                else:
                    yinzi_list.append(i)
        return sum(yinzi_list) == num
```

