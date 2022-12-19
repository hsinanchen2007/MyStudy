![image.png](https://pic.leetcode-cn.com/bd1bb22ace6396ecc9bf207c010226c84ee2cd9a0a9e9f49ab2dc65ab61f3ec6-image.png)


### 0 概述

本题用动态规划(Dynamic Programming)，简称DP，简单易理解，不少老哥都讲得很详细了，尤其是前排labuladong大佬和powcai大佬，讲道理，很优秀。这篇题解，侧重于分享BFS的思路和代码。

### 1 动态规划
要找出最少的硬币数量去达成规定的金额，可以考虑从最少的金额，如1元，开始慢慢往规定的金额靠近。每1元的提升，都可以算得出，达成此目标所需的最少硬币数量。状态方程可以写作
$$
f(x) = min f(x-coin_i) + 1
$$
$f(x)$代表凑成$x$元所需要的最少硬币数量

**官方给的这个图表跟着走一遍，保证醍醐灌顶，豁然开朗**
![image.png](https://pic.leetcode-cn.com/a13e7132d65b37ab1c4471a0ac53bf64ceb8b7e0606d32e9b43154fab8be3d41-image.png)

代码如下：

```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        flag = float('inf')
        dp = [0] + [flag] * amount
        
        for i in range(1,amount+1):
            dp[i] = min([dp[i-c] if i>=c else flag for c in coins]) + 1
            
        return -1 if dp[amount] == flag else dp[amount]
```

### 2 BFS

**BFS的主要思想是，直接观察多个硬币可以组成多少种不同的金额数量，从1个硬币开始慢慢往上提升，这样就能算出不同的金额范围。**

假如`coins = [1,2,5]`，1一个硬币的金额大小就有三种可能，用`level`来保存这些金额，即`level = [1,2,5]`，我们再设置一个列表`seen = [0,1,2,5]`，这表示咱已经用最小的硬币数量达到了这些金额大小，这个列表的意义在于，如果我们用2个硬币计算可以达成多少种金额数量时，1个硬币就能实现的金额，2个硬币就不必关心这个金额了。

来，现在手里拿下2个硬币，那么金额的范围就变成了，`level`里的每个数与`coins`里的每个数分别相加，再取交集的结果，就是`level = [2,3,4,6,7,10]`，由于`2`已经在`seen = [0,1,2,5]`，所以把`level`中的`2`去掉，即`level = [3,4,6,7,10]`。

去掉`2`的思路是很朴素的，因为`seen`表示，已经用最小的硬币数量达成的金额，现在已然手持两枚硬币，却出现`2`，这样一个一枚硬币就能达到的金额，实在是多余，故去掉`2`。

同样的道理，手里再拿下3个硬币时，`level`所代表的的金额范围进一步扩大，显然此时我们所需要的金额`amount = 11`会出现在`level`中，那么直接就返回`3`。

**如果一直在多拿硬币却找不到`amount`怎么办呢？**

我们可以对`level`进行限制，即每次`level`寻找新的金额时，这个金额必须小于等于`amount`，大于的数字都不采用，这样一来随着硬币增加，一直找不到最大值的话，`seen`中的数会变多，从而反作用于`level`，那么`level`就会慢慢变成空，这时候就输出`-1`即可。

代码如下：

```
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount == 0:
            return 0
        level, cur_sum, i = [0], [], 0
        seen = [True] + [False] * amount
        
        while level:
            i += 1
            for cur in level:
                for coin in coins:
                    new_sum = cur + coin
                    if new_sum <= amount:
                        if not seen[new_sum]:
                            if new_sum == amount:
                                return i
                            seen[new_sum] = True
                            cur_sum.append(new_sum)
            level, cur_sum = cur_sum, []
            
        return -1
```

同样的BFS思路，用集合方式，**实现一个蒂花之秀解法：**

```
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        level = seen = {0}
        i = 0
        
        while level:
            if amount in level:
                return i
            level = {a+c for a in level for c in coins if a+c<=amount} - seen
            seen |= level
            i += 1
        
        return -1
```
`seen |= level`就是`seen = seen | level`，也就是`seen`和`level`取个并集的意思~

![image.png](https://pic.leetcode-cn.com/0c98e37364977ce64ad5719e3615600590b562dd4429b2bc7d4dbaeed7678ec8-image.png)





