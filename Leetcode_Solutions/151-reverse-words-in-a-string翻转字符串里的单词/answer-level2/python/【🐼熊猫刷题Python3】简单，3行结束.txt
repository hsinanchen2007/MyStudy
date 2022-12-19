![leetcode.png](https://pic.leetcode-cn.com/cdc32fc07d5e209c1d6235f8ae0a9e926f3d2a1bb07c6d81092df4cf9bf7b192-leetcode.png)
⏲阅读大约需要 1min

## 🔑解题思路
Python 2行结束，切分-翻转-合并

## 🐼代码部分
```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        tmp=s.split()
        return ' '.join(tmp[::-1])
```

**如果你喜欢这条题解的话，欢迎点赞**👍 **收藏**🧡 **转发**📧 **评论**💬
**你的鼓励是我持续创作的动力**
**(゜-゜)つロ 干杯~**

# 🎈最后插播一条广告，**优秀的你怎可错过！**
欢迎加入[@fuxuemingzhu](/u/fuxuemingzhu/)大佬创建的**每日一题打卡网站**＆**微信打卡群**
你能收获什么：
- ✅一群志同道合的小伙伴：与 **385**+ 位小伙伴督促打卡，共同进步
- ✅良好的问答氛围：有问必答，没准还能收获新知识
- ✅和刷题大佬们一起玩耍：**负雪明烛**[@fuxuemingzhu](/u/fuxuemingzhu/)、**wei哥**[@liweiwei1419](/u/liweiwei1419/)、**甜姨**[@sweetiee](/u/sweetiee/)都在群里
- 🚧期待有**爬虫(requests)和后台(spring boot)** 经验的小伙伴加入，和群主大大一起**维护网站&实现需求**

就差你了，赶快加入，一起来玩耍吧！
加群方式见网站👉[http://group.ojeveryday.com/](http://group.ojeveryday.com/)
