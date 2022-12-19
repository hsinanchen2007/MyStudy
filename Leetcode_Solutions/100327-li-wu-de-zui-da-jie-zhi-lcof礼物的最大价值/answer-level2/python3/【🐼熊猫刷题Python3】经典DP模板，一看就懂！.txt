![leetcode.png](https://pic.leetcode-cn.com/cdc32fc07d5e209c1d6235f8ae0a9e926f3d2a1bb07c6d81092df4cf9bf7b192-leetcode.png)
⏲阅读大约需要 3min
🔑解题思路就是经典的 BFS 模板了，其中要标记访问过的点。
## 解题思路
DP 经典题目，只不过这一次不需要额外开辟 DP 的二维数组，直接在原始的 grid 上进行操作就好，同时用一个全局变量记录到遍历到当前格子时可以达到的最大长度即可，最后返回这个全局变量即可

## 🐼代码部分
```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        # MAX用来存储全局路径和的最小值，先初始化为左上角的值(因为m和n都大于0，那么至少是 1x1 的grid)
        # 因此先将MAX初始化为 grid[0][0]
        # 如果为 1x1 直接返回 MAX 就可以了
        MAX = grid[0][0]
        # 处理第一行：想到达第一行的某个元素只能从左侧过来，所以直接在对应位置进行累加
        for j in range(1, n):
            grid[0][j] += grid[0][j - 1]
            MAX = max(MAX, grid[0][j])
        # 处理第一列：同理，到达第一列的某个元素只能从上方过来，所以直接在对应位置进行累加
        for i in range(1, m):
            grid[i][0] += grid[i - 1][0]
            MAX = max(MAX, grid[i][0])
        # 然后开始 dp 状态转移，到达某一个格子能达到的最大的值等于其自身加上 max(左侧的值，上方的值)
        # 同时更新MAX
        if m > 1 and n > 1:
            for i in range(1, m):
                for j in range(1, n):
                    grid[i][j] += max(grid[i - 1][j], grid[i][j - 1])
                    MAX = max(MAX, grid[i][j])
        return MAX
```

**如果你喜欢这条题解的话，欢迎点赞**👍 **收藏**🧡 **转发**📧 **评论**💬
**你的鼓励是我持续创作的动力**
**(゜-゜)つロ 干杯~**

# 🎈最后插播一条广告，**优秀的你怎可错过！**
欢迎加入[@fuxuemingzhu](/u/fuxuemingzhu/)大佬创建的**打卡网站**＆**微信打卡群**
你能收获什么：
- ✅一群志同道合的小伙伴：与 **330**+ 位小伙伴督促打卡，共同进步
- ✅良好的问答氛围：有问必答，没准还能收获新知识
- ✅和刷题大佬们一起玩耍：**负雪明烛**[@fuxuemingzhu](/u/fuxuemingzhu/)、**wei哥**[@liweiwei1419](/u/liweiwei1419/)、**甜姨**[@sweetiee](/u/sweetiee/)都在群里
- 🚧非常期待有爬虫和网站开发经验的小伙伴加入，和群主大大一起维护打卡网站&实现各种需求

就差你了，赶快加入，一起来玩耍吧！
加群方式见网站👉[http://group.ojeveryday.com/](http://group.ojeveryday.com/)