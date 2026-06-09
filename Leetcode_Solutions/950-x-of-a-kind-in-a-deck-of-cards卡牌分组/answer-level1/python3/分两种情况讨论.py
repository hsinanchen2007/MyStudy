### 解题思路
按照这道题给出的示例来看，可以分为只有一种数字的牌和多种数字的牌两种情况讨论

只有一种数字的牌，只要牌是大于1张的，那么就可以分为1组或1组以上

有多种数字的牌，就需要看每种牌数量的最小公约数是否是大于或等于2的，只有大于或等于2才能分组

### 代码思路
首先我们计算出每种数字的牌出现的次数

然后判断是一种牌的情况还是多种牌的情况
* 一种牌的情况直接判断牌的数量
* 多种牌的情况，选出每种牌数量和其他牌数量进行公约数计算，再根据公约数判断是否能分组


### 代码

```python
class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        # 求最小公约数函数
        def max_common_divisor(x, y):
            for i in range(2,(y if x > y else x)+1):
                if x%i==y%i==0:return i
            return 1

        # 首先求每个数字出现的次数
        count_deck = [deck.count(n) for n in set(deck)]
        if len(count_deck)==1:
            return True if count_deck[0]>1 else False
        else：
            # 将牌数相同的牌去重可以减少for循环的时间复杂度
            count_deck=list(set(count_deck))
            # for循环时间复杂度为不同的牌数量的数量
            for i in range(1,len(count_deck)):
                if max_common_divisor(count_deck[i],count_deck[i-1])==1:
                    return False
                else :continue
            return True

```