![leetcode.png](https://pic.leetcode-cn.com/cdc32fc07d5e209c1d6235f8ae0a9e926f3d2a1bb07c6d81092df4cf9bf7b192-leetcode.png)
⏲阅读大约需要 5min
🔑分享解题思路及对应视频；总结 Python 中赋值、深拷贝、浅拷贝、切片中的坑操作并附视频讲解

今天的题解主要两个部分：
1. 题目思路讲解（配视频）
2. **总结Python赋值、深拷贝、浅拷贝、切片中的坑操作（配视频）**
第二部分是重点，有时间的小伙伴可以仔细研究一下，说不定以后就有帮助呢。

# Part 1 题目思路
先附上讲解视频👇：
![...20-04-07-1334-08.mp4](48c33c4e-c78d-4f79-9e99-65d63e70ea84)
今天的题就很容易想了，通过观察可以看出 matrix 顺时针转 90 度就是矩阵先上下翻转，后沿对角线翻转。
话不多说直接看代码👇

# 🐼代码部分
写法 1 :
```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        length = len(matrix)
        # 先在纵向上进行上下翻转
        # 切片会创建新的对象进而开辟新地址
        matrix[:] = matrix[::-1]
        # 然后沿对角线翻转
        for i in range(length):
            for j in range(i):
                matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]
```
写法 2 :
```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        length = len(matrix)
        # 先在横向上进行镜面翻转
        # 这里只用一个tmp变量的空间来完成上下翻转的操作
        for i in range(length // 2):
            for j in range(length):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[length - 1 - i][j]
                matrix[length - 1 - i][j] = tmp

        # 然后沿对角线翻转
        for i in range(length):
            for j in range(i):
                matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]
```
# Part 2 Python中赋值、深拷贝、浅拷贝、切片中的坑
详细说明见下方视频，感觉还是用视频解释清楚些👇
![...-07-1352-23_x264.mp4](c1c433e9-f335-44a8-ad3a-0be4623a9b7c)
有小伙伴说左侧代码为什么错没说清，特此做了下面的 PPT 进行解释,希望有所帮助👇

<![幻灯片1.PNG](https://pic.leetcode-cn.com/32390e8c5ea7de960a9a1d2013e1faae3d966cb548f4ca09255fcc98c7a1d6be-%E5%B9%BB%E7%81%AF%E7%89%871.PNG),![幻灯片2.PNG](https://pic.leetcode-cn.com/8a27e42f6dffb4d57ba356eaadde6c332d856a023c030606eba5fa7b06a3ec62-%E5%B9%BB%E7%81%AF%E7%89%872.PNG),![幻灯片3.PNG](https://pic.leetcode-cn.com/556c9f0e3d0e9ae80fdf0b9494b86849c1eeb3877ff79a73582529debd738617-%E5%B9%BB%E7%81%AF%E7%89%873.PNG),![幻灯片4.PNG](https://pic.leetcode-cn.com/e0c8f07adca586887858cb26d5644037fa68f54d13ec29bd8bc8b2673fb59697-%E5%B9%BB%E7%81%AF%E7%89%874.PNG)>

视频中的代码见下方，共 3 页👇

<![幻灯片1.PNG](https://pic.leetcode-cn.com/27feb0233090917b7735a9d622e29162b5a2bbca04a1d3f821fa3470a23c1ea1-%E5%B9%BB%E7%81%AF%E7%89%871.PNG),![幻灯片2.PNG](https://pic.leetcode-cn.com/7f7e551bfec3e1a69667ae2d5ab6611529228057ec2bfe506f2faf56a5919e2f-%E5%B9%BB%E7%81%AF%E7%89%872.PNG),![幻灯片3.PNG](https://pic.leetcode-cn.com/063b4777702bfa17a7bf5a6f049fd05a5917ad377e10cc25b78c79480ce5436a-%E5%B9%BB%E7%81%AF%E7%89%873.PNG)>

附参考资料：
[Python的赋值、切片、浅拷贝与深拷贝的区别](https://www.jianshu.com/p/5cf2aebdf7c5)
[Python 直接赋值、浅拷贝和深度拷贝解析](https://www.runoob.com/w3cnote/python-understanding-dict-copy-shallow-or-deep.html)

**如果你喜欢这条题解的话，欢迎点赞**👍 **收藏**🧡 **转发**📧 **评论**💬
**你的鼓励是我持续创作的动力**
**(゜-゜)つロ 干杯~**

# 🎈最后插播一条广告，**优秀的你怎可错过！**
欢迎加入[@fuxuemingzhu](/u/fuxuemingzhu/)大佬创建的**打卡网站**＆**微信打卡群**
你能收获什么：
- ✅一群志同道合的小伙伴：与 **320**+ 位小伙伴督促打卡，共同进步
- ✅良好的问答氛围：有问必答，没准还能收获新知识
- ✅和刷题大佬们一起玩耍：**负雪明烛**[@fuxuemingzhu](/u/fuxuemingzhu/)、**weiwei哥**[@liweiwei1419](/u/liweiwei1419/)、**甜姨**[@sweetiee](/u/sweetiee/)都在群里

就差你了，赶快加入，一起来玩耍吧！
加群方式见网站👉[http://group.ojeveryday.com/](http://group.ojeveryday.com/)