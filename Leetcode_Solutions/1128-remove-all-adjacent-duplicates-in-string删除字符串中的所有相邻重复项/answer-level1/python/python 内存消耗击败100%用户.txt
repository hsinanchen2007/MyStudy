### 解题思路
思路算是栈的基本用法，就不赘述。主要是为了纪念第一个100%。

执行用时 :60 ms, 在所有 python 提交中击败了69.49%的用户；
内存消耗 :12.1 MB, 在所有 python 提交中击败了100.00%的用户。

### 代码

```python
class Solution(object):
    def removeDuplicates(self, S):
        """
        :type S: str
        :rtype: str
        """
        stack = []
        for ii in S:
            if stack and ii != stack[-1]:
                stack.append(ii)
            elif stack and ii == stack[-1]:
                stack.pop()
            elif not stack:
                stack.append(ii)
        result = ''.join(stack)
        return result

```