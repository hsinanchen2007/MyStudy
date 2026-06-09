# ![D64C8CE0DE82D21CF71B3237D036B908.png](https://pic.leetcode-cn.com/abd03877920d64e462c6c7f4714cb8ea0f848249a7ba89e370c71bdc5b026c02-D64C8CE0DE82D21CF71B3237D036B908.png)

# ⏲视频大约需要 7min
# 🔑今天直接用视频来讲解思路
# # ❓什么情况下才能存储雨水
# 产生凹陷的地方才能存储雨水，那么高度一定是先减后增，所以思路就是维护一个高度递减的 stack，具体思路见视频讲解，感觉会更清楚一些，视频共 7min
# # 视频👇
# ![..._Final1585972179.MP4](0b694bca-960b-468b-a3dc-0a45a1e546b2)

# # 🐼代码部分
# ```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)
        if length < 3: return 0
        res, idx = 0, 0
        stack = []
        while idx < length:
            while len(stack) > 0 and height[idx] > height[stack[-1]]:
                top = stack.pop()  # index of the last element in the stack
                if len(stack) == 0:
                    break
                h = min(height[stack[-1]], height[idx]) - height[top]
                dist = idx - stack[-1] - 1
                res += (dist * h)
            stack.append(idx)
            idx += 1
        return res
# ```
# **如果你喜欢这条题解的话，欢迎点赞**👍 **收藏**🧡 **转发**📧 **评论**💬
# **你的鼓励是我持续创作的动力**
# **(゜-゜)つロ 干杯~**

# # 🎈最后插播一条广告，**优秀的你怎可错过！**
# 欢迎加入[@fuxuemingzhu](/u/fuxuemingzhu/)大佬创建的**打卡网站**＆**微信打卡群**
# 你能收获什么：
# - ✅一群志同道合的小伙伴：与 **280**+ 位小伙伴督促打卡，共同进步
# - ✅良好的问答氛围：有问必答，没准还能收获新知识
# - ✅和刷题大佬们一起玩耍：负雪明烛[@fuxuemingzhu](/u/fuxuemingzhu/)、weiwei哥[@liweiwei1419](/u/liweiwei1419/)、甜姨[@sweetiee](/u/sweetiee/)都在群里

# 就差你了，赶快加入，一起来玩耍吧！
# 加群方式见网站👉[http://group.ojeveryday.com/](http://group.ojeveryday.com/)

# # 🕯
# 2020.4.4 为深切哀悼在抗击新冠肺炎斗争中的牺牲烈士和逝世同胞，举行全国哀悼日
# 愿逝者安息，愿生者奋发，愿祖国昌盛，中国加油！！
# ![a716fd45ly1gdh0lzzv8ij20u01hcdpb.jpg](https://pic.leetcode-cn.com/f8335ea2e319704e42a1101a7e91649c6663400169e3ad4bb7efe42973d76d8b-a716fd45ly1gdh0lzzv8ij20u01hcdpb.jpg){:width=200}