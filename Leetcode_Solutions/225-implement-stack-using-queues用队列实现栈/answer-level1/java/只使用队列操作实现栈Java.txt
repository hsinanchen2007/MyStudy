执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37.6 MB, 在所有 Java 提交中击败了5.60%的用户
### 解题思路
双队列，一个类似于中间变量那种，一直得保证为空。一个是实际存放数据的队列。push操作O(n),其他操作都是O(1)。
### 代码

```java
class MyStack {

		LinkedList<Integer> q1 ;
		LinkedList<Integer> q2 ;
	    /** Initialize your data structure here. */
	    public MyStack() {
	    	q1 = new LinkedList<>() ; //始终为空，中间变量的感觉。
	    	q2 = new LinkedList<>() ;
	    }
	    
	    /** Push element x onto stack. */
	    public void push(int x) {
	    	q1.addLast(x) ;
	    	while(!q2.isEmpty()) {
	    		q1.addLast(q2.removeFirst()) ;
	    	}
	    	q2 = q1 ;
	    	q1 = new LinkedList<>() ;
	    }
	    
	    /** Removes the element on top of the stack and returns that element. */
	    public int pop() {
	    	return q2.removeFirst() ;
	    }
	    
	    /** Get the top element. */
	    public int top() {
	    	return q2.getFirst() ;
	    }
	    
	    /** Returns whether the stack is empty. */
	    public boolean empty() {
	    	return q2.isEmpty() ;
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