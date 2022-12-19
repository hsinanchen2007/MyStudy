//必须在stackPop为空时，一次性把stackPush的所有数据全部压入
class MyQueue {
public:
	stack<int>stackPush;
	stack<int>stackPop;

	/** Initialize your data structure here. */
	MyQueue() {
	
	}

	/* 当stackPop为空时，stackPush将全部数据一次性压入StackPop*/
	void pushToPop() {
		if (stackPop.empty()) {
			while(!stackPush.empty()){
				stackPop.push(stackPush.top());
				stackPush.pop();
			}	
		}
	}
	/** Push element x to the back of queue. */
	void push(int x) {
		stackPush.push(x);
		pushToPop();

	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (stackPush.empty() && stackPop.empty())
			std::cout << "Queue is empty";
		pushToPop();
		int front_element = stackPop.top();
		stackPop.pop();
		return front_element;

	}

	/** Get the front element. */
	int peek() {
		if (stackPush.empty() && stackPop.empty())
			std::cout << "Queue is empty";
		pushToPop();
		return stackPop.top();

	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (stackPush.empty() && stackPop.empty())
			return true;
		else
			return false;
	}
};
