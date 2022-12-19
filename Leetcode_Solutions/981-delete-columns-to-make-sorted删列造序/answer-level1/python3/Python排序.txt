### 解题思路
-- 使用python内置zip()函数将原数组分解为列
-- 比较每一列与升序排序后是否相等。（排序用sorted()）

![图片.png](https://pic.leetcode-cn.com/2411a5126717fb212868d2b0bf38cf4b5a64f21739840576d6f703984998a1dc-%E5%9B%BE%E7%89%87.png)

### 代码

```python3
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        cols = zip(*A)
        res = 0
        for col in cols:
            if list(col) != sorted(col):
                res +=  1
        return res
```