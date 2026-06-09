![leetcode.png](https://pic.leetcode-cn.com/cdc32fc07d5e209c1d6235f8ae0a9e926f3d2a1bb07c6d81092df4cf9bf7b192-leetcode.png)
⏲阅读大约需要 10min
🔑介绍了二维 dp 解题思路

个人感觉要在以下几点重点理解
- 理解 word1 上的删除等价 word2 上的增加, word1 上的增加等价于 word2 上的删除
- 2维的 dp array 中某一点 dp[i][j] 的意义: word1[ : i] 到 word[ : j] 转换所需要的最小的数目
- 不太需要关注具体进行了删除、增加还是替换操作，而是专注于 a 状态到 b 状态所需要的步数

具体讲解请戳视频👇
![...20-04-06-1051-02.mp4](006a4b53-5a29-4b15-86f5-39e4e1ea8245)
题解的图如下👇
![微信截图_20200406111832.png](https://pic.leetcode-cn.com/bdc3366f3bac7d1650ec3a2f2f5a8170147149c04227d8c9eba4ad41c64383f0-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200406111832.png){:width=200}
# 🐼代码部分
```Python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)
        dp = [[float('inf') for _ in range(n + 1)] for _ in range(m + 1)]
        # 初始化
        for i in range(m + 1):
            dp[i][0] = i
        for i in range(n + 1):
            dp[0][i] = i
        # 状态转移
        # i , j 代表 word1, word2 对应位置的 index
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # 如果word1[:i][-1]==word2[:j][-1]
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                # 否则从三种状态中选一个最小的然后 +1
                else:
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1
        return dp[m][n]
```
**如果你喜欢这条题解的话，欢迎点赞**👍 **收藏**🧡 **转发**📧 **评论**💬
**你的鼓励是我持续创作的动力**
**(゜-゜)つロ 干杯~**

# 🎈最后插播一条广告，**优秀的你怎可错过！**
欢迎加入[@fuxuemingzhu](/u/fuxuemingzhu/)大佬创建的**打卡网站**＆**微信打卡群**
你能收获什么：
- ✅一群志同道合的小伙伴：与**289**+位小伙伴督促打卡，共同进步
- ✅良好的问答氛围：有问必答，没准还能收获新知识
- ✅和刷题大佬们一起玩耍：**负雪明烛**[@fuxuemingzhu](/u/fuxuemingzhu/)、**weiwei哥**[@liweiwei1419](/u/liweiwei1419/)、**甜姨**[@sweetiee](/u/sweetiee/)都在群里

就差你了，赶快加入，一起来玩耍吧！
加群方式见网站👉[http://group.ojeveryday.com/](http://group.ojeveryday.com/)