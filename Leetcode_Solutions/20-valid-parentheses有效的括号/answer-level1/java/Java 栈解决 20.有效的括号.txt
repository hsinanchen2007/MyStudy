一看到题目就想到用栈解决了，完美的先进后出

```java
class Solution {
	public boolean isValid(String s) {
		Stack<String> stack = new Stack<>();
		for (int i = 0;i<s.length();i++) {
			switch (s.charAt(i)) {
				case '(':
					stack.push("(");
					break;
				case ')':
					if (stack.empty()) {
						return false;
					}
					if (!stack.pop().equals("(")) {
						return false;
					}
					break;
				case '[':
					stack.push("[");
					break;
				case ']':
					if (stack.empty()) {
						return false;
					}
					if (!stack.pop().equals("[")) {
						return false;
					}
					break;
				case '{':
					stack.push("{");
					break;
				case '}':
					if (stack.empty()) {
						return false;
					}
					if (!stack.pop().equals("{")) {
						return false;
					}
					break;
			}
		}
		return stack.empty();
	}
}
```