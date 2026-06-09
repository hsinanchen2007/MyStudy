### 解题思路
虽然 0 的 2 倍仍然是 0 本身，但是只有 1 个 0 仍是不行的。所以要统计 0 的数量。

使用 collections.Counter 方便的统计数组中各个元素的数量。

### 代码

```python
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        import collections
        s = collections.Counter(arr)
        for n in s:
            if n == 0:
                if s[n] > 1: return True
            elif n<<1 in s:
                return True
        return False
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)