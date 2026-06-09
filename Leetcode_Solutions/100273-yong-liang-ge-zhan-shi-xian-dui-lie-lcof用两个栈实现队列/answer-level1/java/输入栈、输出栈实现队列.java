使用两个栈，一个用于存储输入的元素，一个用于存储需要弹出的元素。
```
public class CQueue {
	
	Stack<Integer> stack_in=new Stack<>();
	Stack<Integer> stack_out=new Stack<>();
	
	public CQueue() {

    }
    
    public void appendTail(int value) {
    	stack_in.push(value);
    }
    
    public int deleteHead() {
    	if(stack_in.isEmpty() && stack_out.isEmpty()) {
    		return -1;
    	}
    	if(!stack_out.isEmpty()) {
    		return stack_out.pop();
    	}else {
    		while(!stack_in.isEmpty()) {
    			stack_out.push(stack_in.pop());
    		}
    		return stack_out.pop();
    	}
    }
}

```
