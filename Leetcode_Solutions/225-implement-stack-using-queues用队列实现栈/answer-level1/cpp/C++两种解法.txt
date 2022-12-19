##### 用一个队列：To be specific, refer to the code annotation.
```
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) { // 正常插入，不重新排序，出队顺序与出栈的顺序正好相反
    	mystack.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() { // 出栈元素的时候用循环，元素遍历出队一遍并插回队列，对应栈顶的那个元素出队后不插回队列，以此完成出栈操作
    	int size = mystack.size();
    	int ele;
    	for (int i = 0; i < size; ++i) {
    		ele = mystack.front();
    		mystack.pop();
    		if (i != (size - 1))
    			mystack.push(ele);
    	}
    	return ele;
    }
    
    /** Get the top element. */
    int top() { // 对应队列的最后一个元素
    	return mystack.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
    	return mystack.empty();
    }

private:
    queue<int> mystack;
};
```
##### 用两个队列：To be specific, refer to the code annotation.
```
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) { // 两个队列之间互相存放，以调换元素顺序
    	queue<int> temp; // 创建临时队列
    	temp.push(x); // 先将元素插入临时队列
    	while (!_data.empty()) { //判断主队列是否为空，不为空则把主队列的元素出队插入到临时队列中。完成顺序调换。
    		int ele = _data.front();
    		_data.pop();
    		temp.push(ele);
    	}
    	while (!temp.empty()) { // 将完成了顺序调换的所有元素重新放回主队列，这时出队顺序和出栈顺序一致了
    		int ele = temp.front();
    		temp.pop();
    		_data.push(ele);
    	}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() { // 直接出栈即可
    	int ele = _data.front();
    	_data.pop();
    	return ele;
    }
    
    /** Get the top element. */
    int top() { // 直接获取队列头部元素即可
    	return _data.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
    	return _data.empty();
    }

private:
    queue<int> _data;
};
```