### 解题思路
此处撰写解题思路
建立一个队列，利用队列特性，push:每次新数据正常push进队列。pop:在弹出数据时，将队列的前n-1个数据依次弹出并push到队尾，pop出新的第一个元素。top：将队列的前n-1个数据依次弹出并push到队尾，返回新的第一个元素后，在push到队尾。
### 代码

```cpp
class MyStack {
private:
	queue<int> myQue;
	//将队列的前n-1个元素放到队列的尾部
	void myOp(){
		int queSize = myQue.size();
		for (int i = 1; i < queSize; ++i){
			myQue.push(myQue.front());
			myQue.pop();
		}
	}
public:
	/** Initialize your data structure here. */
	MyStack() {
        
	}
	
	/** Push element x onto stack. */
	void push(int x) {//直接放入队列
		myQue.push(x);
	}
	
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		myOp();//将队列的前n - 1个元素放到尾部
		int top = myQue.front();
		myQue.pop();
		return top;
	}
	
	/** Get the top element. */
	int top() {
		myOp();//将队列的前n - 1个元素放到尾部
		int top = myQue.front();
		myQue.pop();
		myQue.push(top);
		return top;
	}
	
	/** Returns whether the stack is empty. */
	bool empty() {
		return myQue.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
```