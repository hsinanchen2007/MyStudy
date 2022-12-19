一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
遍历压入栈，存储于栈中，遍历过程中，如果栈顶是出栈结点，推出值。

- 最终栈空则弹出序列有效
- 栈不空则弹出序列无效

### 代码

```python
class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        stack = []
        i = 0
        for v in pushed:
            stack.append(v)
            while stack and stack[-1] == popped[i]:
                i += 1
                stack.pop(-1)
        if not stack:
            return True
        else:
            return False

```