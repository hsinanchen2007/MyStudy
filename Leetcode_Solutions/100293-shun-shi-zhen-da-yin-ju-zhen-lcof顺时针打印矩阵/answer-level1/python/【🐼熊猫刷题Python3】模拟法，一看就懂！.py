![leetcode.png](https://pic.leetcode-cn.com/cdc32fc07d5e209c1d6235f8ae0a9e926f3d2a1bb07c6d81092df4cf9bf7b192-leetcode.png)
⏲阅读大约需要 3min

## 🔑解题思路
很纯粹的模拟法，见注释

## 🐼代码部分
```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # 模拟法
        res = []
        row_up, row_down = 0, len(matrix)  # 定义行的上下边界
        col_left, col_right = 0, len(matrix[0])  # 定义列的上下边界
        all = row_down * col_right  # 计数判断是否已经全部遍历
        count = 0
        while row_up < row_down and col_left < col_right:
            for j in range(col_left, col_right):  # 从左至右扫描上边界
                res.append(matrix[row_up][j])
                count += 1
            row_up += 1
            if count == all:
                break
            for i in range(row_up, row_down):  # 从上至下扫描右边界
                res.append(matrix[i][col_right - 1])
                count += 1
            col_right -= 1
            if count == all:
                break
            for j in range(col_right - 1, col_left - 1, -1):  # 从右至左扫描下边界
                res.append(matrix[row_down - 1][j])
                count += 1
            row_down -= 1
            if count == all:
                break
            for i in range(row_down - 1, row_up - 1, -1):  # 从下至上扫描下边界
                res.append(matrix[i][col_left])
                count += 1
            col_left += 1
            if count == all:
                break
        return res
```

**如果你喜欢这条题解的话，欢迎点赞**👍 **收藏**🧡 **转发**📧 **评论**💬
**你的鼓励是我持续创作的动力**
**(゜-゜)つロ 干杯~**

# 🎈最后插播一条广告，**优秀的你怎可错过！**
欢迎加入[@fuxuemingzhu](/u/fuxuemingzhu/)大佬创建的**打卡网站**＆**微信打卡群**
你能收获什么：
- ✅一群志同道合的小伙伴：与 **360**+ 位小伙伴督促打卡，共同进步
- ✅良好的问答氛围：有问必答，没准还能收获新知识
- ✅和刷题大佬们一起玩耍：**负雪明烛**[@fuxuemingzhu](/u/fuxuemingzhu/)、**wei哥**[@liweiwei1419](/u/liweiwei1419/)、**甜姨**[@sweetiee](/u/sweetiee/)都在群里
- 🚧非常期待有爬虫和网站开发经验的小伙伴加入，和群主大大一起维护打卡网站&实现各种需求

就差你了，赶快加入，一起来玩耍吧！
加群方式见网站👉[http://group.ojeveryday.com/](http://group.ojeveryday.com/)
