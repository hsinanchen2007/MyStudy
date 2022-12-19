### 解题思路
用两个队列，加入时若第一个队列不为空先把所有元素弹出并加入第二个队列，然后把要加入的元素加入第一个队列后再把第二个队列元素全部加入第一个元素

### 代码

```java
class MyStack {
     LinkedList<Integer> list1 = new LinkedList<>();
	LinkedList<Integer> list2 = new LinkedList<>();
    /** Initialize your data structure here. */
    public MyStack() {

    }
    
    /** Initialize your data structure here. */
    
    /** Push element x onto stack. */
    public void push(int x) {
         if(list1.size()==0) {
        	 list1.add(x);
	        	return;
	        }
	       
	        while(!list1.isEmpty()) {
	        	list2.add(list1.pop());
	        }
	        list1.add(x);
	        while(!list2.isEmpty()) {
	        	list1.add(list2.pop());
	        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(list1.size()>0)
	    	return list1.pop();	
	    	throw new RuntimeException("栈为空");
    }
    
    /** Get the top element. */
    public int top() {
    	if(list1.size()>0)
	    	return list1.peek();	
	    	throw new RuntimeException("栈为空");
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
    	if(list1.size()>0)
	    	return false;
    	return true;
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