```
class MyStack {
	Queue<Integer> queue;
	Queue<Integer> helpQueue;

	/** Initialize your data structure here. */
	public MyStack() {
		queue = new LinkedList<>();
		helpQueue = new LinkedList<>();
	}

	/** Push element x onto stack. */
	public void push(int x) {
		queue.add(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	public int pop() {
		while (queue.size() > 1) {
			helpQueue.add(queue.poll());
		}
		int res = queue.poll();
		while (!helpQueue.isEmpty()) {
			queue.add(helpQueue.poll());
		}
		return res;
	}

	/** Get the top element. */
	public int top() {
		while (queue.size() > 1) {
			helpQueue.add(queue.poll());
		}
		int res = queue.peek();
		helpQueue.add(queue.poll());
		while (!helpQueue.isEmpty()) {
			queue.add(helpQueue.poll());
		}
		return res;
	}

	/** Returns whether the stack is empty. */
	public boolean empty() {
		return queue.isEmpty();
	}
}
```
