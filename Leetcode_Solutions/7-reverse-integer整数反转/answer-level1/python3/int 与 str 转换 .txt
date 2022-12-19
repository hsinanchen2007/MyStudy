  首先，将 输入数字 x 转换为单个字符、单个字符的列表形式，然后将列表反转，判断列表[0]是否为0，是 就去掉。
  取列表的前 len（列表） - 1 项（因为反转后最后一项可能是 ‘-’ ，也可能是数字）用 join 方法制造一个 str
  判断最后一项后，视情况将最后一项填到相应位置
  将 str 转换为 int 形式
  判断边界
 

```python []
class Solution:
    def reverse(self, x: int) -> int:
        # 转为列表
        res = list(str(x))
        res.reverse()

        # 判断 第一项是否为0
        if res[0]==0:
            res.popleft()

        # 转为str
        ans = ''.join(res[:-1])

        # 判断最后一项
        if res[-1] == '-':
            ans = '-'+ans
        else:
            ans += res[-1]

        # 转为 int
        ans = int(ans)
        if  -2**31 <=ans<= 2**31-1:
            return ans
        else:
            return 0
```

但是内存消耗过大，感觉应该还有很大的修改空间。
希望各位大佬不吝赐教！——__——