### 解题思路
此处撰写解题思路

### 代码

```java
class MinStack {
	 Stack<Integer> stack1;
	  Stack<Integer> stack2;
	 
	    public MinStack() {
	    	stack1 = new Stack<Integer>();
	    	stack2 = new Stack<Integer>();
	    }
	    
	    public void push(int x) {
	    	stack1.push(x);
	    	if(stack2.isEmpty()||stack2.peek()>=x) {
	    		stack2.push(x);
	    	}
	    }
	    
	     public void pop() {
	    	int num = stack1.pop();  
	    	if(stack2.peek()==num||num<stack2.peek()) {     //如果stack2栈顶的元素和取出来的数相等， 或者取出的数比stack2顶的还小，让stack2.pop();
	    		stack2.pop();
	    	}
	    	
	    }
	    
	    public int top() {
	    	return stack1.peek();
	    }
	    
	    public int min() {
	    	
	    		if(!stack1.isEmpty()) {
	    				return stack2.peek();
	    		}
	    return -1;
	    }
	}
```