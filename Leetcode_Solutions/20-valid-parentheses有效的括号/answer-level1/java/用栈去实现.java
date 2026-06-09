### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i)=='('||s.charAt(i)=='{'||s.charAt(i)=='[') { 
				stack.push(s.charAt(i));
			}
			if(s.charAt(i)==')') {
				if(stack.size()>0&&stack.peek()=='(') {
					stack.pop();
				}
				else {
					stack.push(')');
				}
			}
			if(s.charAt(i)=='}') {
				if(stack.size()>0&&stack.peek()=='{') {
					stack.pop();
				}
				else {
					stack.push('}');
				}
			}
			if(s.charAt(i)==']') {
				if(stack.size()>0&&stack.peek()=='[') {
					stack.pop();
				}
				else {
					stack.push(']');
				}
			}
		}
		if(stack.size()>0) {
			return false;
		}
		else {
			return true;
		}
    }
}
```