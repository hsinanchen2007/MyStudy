### 解题思路
跟着bobo老师做的，用栈解决的。具体思路是：
遍历所有元素
遇到左括号存入栈
遇到右括号就和栈顶元素比较，如果不匹配返回flase，匹配就继续循环。
注意：即使循环结束也不能返回true，应该返回isEmpty()的Boolean值

### 代码

```java
import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
            Stack<Character> stack = new Stack<>();
		for(int i =0; i<s.length(); i++) {//遍历所有元素
			char c = s.charAt(i);
			if(c == '('|| c=='['|| c=='{') //左括号入栈
				stack.push(c);
			else {
				if(stack.isEmpty())
					return false;
				char topChar = stack.pop();//存放栈顶元素待与右括号比较
				if(c == ')' && topChar != '(')
					return false;
				if(c == ']' && topChar != '[')
					return false;
				if(c == '}' && topChar != '{')
					return false;
			}
		}
		
		return stack.isEmpty();//返回isEmpty()是怕栈有其他未匹配元素
    }
}
```