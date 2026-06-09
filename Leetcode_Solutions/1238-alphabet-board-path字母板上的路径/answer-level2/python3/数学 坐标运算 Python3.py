**思路：**

乍一看，此题像是一道搜索题，但是仔细观察，`alphabet board` 上面的每个字母都是有固定横纵坐标的，所以我们字节遍历 `target`，再根据相对坐标运算得出答案。但是在生成答案的时候需要注意一个特殊情况，就是最后一行只有一个字母 `z`，当前字符为 `z` 的时候，不能从字母 `z` 的右边到达，只能从上边到达。而上一个字符为字母 `z` 的时候，我们不能从字母 `z` 的右边出发，只能从字母 `z` 的上边出发。所以我们需要优化一个答案生成顺序，优先生成左 `L` 上 `U`，即可避免移动出 `alphabet board` 的非法路径。

**图解：**

![图解](https://pic.leetcode-cn.com/d40f02af917d661aea59a7d4d0cf252edb6d46ebc7e31a55b2106aab2b8eb8d9.gif){:width=600}
{:align=center}


**代码：**
```python [-Python]
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        x, y, d = 0, 0, dict()
        for i in range(26):
            d[chr(i + 97)] = (i // 5, i % 5)
        cur, ans = (0, 0), []
        for c in target:
            nxt = d[c]
            dx, dy = nxt[0] - cur[0], nxt[1] - cur[1]
            if dx < 0: ans += ['U'] * (-dx)
            if dy < 0: ans += ['L'] * (-dy)
            if dx > 0: ans += ['D'] * dx
            if dy > 0: ans += ['R'] * dy
            ans.append('!')
            cur = nxt
        return ''.join(ans)
```


