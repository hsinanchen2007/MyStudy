### 解题思路
1.此类创造数据结构的题，在思考的时候思维不能被限制住，要当个心态毫无变化的上帝去享受编码的快感。比如说栈顶元素，先用着空间去换时间，去简化思路。 同样的还有最小值栈这题。
2.这种题最简单的思路就是跟着数据，自己画图来解决。一定要把用例思考全，保证方法对了再去写代码，这样可以减少编码时间，毕竟抠细节是真滴8行。

### 代码

```java
class MyStack {

	// 存放数据的队列
	Queue<Integer> data;
	
	// 辅助pop的队列
	Queue<Integer> helper;
	
	// 存放top的元素
	int top;
	
    /** Initialize your data structure here. */
    public MyStack() {
    	data = new LinkedList();
    	helper = new LinkedList();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
    	data.add(x);
    	top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
    	while(data.size()!=1) {
    		top = data.poll();
    		helper.add(top);
    	}
    	int res = data.poll();
    	Queue<Integer> tmp = helper;
    	helper = data;
    	data = tmp;
    	return res;
    	
    }
    
    /** Get the top element. */
    public int top() {
    	return top;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
    	return data.isEmpty();
    }
}
```