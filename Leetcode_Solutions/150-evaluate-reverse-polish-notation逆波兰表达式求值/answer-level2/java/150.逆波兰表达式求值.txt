思路：使用栈，遇到数字就入栈，遇到操作符，依次弹出栈顶两个数字，注意对于减法和除法，后弹出的数在操作符前。
```
public int evalRPN(String[] tokens) {
		Deque<Integer> stack = new LinkedList();
		int val=0;
		for(String s : tokens) {
			if(s.equals("+")) {
				val = stack.pop() + stack.pop();
				stack.push(val);
			} else if(s.equals("-")) {
				int x = stack.pop();
				int y = stack.pop();
				val = y - x;
				stack.push(val);
			} else if(s.equals("*")) {
				val = stack.pop() * stack.pop();
				stack.push(val);
			} else if(s.equals("/")) {
				int x = stack.pop();
				int y = stack.pop();
				val = y / x;
				stack.push(val);
			} else {
				try {
					stack.push(Integer.valueOf(s));
				} catch (NumberFormatException e) {
					e.printStackTrace();
				}
				
			}
		}
		return stack.pop();
	}
```
