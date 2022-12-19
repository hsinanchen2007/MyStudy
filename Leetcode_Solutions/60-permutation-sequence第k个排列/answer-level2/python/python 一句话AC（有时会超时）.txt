### 解题思路

几秒前	通过	2144 ms	56.4 MB	Python3

由于太暴力了，徘徊在超时的边缘上，有时提交会超时，多交几次，就能过。

使用 itertools 库中的 permutations 获取所有排列，然后把第 k 个弄成字符串输出

### 代码

```python
class Solution(object):
    def getPermutation(self, n, k):
        return ''.join(list(__import__('itertools').permutations([str(i)for i in range(1,n+1)], n))[k-1])
```