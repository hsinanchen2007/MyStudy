### 解题思路
此处撰写解题思路

### 代码

```java
class MyStack {
    
    public LinkedList<Integer> que1 = new LinkedList<>();
	public LinkedList<Integer> que2 = new LinkedList<>();

    /** Initialize your data structure here. */
    public MyStack() {
        
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(que1.isEmpty()) {
			que2.add(x);
		}else {
			que1.add(x);
		}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(que1.isEmpty()) {
    		while(que2.size()>=2) {
    			que1.add(que2.remove());
    		}
			return que2.remove();
		}else {
			while(que1.size()>=2) {
    			que2.add(que1.remove());
    		}
			return que1.remove();
		}
    }
    
    /** Get the top element. */
    public int top() {
        if(que1.isEmpty()) {
    		while(que2.size()>=2) {
    			que1.add(que2.remove());
    		}
    		int temp = que2.remove();
    		que1.add(temp);
			return temp;
		}else {
			while(que1.size()>=2) {
    			que2.add(que1.remove());
    		}
			int temp = que1.remove();
			que2.add(temp);
			return temp;
		}
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        if(que1.isEmpty() && que2.isEmpty()) 
    		return true;
    	else 
    		return false;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
```