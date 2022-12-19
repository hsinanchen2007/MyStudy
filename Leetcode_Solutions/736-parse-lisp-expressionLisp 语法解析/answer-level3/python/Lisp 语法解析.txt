####  方法：递归分析法 [Accepted]
**算法：**
这个问题从表达式的语法看相对简单，但是在解决的过程中会出现较大的困难。

表达式中会包含子表达式，这种情况适合用递归来解决。

一个难点是如何管理变量的正确范围。我们可以用栈来存放变量和值的对应关系，当进入变量作用的括号范围时，就将变量和值的哈希映射添加到栈中，当出括号内时，就弹出栈顶元素。

`evaluate` 方法会检查每个表达式 `expression` 采用的形式
- 如果 `expression` 是数字开头，则它是一个整数：返回它。 
- 如果 `expression` 以字母开头，则它是一个变量。则检查该变量的作用域。 
- 否则我们将 `expression` 中的标记（变量或表达式）分组，通过计算 `bal = '(' 的数量减去 ')' 的数量`，当 `bal` 为零时，则我们得到一个标记。举个例子：`(add 1 (add 2 3))` 可以获得两个标记 `'1'` 和 `'(add 2 3)'`。
- 计算每个标记并返回它们的加法或乘法得结果。 
- 对于 `let` 表达式，按顺序计算每个表达式并将其值分配给当前作用域中的变量，然后返回对最终表达式的求值。 
 
```Python [ ]
def implicit_scope(func):
    def wrapper(*args):
        args[0].scope.append({})
        ans = func(*args)
        args[0].scope.pop()
        return ans
    return wrapper

class Solution(object):
    def __init__(self):
        self.scope = [{}]

    @implicit_scope
    def evaluate(self, expression):
        if not expression.startswith('('):
            if expression[0].isdigit() or expression[0] == '-':
                return int(expression)
            for local in reversed(self.scope):
                if expression in local: return local[expression]

        tokens = list(self.parse(expression[5 + (expression[1] == 'm'): -1]))
        if expression.startswith('(add'):
            return self.evaluate(tokens[0]) + self.evaluate(tokens[1])
        elif expression.startswith('(mult'):
            return self.evaluate(tokens[0]) * self.evaluate(tokens[1])
        else:
            for j in xrange(1, len(tokens), 2):
                self.scope[-1][tokens[j-1]] = self.evaluate(tokens[j])
            return self.evaluate(tokens[-1])

    def parse(self, expression):
        bal = 0
        buf = []
        for token in expression.split():
            bal += token.count('(') - token.count(')')
            buf.append(token)
            if bal == 0:
                yield " ".join(buf)
                buf = []
        if buf:
            yield " ".join(buf)
```

```Java [ ]
class Solution {
    ArrayList<Map<String, Integer>> scope;
    public Solution() {
        scope = new ArrayList();
        scope.add(new HashMap());
    }

    public int evaluate(String expression) {
        scope.add(new HashMap());
        int ans = evaluate_inner(expression);
        scope.remove(scope.size() - 1);
        return ans;
    }

    public int evaluate_inner(String expression) {
        if (expression.charAt(0) != '(') {
            if (Character.isDigit(expression.charAt(0)) || expression.charAt(0) == '-')
                return Integer.parseInt(expression);
            for (int i = scope.size() - 1; i >= 0; --i) {
                if (scope.get(i).containsKey(expression))
                    return scope.get(i).get(expression);
            }
        }

        List<String> tokens = parse(expression.substring(
                expression.charAt(1) == 'm' ? 6 : 5, expression.length() - 1));
        if (expression.startsWith("add", 1)) {
            return evaluate(tokens.get(0)) + evaluate(tokens.get(1));
        } else if (expression.startsWith("mult", 1)) {
            return evaluate(tokens.get(0)) * evaluate(tokens.get(1));
        } else {
            for (int j = 1; j < tokens.size(); j += 2) {
                scope.get(scope.size() - 1).put(tokens.get(j-1), evaluate(tokens.get(j)));
            }
            return evaluate(tokens.get(tokens.size() - 1));
        }
    }

    public List<String> parse(String expression) {
        List<String> ans = new ArrayList();
        int bal = 0;
        StringBuilder buf = new StringBuilder();
        for (String token: expression.split(" ")) {
            for (char c: token.toCharArray()) {
                if (c == '(') bal++;
                if (c == ')') bal--;
            }
            if (buf.length() > 0) buf.append(" ");
            buf.append(token);
            if (bal == 0) {
                ans.add(new String(buf));
                buf = new StringBuilder();
            }
        }
        if (buf.length() > 0)
            ans.add(new String(buf));

        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$。其中 $N$ 指的是 `expression` 的长度。每个表达式只计算一次，但在计算过程中可能要搜索整个范围。 
* 空间复杂度：$O(N^2)$，在进行中间求值时，我们可以将 $O(N)$ 个新字符串传递给 `evaluate` 函数，每个字符串的长度为 $O(N)$。通过优化，可以将总空间复杂度降低到 $O(N)$。