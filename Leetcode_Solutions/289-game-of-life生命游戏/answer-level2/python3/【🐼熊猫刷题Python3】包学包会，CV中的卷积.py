# ![leetcode.png](https://pic.leetcode-cn.com/ae53949a5779e631df46daac47f6772958b1bbf536251b1fa4b9fc13bf9711b4-leetcode.png)
# ⏲阅读大约需要 4min
# 🔑介绍了解题思路、卷积概念、卷积示意图、代码
# 看到这道题的时候，第一时间想到的就是卷积运算了(然而其实是这样的，A在B上摩擦摩擦，这不就是卷积吗？！😂
# 但这种方法时空开销大，这里只是提供一种便于理解的思路，不喜勿喷，谢谢😜
# # ❓那么什么是卷积？
# 用一个模板 (kernel) 和一幅图像进行卷积，对于图像上的一个点，让模板的原点和该点重合，然后模板上的点和图像上对应的点相乘，然后各点的积相加，就得到该点的卷积值。对图像上的每个点都这样处理。(注：这里的卷积是 CV 中常用的卷积和数字信号处理中的略有区别)

# 下面的图是一个没有补零 (zero padding) 的2维卷积的示意图，深蓝色的 3 x 3 的正方形就是所说的 kernel，下面的浅蓝色就是图像，通过滑动 kernel 并且将 kernel 的对应位置和它覆盖区域的对应位置的数值相乘并加和，就可以得到卷积后某一个位置的值，大家可以自己看着图计算一下
# ![v2-84a92b2e7cce6f31ad9fba1e57841198_b.webp](https://pic.leetcode-cn.com/acff40cd915c2a16d52eb33d9b152e9b6cff1bbd5bb12b5679d254e926be2eb0-v2-84a92b2e7cce6f31ad9fba1e57841198_b.webp)


# 下图展示的是带 zero padding 的 2D 卷积操作，也是为了方便处理我们的数据(本题中同样采用补零，如果不在原始的 board 的周围补零，对于 board 最外围的一圈值处理起来比较麻烦，而通过补零我们可以统一进行处理)
# ![6e5c4d003f584cf1af342eae71dc31aa_th.jpg.gif](https://pic.leetcode-cn.com/163bfccfd90c7e720b493186760a00a26c238007de6d35911855d4360242b16b-6e5c4d003f584cf1af342eae71dc31aa_th.jpg.gif)
# # 🐼代码部分
# ```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        import numpy as np
        r, c = len(board), len(board[0])
        # 下面两行做 zero padding
        board_exp = np.array([[0 for _ in range(c + 2)] for _ in range(r + 2)])
        board_exp[1:1 + r, 1:1 + c] = np.array(board)
        # 设置卷积核
        kernel = np.array([[1, 1, 1], [1, 0, 1], [1, 1, 1]])
        # 开始卷积
        for i in range(1, r + 1):
            for j in range(1, c + 1):
                # 统计细胞周围 8 个位置的状态
                temp_sum = np.sum(kernel * board_exp[i - 1:i + 2, j - 1:j + 2])
                # 按照题目规则进行判断
                if board_exp[i, j] == 1:
                    if temp_sum < 2 or temp_sum > 3:
                        board[i - 1][j - 1] = 0
                else:
                    if temp_sum == 3:
                        board[i - 1][j - 1] = 1  
# ```

# 2020.4.1 互联网带来了无限的机遇与红利，老罗的首次抖音带货，薇娅直播间卖起了火箭，中国电商史上魔幻的一夜，晚安。

# **如果你喜欢这条题解的话，欢迎点赞**👍 **收藏**🧡 **转发**📧 **评论**💬
# **你的鼓励是我持续创作的动力**
# **(゜-゜)つロ 干杯~**

# # 🎈最后插播一条广告，**优秀的你怎可错过！**
# 欢迎加入[@fuxuemingzhu](/u/fuxuemingzhu/)大佬创建的**打卡网站**＆**微信打卡群**
# 你能收获什么：
# - ✅一群志同道合的小伙伴：与 **280**+ 位小伙伴督促打卡，共同进步
# - ✅良好的问答氛围：有问必答，没准还能收获新知识
# - ✅和刷题大佬们一起玩耍：**负雪明烛**[@fuxuemingzhu](/u/fuxuemingzhu/)、**weiwei哥**[@liweiwei1419](/u/liweiwei1419/)、**甜姨**[@sweetiee](/u/sweetiee/)都在群里

# 就差你了，赶快加入，一起来玩耍吧！
# 加群方式见网站👉[http://group.ojeveryday.com/](http://group.ojeveryday.com/)