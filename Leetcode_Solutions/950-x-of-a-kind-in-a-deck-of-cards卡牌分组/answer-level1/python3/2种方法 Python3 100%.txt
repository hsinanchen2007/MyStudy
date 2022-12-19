
***
## 解法一（暴力法）
思路：通过字典保存每个数值对应的个数，然后对所有个数检测，是否可以整除2以上的数值。

1. 使用python内置函数Counter，获取每个数字对应的个数
2. 获取个数最小值作为循环开始，直到最小值小于2
3. 每次循环判断，所有数值整除当前最小值

* 时间复杂度：O(N^2^)
* 空间复杂度：O(N)

```python
# author: suoxd123@126.com
import collections
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        groups = collections.Counter(deck)
        vals = groups.values()
        minVal = min(vals)#获取最小个数
        while minVal >= 2:
            rst = True
            for v in vals:
                if v % minVal > 0:#不能统一组合
	                rst = False
	                minVal -= 1
	                break
            if rst:# 都可以完成组合
                break
        return minVal >= 2 and rst
```

当然，上面是按常规的算法步骤写编码，也可以写的更Pythonic一些，如下：

```python
# author: suoxd123@126.com
import collections
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        groups = collections.Counter(deck)
        minVal = min(groups.values())#获取最小个数
        for tmpVal in range(minVal,1,-1):
            if all(groups[k] % tmpVal == 0 for k in groups):
                return True
        return False
```

***
## 解法二（最大公约数）
思路：获取当前个数的最大公约数，如果最大公约数大于1，则满足题目

1. 获取每个数字对应的个数，并取得个数组成的元组
2. 使用minGcd保存最大公约数的值，只有一个时最大公约数等于自己，后面所有元素依次跟其求最大公约数
3. 最大公约数大于1，则返回True，否则返回False

```python
# author: suoxd123@126.com
import collections
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if len(deck) == 0:
            return False
        groups = collections.Counter(deck)
        vals = tuple(groups.values())
        minGcd = vals[0]
        for i in range(1,len(vals)):
            tmpC, tmpB = min(minGcd, vals[i]), max(minGcd, vals[i])
            while tmpC > 0: #辗转相除，获取最大公约数
                tmpC, tmpB = tmpB % tmpC, tmpC
            minGcd = tmpB 
            if minGcd == 1:#最大公约数，等于1了
                break
        return minGcd > 1
```
同样，也可以写的Pythonic一些

```python
# author: suoxd123@126.com
import collections
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        groups = collections.Counter(deck)
        minGcd = min(groups.values())
        for k in groups:
            minGcd = math.gcd(minGcd,groups[k])
        return minGcd > 1
```

欢迎大佬们，随手关注VX公众号【[真相很简单](https://www.zhenxiangsimple.com/categories/tech/math/)】，拍砖指导，查看一题多解

![zhenxiangSimple](https://pic.leetcode-cn.com/f5cdcda21a37ab2959ff8c7fa75e174b326a0b126a27296ba28e906b7309dab1-zhenxiangSimple.jpg)
