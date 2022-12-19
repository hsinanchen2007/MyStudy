公众号连载每日一题leetcode题解，还有各种真题套路解析，欢迎关注。

![](https://pic.leetcode-cn.com/2a15d78b4b977527a4d95f2bb238db8c82b7d133878dbf168b4b972271818c58.jpg)


题目汇总： [leetcode](http://flypython.com/leetcode/) 


## 思路

开局一堆字加图，表达的意思其实很简单。车只能四个方向直走，只能吃掉敌人，友军会挡路。

我们需要的是先找到自己的车(R)在哪里，然后大杀四方，看看遇到了多少次敌人(p)。

开始循环找到R的位置，然后把X，Y轴上的所有障碍"."都清空，这样我们的车R就直接和敌人p交手了。敌人p可能在R的两侧，所有需要分别对"pR"和"Rp"进行计数，统计出与敌人的交手次数，当然车是百战百胜的，这样就得出了杀敌数。

## 代码

```
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(len(board)):
            if 'R' in board[i]:
                raw = i
                break
        colum = board[raw].index('R')

        r = ''.join(board[raw]).replace('.','')
        c = ''.join(i[colum] for i in board).replace('.','')

        return r.count("Rp") + r.count("pR") + c.count("Rp") + c.count("pR")

```

此题公众号链接： [「每日一题」第26天——999. 车的可用捕获量](https://mp.weixin.qq.com/s/QxRZSbMjqFpnlD53au2q1w)