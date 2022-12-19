时隔两个月，重新捡起了这道题，终于过了，上次没过就是因为精度问题。


**方法一，斜率`k`匹配法：**

参考了大佬的代码，

首先是计数出每个点重合的个数，获得坐标计数字典`cnt`。

然后就是从计数字典逐个取出点，与其他点比较，斜率相同的累点的数量加进斜率字典`slp`，这样就可以知道某个斜率下，经过当前点的最大数量。

点和斜率都确定了，就可以确定直线了，所以通过全局记录最大值`ans`就可以获得答案了。

`popitem()`逐个取出，是因为点与点是组合关系，所以避免重复计算。

关于精度：因为斜率计算里只用做一次除法计算，作为key，精度上一般不会出问题。

![image.png](https://pic.leetcode-cn.com/d1aee16ed6a08c603c9e009447f51793e540245ed103694d5a3801ad83a8f0f9-image.png)

```python []
class Solution:

    def maxPoints(self, p: List[List[int]]) -> int:
        cnt = collections.Counter((x, y) for x, y in p)
        if len(cnt) <= 2:
            return len(p)
        ans = 0
        for _ in range(1, len(cnt)):
            (x1, y1), t1 = cnt.popitem()
            slp = collections.defaultdict(lambda: t1)
            for (x2, y2), t2 in cnt.items():
                s = (y2 - y1) / (x2 - x1) if x1 != x2 else float('inf')
                slp[s] += t2
            ans = max(ans, max(slp.values()))
        return ans
```

**方法二，直线公式`y = kx + b`匹配法：**

原本勉强能过的乐色版本，因为涉及到了常数项的计算，属于小数的二次四则计算，精度就很容易出问题了。

用了Python自带的`Fraction`分数模块才能保证准确度，但这个模块实在是太慢了，就算是放在方法一里面，也能从44ms升到400ms左右。

如果不用组合迭代器，两个`for`循环就直接超时的那种慢。

用`round`函数也可以解决精度问题，但也一样麻烦不少，而且理论上`round`函数在小数部分的四舍五入也是有坑的，只是这题里面没有体现。

![image.png](https://pic.leetcode-cn.com/b6cd450450a52cf140cc42c8c5e3e9a48d2cb14f35866d1d38c89447b67aeb02-image.png)


```python []
from fractions import Fraction as Frt

class Solution:

    def maxPoints(self, p: List[List[int]]) -> int:
        n = len(p)
        if n <= 2:
            return n
        d = collections.defaultdict(set)
        for i, j in itertools.combinations(range(n), 2):
            (x1, y1), (x2, y2) = p[i], p[j]
            if x1 == x2:
                d[('inf', x1)] |= {i, j}
            else:
                k = Frt(y2 - y1, x2 - x1)
                b = y1 - k * x1
                d[(k, b)] |= {i, j}
        return max(map(len, d.values()))
```

如果不用`Fraction`模块，可以像如下方法这么写，但是`b`的计算过程太大了，影响了整体精度，

`[[0,0],[94911151,94911150],[94911152,94911151]]`这个数据就是唯一过不了的数据，

需要单独摘出来面向测试编程才能过，之前坑也就坑在这，如果不算这个数据，也能挺进几十毫秒以内了。

![image.png](https://pic.leetcode-cn.com/e489d7dbb5d753b5be54c072660c882d86fc317820a9298b6b2f09d275625890-image.png)

```python []
class Solution:

    def maxPoints(self, p: List[List[int]]) -> int:
        n = len(p)
        if n <= 2:
            return n
        d = collections.defaultdict(set)
        for i, j in itertools.combinations(range(n), 2):
            (x1, y1), (x2, y2) = p[i], p[j]
            if x1 == x2:
                d[('inf', x1)] |= {i, j}
            else:
                k = (y2 - y1) / ( x2 - x1)
                b = (y1 * x2 - y2 * x1) / (x2 - x1)
                d[(k, b)] |= {i, j}
        return max(map(len, d.values()))
```
