题目的过程就是假设我们在玩收集游戏，有n个（编号0~n-1）的宝箱和钥匙，编号i的钥匙可以打开宝箱i，有的宝箱是上锁的（status[i]==0），有的没锁（status[i]==1）。
我们有个背包，初始状态下背包中有几个宝箱（initialBoxes），我们先把上锁的宝箱放入背包备用，等以后有钥匙再用，然后把没上锁的宝箱直接打开看，每开一个宝箱会掉落一些新的宝箱（containedBoxes[i]）和新的钥匙（keys[i]），当然还有糖果（candies[i]），我们把新宝箱和钥匙放到背包中备用。如果背包中存在相同编号的一对盒子和钥匙，就可以把它打开拿糖果了，最后直到没有宝箱可以开了游戏结束。

在开始实现上述过程之前有几个疑问
1. 如何模拟这个过程？
整个过程可以用广度优先搜索来模拟。

2. 背包怎么表示？
这里我用了一个两位的二进制数来表示的，XX <=> 背包中是否有钥匙，背包中是否有盒子，有以下四种状态。

二进制 | 意义 | 十进制  
-|-|-
00 | 钥匙盒子都没有 | 0 |
01 | 没钥匙，有盒子 | 1 |
10 | 有钥匙，没盒子 | 2 |
11 | 钥匙盒子都有 | 3 |

3. 没有锁的盒子怎么表示？
对于没上锁的盒子，打开它的条件就是拿到它，所以等价于已经有钥匙的状态。

代码如下：
```
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        stk = [e for e in initialBoxes if status[e] == 1]
        bag = [0] * len(status)
        for i in range(len(status)):
            if i in initialBoxes:
                bag[i] |= 1
            if status[i] == 1:
                bag[i] |= 2
        score = 0
        while stk:
            i = stk.pop()
            score += candies[i]
            for x in containedBoxes[i]:
                if bag[x] == 3: continue
                bag[x] |= 1
                if bag[x] == 3:
                    stk.insert(0, x)
            for j in keys[i]:
                if bag[j] == 3: continue
                bag[j] |= 2
                if bag[j] == 3:
                    stk.insert(0, j)
        return score
```
