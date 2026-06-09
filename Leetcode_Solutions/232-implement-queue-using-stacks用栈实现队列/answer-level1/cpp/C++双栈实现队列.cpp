### 思路
通过使用双栈模拟出队列，A栈为入队操作，B栈为出队操作
在每次需要设计到出队时，则要去**检查B栈是否为空，如果为空，则要把A栈中的内容装入到B中**，该操作对应的函数即为A2B()，
如果不为空，则对B进行操作即可。
另外此处判断是否为空，看了别人代码后，一种非常简单的写法是，判断A和B是否都为空，如果都为空，则为空，否则说明不为空。
自己刚开始的思路是先执行一次A2B()，最后再判断一次B是否为空。


### 代码
```cpp
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
		
	}
	/** Push element x to the back of queue. */
	void push(int x) {//入队
		A.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {//队列的弹出有返回值？
		//B为空，将A中数据全部转到B中
		A2B();
		//不为空，直接弹出B
		int front = B.top();
		B.pop();
		return front;
	}

	/** Get the front element. */
	int peek() {
		//B为空，将A中数据全部转到B中
		A2B();
		//不为空，返回B的头部元素
		return B.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		//A和B全部为空，则全为空,否则不为空
		return A.empty() && B.empty();
	}
	void A2B()
	{
		//B为空时，将A中所有元素压入B中
		if (B.size() == 0)
		{
			while (!A.empty())
			{
				B.push(A.top());//将A中元素压入B中
				A.pop();//A中元素出栈
			}
		}	
	}
	stack<int> A, B;//A出队时使用，B入队时使用
};
```