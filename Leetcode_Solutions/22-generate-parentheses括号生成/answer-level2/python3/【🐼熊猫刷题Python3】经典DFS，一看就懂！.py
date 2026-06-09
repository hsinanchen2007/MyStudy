![leetcode.png](https://pic.leetcode-cn.com/cdc32fc07d5e209c1d6235f8ae0a9e926f3d2a1bb07c6d81092df4cf9bf7b192-leetcode.png)
⏲阅读大约需要 3min

🔑解题思路就是经典的 DFS ,要点已经写在注释中

## 🐼代码部分
```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(cur, l_num, r_num):
            if l_num == 0 and r_num == 0:
                # 如果可以放置的左右括号数为0，说明已经已经完成一个有效组合，直接将字串加入结果集
                res.append(cur)
                return
            if r_num > 0 and r_num > l_num:
                dfs(cur + ')', l_num, r_num - 1)
            if l_num > 0:
                # 如果可以放置的左括号数大于零，则放置左括号，然后继续dfs
                # 这里可以不添加 and l_num <= r_num，因为上一步r_num > l_num已经保证了这点
                dfs(cur + '(', l_num - 1, r_num)

        res = []
        dfs('', n, n)
        return res
```

**如果你喜欢这条题解的话，欢迎点赞**👍 **收藏**🧡 **转发**📧 **评论**💬
**你的鼓励是我持续创作的动力**
**(゜-゜)つロ 干杯~**
