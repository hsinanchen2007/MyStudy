- ### 解题思路
这个很简单 因为队列是先进先出的 我们需要准备两个栈 一个叫push 一个叫pop
其中 push 只负责模拟进队列 pop负责模拟出队列，当pop为空的时候才能把push 倒入pop中 如果不为空就不能倒入

### 代码

```java
	class MyQueue {
		private Stack<Integer> stackPush;
		private Stack<Integer> stackPop;
	    /** Initialize your data structure here. */
	    public MyQueue() {
	    	stackPush = new Stack<Integer>();
			stackPop = new Stack<Integer>();

	    }
	    
	    /** Push element x to the back of queue. */
	    public void push(int x) {
	    	stackPush.push(x);
	    }
	    
	    /** Removes the element from in front of queue and returns that element. */
	    public int pop() {
	    	if(stackPop.empty()) {
	    		while (!stackPush.empty()) {
					stackPop.push(stackPush.pop());
				}
	    	}
	    	return stackPop.pop();
	    }
	    
	    /** Get the front element. */
	    public int peek() {
	    	if(stackPop.empty()) {
	    		while (!stackPush.empty()) {
					stackPop.push(stackPush.pop());
				}
	    	}
	    	return stackPop.peek();
	    	

	    }
	    
	    /** Returns whether the queue is empty. */
	    public boolean empty() {
	    	if(stackPop.empty() && stackPush.empty()) {
	    		return true;
	    	}else {
				return false;
			}
	    }
	}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
```