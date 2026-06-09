# ![leetcode.png](https://pic.leetcode-cn.com/cdc32fc07d5e209c1d6235f8ae0a9e926f3d2a1bb07c6d81092df4cf9bf7b192-leetcode.png)
# ⏲阅读大约需要 3min
# 🔑解题思路就是经典的 BFS 模板了，其中要标记访问过的点。

# 方法很经典，就是 BFS 了，通常看到题目里给上下左右移动这种，八成会用 BFS 算法
# 前一阵碰到一个类似的题目👉[1162. 地图分析](https://leetcode-cn.com/problems/as-far-from-land-as-possible/)
# 也有视频讲解👉[1162. 地图分析的视频讲解](https://www.bilibili.com/video/BV1Pp4y1C7Hd/)，如果这道题不太懂的小伙伴可以去看下视频，都是完全一样的思路

# # 🐼代码部分
# ```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        # 计算位数的和
        def add_coor(a, b):
            ans = 0
            while a != 0:
                ans += a % 10
                a //= 10
            while b != 0:
                ans += b % 10
                b //= 10
            return ans

        from collections import deque
        mat = [[0 for _ in range(n)] for _ in range(m)]  # 先创建 m x n 的矩阵并都设为 0
        mat[0][0] = 1  # 将初始位置设为1，代表已经访问过
        temp = deque() # 用一个队列存储即将扩展的点的坐标
        temp.append([0, 0])
        res = 0
        # BFS经典模板
        while temp:
            temp_point = temp.popleft()
            res += 1
            x, y = temp_point
            for x_bias, y_bias in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                new_x = x + x_bias
                new_y = y + y_bias
                if new_x < 0 or new_x > m - 1 or new_y < 0 or new_y > n - 1 or add_coor(new_x, new_y) > k or mat[new_x][
                    new_y] == 1:
                    continue
                mat[new_x][new_y] = 1
                temp.append([new_x, new_y])
        return res
# ```
# (还是要好好锻炼好好休息，一个变量拼写错误，看了半天才看出来，溜了溜了，睡觉去~
# (另：群里的小伙伴越来越多了，真好hh

# **如果你喜欢这条题解的话，欢迎点赞**👍 **收藏**🧡 **转发**📧 **评论**💬
# **你的鼓励是我持续创作的动力**
# **(゜-゜)つロ 干杯~**

# # 🎈最后插播一条广告，**优秀的你怎可错过！**
# 欢迎加入[@fuxuemingzhu](/u/fuxuemingzhu/)大佬创建的**打卡网站**＆**微信打卡群**
# 你能收获什么：
# - ✅一群志同道合的小伙伴：与 **330**+ 位小伙伴督促打卡，共同进步
# - ✅良好的问答氛围：有问必答，没准还能收获新知识
# - ✅和刷题大佬们一起玩耍：**负雪明烛**[@fuxuemingzhu](/u/fuxuemingzhu/)、**wei哥**[@liweiwei1419](/u/liweiwei1419/)、**甜姨**[@sweetiee](/u/sweetiee/)都在群里
# - 🚧非常期待有爬虫和网站开发经验的小伙伴加入，和群主大大一起维护打卡网站&实现各种需求

# 就差你了，赶快加入，一起来玩耍吧！
# 加群方式见网站👉[http://group.ojeveryday.com/](http://group.ojeveryday.com/)