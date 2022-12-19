### 解题思路
广度优先遍历方法很多题解都提到了，该方法是很容易理解的，我个人觉得其实就是枚举，删一个括号，删两个括号...，只不过每次是从上一层的基础上再删一个括号进行的，比如删除两个括号是在删除一个括号得到的字符串集合的基础上得到的。这种方法简单有效，但是就是太慢了，而加快树的遍历的有效方法就是剪枝。
剪枝的方法很简单，首先改变判断字符串是否有效的函数为返回字符串中无效括号的数量，这很容易修改，我是用栈做的，修改方法就是返回最后栈中元素的个数即可，对于每一层，只保留具有最少的无效括号的字符串，然后以他们为基础得到下一层候选字符串，基于的思想也很简单，如果能够删除最少的括号使得字符串有效，那么每一步都应该使得无效括号减少一个。
下面给出普通的广度优先遍历和加了剪枝的广度优先遍历的代码。（两个都是可以通过的，效率是差了指数级的）

### 代码

```python
class Solution(object):
    def removeInvalidParentheses(self, s):
        """ 广度优先遍历 + 剪枝
        :type s: str
        :rtype: List[str]
        """
        def get_invalid(s):
            """
            返回不匹配的括号的数量
            """
            stack = []
            for ch in s:
                if ch == '(':
                    stack.append('(')
                elif ch == ')':
                    if len(stack) != 0 and stack[-1] == '(':
                        del stack[-1]
                    else:
                        stack.append(')')
            # print(s, ':', len(stack))
            return len(stack)

        candidate = [s]
        # valid_num = float('inf') # 记录每一层的不匹配括号的数量
        res = []
        while res == [] and candidate != []:
            min_valid_num = float('inf') 
            s_list = [] # 当前这一层有最小不匹配括号数量的s的下标
            for s in candidate:
                s_valid_num = get_invalid(s)
                if s_valid_num == 0:
                    res.append(s)
                elif res == [] and s_valid_num < min_valid_num:
                    s_list = [s]
                    min_valid_num = s_valid_num
                elif res == [] and s_valid_num == min_valid_num:
                    s_list.append(s)

            if res != []:
                print('res:', res)
                break
            temp = []
            for s in s_list:
                mem = None
                for i in range(len(s)):
                    if s[i] != mem:
                        temp.append(s[:i] + s[i + 1:])
                        mem = s[i]
            candidate = list(set(temp))
        return res

    def removeInvalidParentheses_2(self, s):
        """ 广度优先遍历
        :type s: str
        :rtype: List[str]
        """
        def judge_valid(s):
            stack = []
            for ch in s:
                if ch == '(':
                    stack.append(ch)
                elif ch == ')':
                    if len(stack) != 0 and stack[-1] == '(':
                        del stack[-1]
                    else:
                        return False
            if len(stack) != 0:
                return False
            return True

        candidate = [s]
        res = []
        while res == [] and candidate != []:
            for s in candidate:
                if judge_valid(s):
                    res.append(s)
            if res != []:
                break
            temp = []
            for s in candidate:
                mem = None
                for i in range(len(s)):
                    if s[i] != mem:
                        temp.append(s[:i] + s[i + 1:])
                        mem = s[i]
            candidate = list(set(temp))
        return res
```