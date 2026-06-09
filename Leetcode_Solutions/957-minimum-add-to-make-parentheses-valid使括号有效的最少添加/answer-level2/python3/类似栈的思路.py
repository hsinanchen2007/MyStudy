括号匹配问题，我们可以想到的是栈。
对于栈的最经典的应用就是计算表达式（虽然python可以直接调用eval函数解决）
我们可以通过这个方式去了解我们栈的工作方式
栈总的来说就是先入后出，有点像我们的桶装薯片，你只能从上面拿，而不能从下面拿。
那根据这个思路，实际上我们进行括号匹配最关键的就是右括号
一个右括号必然要匹配一个左括号才是成功的
所以根据这个想法我们可以得到如下代码。
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        stack = []
        for i in range(len(S)):
            stack.append(S[i])
            if S[i] == ')' and len(stack) >= 2:
                if stack[-2] == '(':
                    del stack[-1]
                    del stack[-1]
        return len(stack)