用栈就可以了, 遇到数字压入栈, 遇到操作符,弹出栈顶两个元素操作就可以了!

```python 
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t in {"+", "-", "/", "*"}:
                tmp1 = stack.pop()
                tmp2 = stack.pop()
                stack.append(str(int(eval(tmp2+t+tmp1))))
            else:
                stack.append(t)
        return stack.pop()     
```

执行速度太慢, 可能用了`eval`原因,换一种写法,大家可以借鉴这样写法, 看起来很舒服!

```python []
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        plus = lambda a, b : b + a
        sub = lambda a, b: b - a
        mul = lambda a, b: b * a
        div = lambda a, b: int(b / a)
        opt = {
            "+": plus,
            "-": sub,
            "*": mul,
            "/": div
        }
        for t in tokens:
            if t in opt:
                stack.append(opt[t](stack.pop(), stack.pop()))
            else:
                stack.append(int(t))
        return stack.pop()
```



```java []
class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new LinkedList<>();
        for (String s : tokens) {
            if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                int right = stack.pop();
                int left = stack.pop();
                if (s.equals("+")) stack.push(left + right);
                if (s.equals("-")) stack.push(left - right);
                if (s.equals("*")) stack.push(left * right);
                if (s.equals("/")) stack.push(left / right);
            } else {
                stack.push(Integer.valueOf(s));
            }
        }
        return stack.pop();
    }
}
```

