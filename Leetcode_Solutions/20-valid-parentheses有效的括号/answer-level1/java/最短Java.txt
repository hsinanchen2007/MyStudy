### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
        public boolean isValid(String s) {
       Stack<Character> stack = new Stack<Character>();
	for (char c : s.toCharArray()) {
		if (c == '(')
			stack.push(')');
		else if (c == '{')
			stack.push('}');
		else if (c == '[')
			stack.push(']');
		else if (stack.isEmpty() || stack.pop() != c)
			return false;
	}
	return stack.isEmpty();

    }
}

```
摘自国际区，很巧妙，字符串里的左括号在栈里压入右括号