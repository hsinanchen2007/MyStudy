真题不难，就是简单的出栈入栈法。逆波兰表示法对于基本的四则运算没有优先级的限制，所以对于本题而言，运算符的优先顺序完全是看运算符在tokens表达式内出现的先后顺序来决定的。这就好说了，定义一个栈列表stack，一次遍历tokens表达式，如果是数字则进栈，如果是运算符，则将栈stack内前两个栈顶元素出栈，进行相应运算。不过此题中比较麻烦一点的就是除法运算了，逆波兰表示法进行除法运算时是只保留整数位，既不是向上整数也不是向下整除。我是用math.trunc()来计算的，这一点需要注意一下。

代码如下：
```Python
import math
class Solution(object):
    # 进栈出栈顺序计算
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for tok in tokens:
            if tok in ["+", "-", "*", "/"]:
                right_num = stack.pop()
                left_num = stack.pop()
                expression = left_num + tok + right_num
                # 逆波兰表示法进行除法运算时是只保留整数位，既不是向上整数也不是向下整除
                if tok == "/":
                    res = math.trunc(eval(expression))
                else:
                    res = eval(expression)
                stack.append(str(res))
            else:
                stack.append(tok)
        return int(stack.pop())


if __name__ == "__main__":
    tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    result = Solution().evalRPN(tokens)
    print(result)
```
如果有更好的方法，希望大家积极留言啊！！！