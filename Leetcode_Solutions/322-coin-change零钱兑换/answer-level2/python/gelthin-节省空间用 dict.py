### 解题思路
有一点同习题 [377. 组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)
不过一个是计算最小数量 coin, 一个是统计有多少中可能的找零方法。


本题接连错了 5 次。
+ 执行出错 对样例[1] 0，index out of range
+ 解答错误 对样例[1] 0，输出 -1 这里评论区第一条就是此
+ 执行出错 [1,2147483647] 2， coin 的可取值大小远大于 amount, 导致 DP[coin] 出错， 若取 DP = [None]*(max[max(coin),amount]) 可能会导致数组所需空间过大。
+ 解答错误 重写代码，直接蛮力递归，没有使用DP amount 数组。 但又忘记了 [1] 0 样例导致错误
+ 超出时间限制: 没有用DP，直接蛮力递归，导致超出时间限制

后来使用 dict 结构，只保留可以用 coin 值组合得到的值，避免开一个大的 DP 数组内存炸了。



最开始是直接蛮力递归，不保存计算中间值，导致重复计算了很多子问题，效率根本不行。

然后想从上到下（从大到小）使用 DP，当用 DP=[-1]*(amount+1) 开辟数组时，发现内存直接炸了。

看了官方题解，从下到上（从小到大）计算，避免枚举大量状态，效率高很多，


就是有点不太理解下面的代码，先枚举只使用第一种 coin, 所能得到的解，再枚举使用第二种 coin 所能得到的解，... 最后枚举最后一种 coin 所能得到的解，能够不偏不漏得到最终解。

原本 DP 直接代表了最优解， DP[i] = min_coin (DP[i-coin]+1)
但下面的代码， 在只枚举到第一个硬币时，DP 代表的是只使用第一枚硬币所对应的最优解。 有点像 Floyd 算法，枚举所有可能的中间节点 ，k-i-j


```python3
DP = dict()
DP[0] = 0
for coin in coins:
    for x in range(coin, amount+1):
        update DP[x]
```

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        DP = dict() ## 如果直接用 DP = [-1]*(amount+1) 内存会炸掉
        DP[0] = 0
        for coin in coins:
            for x in range(coin, amount+1):
                if x in DP and (x-coin) in DP:
                    DP[x] = min(DP[x-coin]+1, DP[x])
                elif (x-coin) in DP:
                    DP[x] = DP[x-coin]+1  ## 这里恰好利用了 DP[0]=1 得到 DP[coin]=1
                elif x in DP and not (x-coin) in DP:
                    pass
                else:
                    pass
        if amount in DP:
            return DP[amount]
        else:
            return -1
```

#### 原来的无法通过的错误代码

``` python3 
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:  # [1] 0
            return 0
        if not coins or amount < min(coins): # [1] 0
            return -1
        DP = [-1]*(amount+1)   ## [1,2147483647] 2 过不了，不能开辟一个大空间全部存储, 应该用递归
        for x in coins:
            DP[x] = 1
        for i in range(amount+1):
            tmp = -1
            for x in coins:
                if i-x>=0 and DP[i-x] != -1:
                    if tmp == -1:
                        tmp = DP[i-x] + 1
                    else:
                        tmp = min(DP[i-x]+1, tmp)
            if DP[i] == -1:  ## 少了这一句，把 1,3,,5 都改成-1 了
                DP[i] = tmp
        return DP[amount]
```
