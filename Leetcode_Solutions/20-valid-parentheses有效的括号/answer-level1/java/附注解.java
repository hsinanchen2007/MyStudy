### 解题思路
如下描述

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if(s.isEmpty())
            return true;
	    Stack<Character> stack=new Stack<Character>();   //建立栈，先进后出，直到栈空
	    for(char c:s.toCharArray()){
	        if(c=='(')
	            stack.push(')');
	        else if(c=='{')
	            stack.push('}');
	        else if(c=='[')
	            stack.push(']');
	        //这个代码写的不太友好，.pop动作是肯定发生的，只是如果遍历到的括号没有按照之前的顺序出栈，或者还没遍历完就已经空了，就false
	        else if(stack.empty()||c!=stack.pop())   
	            return false;
	    }
	    return stack.empty();
    }
}
```