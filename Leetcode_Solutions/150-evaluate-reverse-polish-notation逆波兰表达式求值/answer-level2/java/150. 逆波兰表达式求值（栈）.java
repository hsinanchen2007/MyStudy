```Java
class Solution{
	public int evalRPN(String[]tokens){
		Stack<Integer>stack=new Stack<>();
		int a,b;
		for(String s:tokens){
			switch(s){
				case "+":
					a=stack.pop();
					b=stack.pop();
					stack.push(b+a);
					break;
				case "-":
					a=stack.pop();
					b=stack.pop();
					stack.push(b-a);
					break;
				case "*":
					a=stack.pop();
					b=stack.pop();
					stack.push(b*a);
					break;
				case "/":
					a=stack.pop();
					b=stack.pop();
					stack.push(b/a);
					break;
				default:
					stack.push(Integer.valueOf(s));
					break;	
			}
		}
		return stack.pop();
	}
}
```