
![image.png](https://pic.leetcode-cn.com/15b171f287903d85aa6f4a776c6b5fcdafe7c52c17708b7df2f05548d49433ae-image.png)![image.png](https://pic.leetcode-cn.com/8d66421c5d7f0cd94ec0737645b95af7647002fe921b9012bf574461b0db7e44-image.png)


由函数的单调可知，对于任意$x, y$ 属于区间$[1, 1000]$，

存在$f(0, y) < f(0 + x, y)$

令$f(0, y) == 1$，即取最小值，

考虑单调性$f(1, y) > f(0, y) == 1$，

由于接口的整形特征可得$f(1, y) >= 2$，

同理归纳可得$f(i, y) >= i + 1$，

令 $i == z$，则有$f(z, y) >= z + 1$

同理可得$f(x, z) >= z + 1$

即当$x >= z$ 或 $y >= z$时，有$f(x, y) >= z + 1 > z$

所以查找的时候$x, y$只用考虑在$[1, ..., z]$的范围里就可以了，不管是直接遍历还是二分查找都可以直接用这个范围，遍历$[1, 1000] * [1, 1000]$完全多余。

**方法一：**

基于这个思路，先来个一行版的边长为$z$的正方形遍历，最快在88ms，50%左右，时间复杂度$O({Z}^{2})$。

```python []
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        return filter(lambda x: customfunction.f(*x) == z, itertools.product(range(1, z + 1), repeat=2))
```

**方法二：**

然而，这也是可以优化的，再次考虑到函数的单调性，

当$f(x, y) <= z$时，有$f(x, y - 1) < z$，即对于每个$y$，最多存在一组$(x, y)$数对满足$f(x, y) == z$，

故在遍历y的时候可以考虑从大往小遍历，

如果$f(x, y) == z$，则可输出，

如果$f(x, y) < z$，则$x = x + 1$，保留当前的$y$值，从$y$开始继续向下遍历。

基于此原理，可得时间复杂度为$O(Z)$。

```python []
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        y, g = z, customfunction.f
        for x in range(1, z + 1):
            while y:
                d = g(x, y) - z
                if d <= 0:
                    if not d:
                        yield [x, y]
                    break
                y -= 1
```

语法上优化了几个点：

减少重复计算，减少赋值，减少点调用；

`for`循环比`while`快一倍左右，基于前者的前提下优先用`for`语句；

`yield`生成器节省函数内的输出空间，不过这题数据也比较小，其实没啥影响；

存在语句相较于比较运算要快`40%`左右。