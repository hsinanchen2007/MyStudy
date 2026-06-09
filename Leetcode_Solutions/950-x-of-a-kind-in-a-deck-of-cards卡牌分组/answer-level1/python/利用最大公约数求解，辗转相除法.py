### 解题思路
主要利用了辗转相除法，手动求解最大公约数
用时20ms，但是内存消耗较大，可以尝试优化一下～
基本上有这几种情况：
1.每个数字出现次数都相等
    1. 出现次数 = 1 🙅False
    2. 出现次数 > 1 🙆True
2.出现次数有不相等的
    1. 不相等的次数和其他数字次数的最大公约数 = 1 False
    2. 不相等的次数和其他数字次数的最大公约数 > 1 True

### 代码

```python
class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        #辗转相除法，求解最大公约数
        def divNum(m,n) :  
            if m < n : m, n = n, m
            while n > 0 :
                m, n = n, m%n  
            return m
        cards = {}
        for i in deck :
            if i not in cards :
                cards[i] = 1
            else :
                cards[i] += 1
        cnt = cards[deck[0]]

        for i,j in cards.items() :
            if divNum(j , cnt) <= 1 :
                return False
            cnt = j
        return True





```