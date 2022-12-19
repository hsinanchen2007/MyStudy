### 解题思路
java初学记录笔记

遍历字符串 
遇到左括号入栈0
右括号则出栈判断前一个数
选择push 1 或者push *2后和前个数的加和
### 代码

```java
class Solution {
    public int scoreOfParentheses(String S) {

         final char left = '(';
		Stack<Integer> stack = new Stack();
		int length = S.length();
        int peek;          //观测栈顶元素
		char c;
		for(int i=0;i<length;i++) {
			c = S.charAt(i);
			if(c == left) {//左括号
				stack.push(0);
			}else 
			{
				int top = stack.pop();
				if(top == 0) {
					
                    if(stack.empty()||stack.peek()==0){
                        stack.push(1);
                    }else{
                        stack.push(stack.pop()+1);
                    }

				}else 
				{
					stack.pop();
					if(stack.empty()||stack.peek()==0) {
						stack.push(top*2);
					}else {
					    peek = stack.pop();
						stack.push(top*2+peek);
					}				
				}
						
			}
		}
		
		return stack.pop();
    }
}
```