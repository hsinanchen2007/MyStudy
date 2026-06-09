# 解题思路
无论是暴力算法还是官方算法，这题的核心就是将`可行的分组`转化成是否所有数字的`count`都有`X >= 2`的约数。一旦找到这个对应关系，本题就迎刃而解。

## 心路历程

1. 输出为`true` or `false` -> 只需要证明`X`的存在，而不需要求出`X`的所有可能或证明其唯一性。
2. `X * N = count` 对于每一个数都一定成立 -> 从而发现约数关系

## 官方题解

已经明白解题思路后，只需要求出所有数字的`count`比如`a,b,c,d`的最大公约数`X`是否`>=2`即可。

### 代码

```python3
class Solution(object):
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        from fractions import gcd
        from functools import reduce
        vals = collections.Counter(deck).values()
        return reduce(gcd, vals) >= 2

```

### 知识点

1. 可以使用`collections.Counter`得到`iterm`到`count`的对应关系，测试发现会比自己用字典实现count效率高。

    ```python3
    collections.Counter(list) -> dict() # a dictionary stores iterm->count pairs
    ```

    需要注意的是`collections.Counter(_).values()`返回的是一`iterator`而不是一个`list`

2. `functools.reduce()`

    一个简单的例子
    ```python3
    from functools import reduce
    product = reduce((lambda x, y: x * y), [1, 2, 3, 4])
    # (((x:1, y:2)->x:2, y:3)->x:6, y:4)->24
    # Output: 24
    ```
    等效于
    ```python3
    product = 1
    for i in [1,2,3,4]:
        product *= i

    # Output: 24
    ```

    所以，官方题解里的`reduce(gcd, vals)`等效于

    ```python3
    X = vals[0] # invalid operation as vals is a iterator
    for num in vals:
        X = gcd(X, num)
    ```

3. `fraction.gcd` and `math.gcd`

    其实，`fraction.gcd`已经在`python3.5`Deprecated并被替换成了`math.gcd`。我们来看看官方文档：

    ```
    fractions.gcd(a, b)
    Return the greatest common divisor of the integers a and b. If either a or b is nonzero, then the absolute value of gcd(a, b) is the largest integer that divides both a and b. gcd(a,b) has the same sign as b if b is nonzero; otherwise it takes the sign of a. gcd(0, 0) returns 0.

    Deprecated since version 3.5: Use math.gcd() instead.
    ```

## 首次尝试

其实和官方的思路相像，但是自己用`dict`实现了`count`，并妄想使用`sorted`把`count.values()`排序实现提前终止，但是貌似排序本身消耗了较长时间，没有`reduce`函数来的高效。不解释了看代码吧。

### 题解

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        card_count = dict()
        factor_list = list()
        for card in deck:
            if card not in card_count:
                card_count[card] = 1
            else:
                card_count[card] += 1
        card_values = sorted(card_count.values())
        first = card_values[0]
        if first == 1:
            return False
        else:
            for i in range(2, first+1):
                if first % i == 0:
                    factor_list.append(i)
        for v in card_values:
            tmp = list()
            for factor in factor_list:
                if v % factor == 0:
                    tmp.append(factor)
            if len(tmp) == 0:
                return False
            factor_list = tmp
        return len(factor_list) > 0
```

## 题目变种: 小思考

1. 求出最大的`X`
2. 求出有多少个满足条件的`X`