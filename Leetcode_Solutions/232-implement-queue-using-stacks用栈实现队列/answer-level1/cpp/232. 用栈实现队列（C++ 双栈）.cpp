# 232. 用栈实现队列

创建两个栈stack1和stack2，使用两个“先进后出”的栈实现一个“先进先出”的队列。

```
class MyQueue {
private:
	stack<int> m_stack1;	//输入栈
	stack<int> m_stack2;	//输出栈
public:
    /** Initialize your data structure here. */
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        m_stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		int top = peek();
		m_stack2.pop();
		return top;
    }
    
    /** Get the front element. */
    int peek() {
		if(empty())  return -1;
        if( m_stack2.empty() ){	//输出栈空-将输入栈所有元素取出插入输出栈
			while( !m_stack1.empty() ){
				m_stack2.push(m_stack1.top());
				m_stack1.pop();
			}
		}
		return m_stack2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if( m_stack1.empty() && m_stack2.empty() )  //输入输出栈都为空 队列为空
			return true;
		else  
			return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```
