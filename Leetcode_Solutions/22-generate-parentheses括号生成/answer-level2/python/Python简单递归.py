### 解题思路
方法其实很简单，在方法get_res中有三个参数n, count, s，参数的意义已经在代码中注释，递归的思想是如果目前仍然有可以使用的左括号那么我们就可以生成一个左括号，如果有尚未闭合的左括号，那么我们就可以添加一个右括号。
ps: 思想实在是太简单了，看代码一看就懂。

### 代码

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def get_res(n, count, s):
            """
            :param n->int: 目前还可使用的左括号的数量
            :param count->int: 目前尚未闭合的左括号的数量
            :param s->str: 生成的字符串
            """
            if n == 0 and count == 0:
                res.append(s)
                return 
            if n > 0:
                get_res(n - 1, count + 1, s + '(')
            if count > 0:
                get_res(n, count - 1, s + ')')
        res = []
        get_res(n, 0, '')
        return res
```