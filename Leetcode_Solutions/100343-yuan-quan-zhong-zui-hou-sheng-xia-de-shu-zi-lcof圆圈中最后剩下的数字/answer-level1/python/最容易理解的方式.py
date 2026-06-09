### 解题思路
见每行代码注释。

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        # 初始化一个0到n-1的数组；初始化要删除的元素序号为0
        ans, popindex = list(range(n)), 0

        # 对数组进行逐个删除操作，直到数组只剩余1个元素。
        while len(ans) > 1:
            # 计算要删除的元素序号。
            # 每次要删除的元素即为上次要删除的元素序号往后数m个，因为数组是从0开始，所以要减1。
            # 因为数组到末尾后，要从头开始重新数，所以要对数组长度求余： % len(ans)
            popindex = (popindex + m - 1) % len(ans)
            # 从数组中删除该元素。
            ans.pop(popindex)
        
        # 数组中只剩一个元素，返回即可。
        return ans[0]
```