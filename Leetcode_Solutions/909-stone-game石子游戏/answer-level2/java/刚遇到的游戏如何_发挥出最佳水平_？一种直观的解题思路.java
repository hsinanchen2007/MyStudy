看到这里之前想必你已经知道，这道题目有一种“取巧”的解法，我们先针对它做出解析，依据题干可知
1. 石堆的总数是偶数
2. 石子的总数是奇数

将石堆排序，**奇数编号**的石堆拥有的石子总数和**偶数编号**石堆拥有的石子总数相比，**总有一个大于另外一个**。 
因为石堆的个数是偶数，每一回合先手玩家总会单方面决定他们两个选取石堆的编号的奇偶性，换句话说，先手玩家可以选择**永远拿奇数编号石堆**或者**偶数编号石堆**，结合上面的结果可知先手玩家必胜，因此次此道题目可以直接 return true.

当然我们做题的目的不是为了ac具体的某一道题目，更重要的是提高分析能力、学习套路，上述取巧办法在题目稍作变化之后也许就会失效，不是一种好的思考方向。比如上述的奇偶必胜策略并不是获胜的最优策略，最优策略得到是什么？是否能计算出Alex最优能拿多少个？针对这道题目，“**通用**”的解题思路可以是这样的。

## 思路
回到题目要求，我们需要得出基于现有游戏规则得出两人都发挥最佳水平时返回的结果。关键在于什么是“最佳水平”？面对不熟悉的领域，尤其是刚刚才阅读了规则的游戏，由我们自己短时间内掌握最佳游戏策略并一步一步替两人做决策是不现实的，思路如果朝着这方向去推演会陷入泥潭，想到策略容易，想到最优、唯一的策略并且通过验证非常困难。

那要如何发挥最佳？
有过作弊经验的同学（当然你懂我指的是无伤大雅的游戏作弊）可能已经想到，任何博弈都有一种永恒**不变的最佳策略**，拿着答案/结果去玩。
不管处于什么情况，不管条件如何变化，最佳策略只需要从答案里选择正确、从已经发生的**结果里选择最优**的那一个即可。在编程领域，我们可以通过使用**递归**实现这种策略。

## 算法
回到本题，将所有石堆包含的石子数按照石堆的排列顺序放入数组`pile`中，使用 `stones(left,right)` 表示Alex可以得到的最大石子总数，`left`指向代表挑选完后剩余石堆石子数的数组的开始，`right`指向数组的末尾。

对Alex来讲，有两个选择摆在面前，拿最左侧或最右侧的，这一步的**最佳策略**是什么？其实很简单，拿能让自己得到更多石子的那一边 -- 选取的石堆里的石子数加上 下一步Lee做操作后能得到的石子数。
```
stones(left,right) = Math.max(piles[left] + Round1LeesMove1 , piles[right] + Round1LeesMove2)
```
下一步是Lee的操作，对于Lee来讲，他也要拿最多的石子，换句话说他要让Alex拿到的石子最少（石子总数一定，两者等价）。因为我们定义了`stone`来记录Alex能拿的石子数（这一步并不计算Lee得到的石子数，有点像打升级，不得分的一方努力赢分的目的是让对方得分最少），Lee的操作应该是这样的
```
// Alex takes piles[left] previously 
LeesMove1 = Math.min(Round2AlexsNextMove1 , Round2AlexsNextMove2)
// Alex takes piles[right] previously
LeesMove2 = Math.min(Round2AlexsNextMove3 , Round2AlexsNextMove4)
```
Round2AlexNextMove 1、2、3、4 代表了得到新石堆之后应该作出的决策，此时的处境由前面的选择决定，例如上一回合Alex选择拿`pile[left]`, Lee选择拿`pile[right]`, 剩下的数组或者说石堆则为`[left+1,...,right-1]`，因此Round2AlexNextMove1对应
```
Math.max(piles[left+1] + Round2LeesMove1 , piles[right-1] + Round2LeesMove2)
```

由此得到求(每回合)最大值的findMax方程(省略条件处理)
```
private int findMax(int left, int right, int[] piles) {
    return Math.max(
        piles[left] + Math.min(findMax(left + 2, right, piles), findMax(left + 1, right - 1, piles)), 
        piles[right] + Math.min(findMax(left + 1, right - 1, piles), findMax(left, right - 2, piles))
    );
}
```

通过调用方程可算出Alex可以得到的最大石头数量，与石子总数相比我们可以知道Alex是否能赢。当然此题目Alex必应，不过题目稍微变化一下，比如求出Alex能得到的最大石子数、石子数之差等我们的解法就可以派上用场，能够应对要求甚至题目本身的变化。

## 代码
下面是我写的java代码，使用了mem来保存计算结果避免重复计算提高效率。

```
// Source : https://leetcode.com/problems/stone-game/
// Id     : 877
// Author : Fanlu Hai | https://github.com/Fanlu91/FanluLeetcode
// Date   : 2019-09-18
// Topic  : Dynamic Programming
// Level  : Medium
// Other  :
// Tips   :
// Result : 100.00% 100.00%

public class StoneGame {

    /**
     * explained below:
     * https://leetcode.com/problems/stone-game/discuss/384891
     *
     * @param piles
     * @return
     */
    // 51.82% 5 ms 84.85%
    public boolean stoneGame(int[] piles) {

        int sum = 0;
        for (int i : piles) {
            sum += i;
        }
        int[][] mem = new int[piles.length][piles.length];
        return 2 * findMax(0, piles.length - 1, piles, mem) >= sum;
    }

    private int findMax(int left, int right, int[] piles, int[][] mem) {
        if (left < 0 || right < 0 || left > right)
            return 0;
        if (mem[left][right] != 0)
            return mem[left][right];
        if (left == right) {
            mem[left][right] = piles[left];
            return piles[left];
        }

        int max = Math.max(piles[left] + Math.min(findMax(left + 2, right, piles, mem), findMax(left + 1, right - 1, piles, mem)),
                piles[right] + Math.min(findMax(left + 1, right - 1, piles, mem), findMax(left, right - 2, piles, mem)));
        mem[left][right] = max;
        return max;
    }


    /**
     * Just return true
     * Alex is first to pick pile.
     * piles.length is even, and this lead to an interesting fact:
     * Alex can always pick odd piles or always pick even piles!
     * <p>
     * In the description, we know that sum(piles) is odd.
     * If sum(piles[even]) > sum(piles[odd]), Alex just picks all evens and wins.
     * If sum(piles[even]) < sum(piles[odd]), Alex just picks all odds and wins.
     */
    // 100.00% 100.00%
    public boolean stoneGameDirectAnswer(int[] piles) {
//    public boolean stoneGame(int[] piles) {
        return true;
    }
}
```

如有问题欢迎讨论指正。