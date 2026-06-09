### 解题思路
瞄了一眼高赞题解，素数筛是什么鬼啊，，，所以我来写个简洁的。

题目等价于选择一个数字 X，使它能除尽所有数字相同的牌的数量。这意味着对所有数字相同的牌的数量取一个最大公约数，则 X 是这个最大公约数的任意一个约数。

现在要求 X>=2，那么只要最大公约数>=2就可以了。

代码中 [deck.count(i) for i in set(deck)] 用于计算所有数字相同的牌的数量；reduce(gcd, [...]) 用于对整个数组取最大公约数，最后判等即可。

### 代码

```python
class Solution(object):
    def hasGroupsSizeX(self, deck):
        return reduce(__import__('fractions').gcd, [deck.count(i) for i in set(deck)])!=1

```