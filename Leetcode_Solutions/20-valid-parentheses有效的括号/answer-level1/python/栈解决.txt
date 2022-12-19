## 思路:

匹配问题，我们一般使用 **栈**

遍历字符串，我们把左括号压入栈中，当遇到右括号，和栈顶元素比较！

时间复杂度：$O(n)$

空间复杂度：$O(n)$

## 代码：

```Python []
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        lookup = {
            "(":")",
            "[":"]",
            "{":"}"
        }
        for alp in s:
            if alp in lookup:
                stack.append(alp)
                continue
            if stack and lookup[stack[-1]] == alp:
                stack.pop()
            else:
                return False
        return True if not stack else False
```

```Java []
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (char alp : s.toCharArray()) {
            if (alp == '(') stack.push(')');
            else if (alp == '[') stack.push(']');
            else if (alp == '{') stack.push('}');
            else if (stack.isEmpty() || stack.pop() != alp) return false;
        }
        return stack.isEmpty();
        
    }
}
```



