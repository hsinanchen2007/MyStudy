### 解题思路
这道题的思路很简单，原问题求min(max(depth(A), depth(B)))，我们最起码能够确定的是原字符串中最大深度的子串是肯定要进行分开的，比如"()(())"，最大的部分是"(())"，我们肯定是要将这部分分到A，B的，那么应该怎么分呢？我们将问题转换成将某个整数分成两个数，并且希望两个数最大的数最小，显而易见，只需要将这个整数平分即可，那么我们的思路也是基于这个。具体来说：那么最简单的方法是将每个嵌套的符号都分成两部分那么两部分最大深度肯定能够达到最小，那么这时候我们就需要在遍历的时候确定每个括号所在的深度：**对于’(‘其所在深度就是栈中元素个数 + 1，对于')'来说就是栈顶所代表的'('所在深度**，在具体实现上，我们知道栈中只可能保存'('，所以我们实际上并不需要保存元素内容是什么（因为肯定是'('），我们只需要保存括号的深度即可。

### 代码

```python
class Solution(object):
    def maxDepthAfterSplit(self, seq):
        """
        :type seq: str
        :rtype: List[int]
        """
        stack = []
        res = []
        for c in seq:
            if c == '(':
                depth = len(stack) + 1
                stack.append(depth) # 入队的是当前括号的深度
                res.append(depth % 2)
            else:
                res.append(stack[-1] % 2)
                del stack[-1]
        return res
```