### 解题思路
栈，先入后出

计算结果也要推入栈
### 代码

```java
class Solution {
    public int evalRPN(String[] tokens) {

		Stack<Integer> stack = new Stack<>();
		for( int i=0;i<tokens.length;i++){
			if(isOp(tokens[i])){
				//操作
				int b = stack.pop();
				int a = stack.pop();
				int rst = operation(a,b, tokens[i]);
				stack.add(rst);
			}else{
				stack.add(Integer.parseInt(tokens[i]));
			}
		}
		return stack.pop();
	}
	
	public boolean isOp(String s){
		return s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/") ; 
	}
	
	public int operation(int a,int b,String op){
		if("+".equals(op)){
			return a+b;
		}else if ("/".equals(op)){
			return a/b;
		}else if("-".equals(op)){
			return a-b;
		}else{
			return a*b;
		}
		
	}
}
```