喝最烈的酒，骑最野的马，刷最难的题。   -----莎士比亚


我们都知道，分治法最常见的解题思路就是把原问题对半分成左右两个子问题。尝试如下:

在长度为n的字符串S中，取字符串s1，s1中的字符索引范围为 [i, j] (j < n and i <= j)。
取s1的中点mid，令 mid = (i + j) / 2
字符串s1可被中点分为左右两个子字符串（即两个子问题）： 字符串sub1, 索引范围为 [i, mid]; 字符串 sub2，索引范围为 [mid + 1, j]

假设sub1的有效排列数量为a1, sub2的有效排列数量为a2，a2中不满足条件的排列数量为b。为啥a2中会存在不满足条件的排列呢？举个例子吧，若sub1的末字符为 'D' ，a1排列的末尾数字为3，a2排列的首数字为5，则此a2排列必不满足条件。


据此，s1的有效排列数量 = a1 * (a2 - b) * C(j - i + 1, mid - i + 1)

上式中，C(j - i + 1, mid - i + 1) 是[排列组合](https://zhuanlan.zhihu.com/p/41855459)的概念，意思是在 j - i + 1 （即s1对应的数字范围）个数字中，选择 mid - i + 1（sub1对应的数字范围） 个数字出来，选择的顺序无所谓，选择的方式总共有C(j - i + 1, mid - i + 1)种。

接下来，我们似乎只要算出b，整个问题就迎刃而解了。遗憾的是，算出b所需要花费的代价是我们远远不能承受的。这就好像你向神龙许愿，要和喜欢的女孩幸福的生活在一起，为此不惜代价；结果神龙让女孩成了你后妈。 你能接受这样的代价吗

现在不能接受这个代价的小伙伴请跟我一起寻找其他解决办法。

既然判断a2中无效排列需要花费那么大代价，**那有没有方法可以让我们避免判断a2中是否有无效排列呢？不难发现，当a2中全部都为有效排列时，自然就不用判断了**。此时我们发现把原问题对半分为两个子问题的做法，是没办法确保a2全部为有效排列的。原因如下：现假设sub1的末字符和sub2的首字符组成字符串s3。令s3对应的数字为num1, num2, num3。s3的可能情况为  'DI', 'DD', 'ID', 'II'，不可能找到 num1、num2、num3既满足 'DI'，又满足'ID'的。因此，我们需要改变子问题的划分方法。

根据上面的分析，不难发现，子问题的划分和s3是强关联的。我们必须要在s3满足特定条件时再划分子问题。此外，s3对应的数字也必须满足特定条件。**因为若num1、num2、num3都为任意数字，则一定无法在任意情况下都满足s3的要求的三个数之间的大小关系这一条件**。比如若s3 = 'DI'， 此时num1一定要大于num2。因为无论假设num1、num2还是num3为特定数字都没有本质区别。不妨先假设num2为某个特定数字,num1、num3为任意数字。此时，若 s3 = 'DD'，则num1 > num2 > num3，即num2必然不是最小的数字。又因为num1为任意数字，所以num1可以取最小数字，此时存在无效排列。若 s3 = 'II' 时，同理不满足条件。若 s3 = 'DI'，不难发现若 num2 取最小的数字，则一定不存在无效排列。若s3 = 'ID'，则应该取num2为最大的数字。

因 s3 为 'DI' 和 s3 为 'ID'条件对立，取其中之一即可。不妨取 s3为 'DI'。即在s3恰为 'DI'时，令 num2为最小的数字，划分子问题，然后递归求解。此时有状态转移方程： def( i, j ) = def(i, k - 1) * def(k + 2, j) * C(j - i + 1, k - i + 1) 。其中 i, j 表示s1中的字符索引的临界值，k满足s1[k: k + 2] = 'DI'。


不过问题并没有到此结束。我们之前推断出,划分子问题时需要满足num2恰好为最小的数这一条件。但这一条件显然不是对于任意的s1都恒成立的。我们还需要考虑若最小的数的位置不在num2处的情况，并将所有可能情况叠加，得到的才是完整的解。此时，不难发现，若最小的数不在 num2处，那么它只有两个地方可以去，一个是字符串s1的首字符为'I'时，另一个是字符串的末字符为'D'时。

思路清晰了之后，代码也就不难写了：


```python []

MOD = 10**9 + 7 # 模数

# 用于阶乘的辅助函数
def factorial(n):
    if n == 1:
        return 1
    return factorial(n - 1) * n

# 主函数
def getPermsDISeq(i, j, S):
    res = 0
    if i >= j:
        return 1


    if S[i] == 'I':
        res += getPermsDISeq(i + 1, j, S) % MOD

    if S[j] == 'D':
        res += getPermsDISeq(i, j - 1, S) % MOD

    for k in range(i, j):
        if S[k] == 'D' and S[k + 1] == 'I':
            res += getPermsDISeq(i, k - 1, S) * getPermsDISeq(k + 2, j, S) * factorial(j - i + 1) // factorial(k - i + 1) // factorial(j - k) % MOD

    return res % MOD
        

```

上面的的代码是会超时的。所以我们的 getPermsDISeq函数 和 factorial函数都需要动态规划优化一下，以避免重复解。

这里我用的是 python functools库里的lru_cache函数做动态规划缓存的，完整代码如下：


```python []
from functools import lru_cache

class Solution:
    def numPermsDISequence(self, S):
        MOD = 10**9 + 7

        @lru_cache(None)
        def factorial(n):
            if n == 1:
                return 1
            return factorial(n - 1) * n

        @lru_cache(None)
        def getPermsDISeq(i, j, S):
            res = 0
            if i >= j:
                return 1


            if S[i] == 'I':
                res += getPermsDISeq(i + 1, j, S) % MOD

            if S[j] == 'D':
                res += getPermsDISeq(i, j - 1, S) % MOD

            for k in range(i, j):
                if S[k] == 'D' and S[k + 1] == 'I':
                    res += getPermsDISeq(i, k - 1, S) * getPermsDISeq(k + 2, j, S) * factorial(j - i + 1) // factorial(k - i + 1) // factorial(j - k) % MOD

            return res % MOD
        return getPermsDISeq(0, len(S) - 1, S)


```




回顾上面的解题心路，思路竟然和快速排序的思路竟然有异曲同工之妙。**快速排序的难点在于分，在于构造左右两个子序列，使得其满足一个强条件：左边的子序列的最大元素，要小于右边的子序列的最小元素。这道题的难点同样在于分，同样要使子问题满足一个强条件：右子问题中不存在无效排列**。这道题剩下的思路正是基于这个强条件层层推进，最终水到渠成。

个人认为，我们的解题思路背后，其实折射的是我们对分治法的理解：怎么分？为什么这么分？如果做题时很吃力，这可能意味着我们对分治法的理解出了偏差。所以看懂题解只是一个开始，对概念（比如分治法）有更深刻的理解才是真正的进步。有时候，题目刷的再多，也未必能有收获；就好像有时候玩游戏的时间再长也未必能快乐，**只有充钱才能收获真正的满足**。



推荐巩固训练的题目： [戳气球](https://leetcode-cn.com/problems/burst-balloons/)。