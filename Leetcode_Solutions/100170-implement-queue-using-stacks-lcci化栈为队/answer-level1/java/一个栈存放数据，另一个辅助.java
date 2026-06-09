class MyQueue {
    Stack<Integer> left = new Stack<>();
    Stack<Integer> right = new Stack<>();

    /** Initialize your data structure here. */
    public MyQueue() {
        left.clear();
        right.clear();
    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
        while (!left.empty()) {
            right.push(left.pop());
        }

        left.push(x);

        while (!right.empty()) {
            left.push(right.pop());
        }
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
        return left.pop();
    }

    /**
     * Get the front element.
     */
    public int peek() {
        return left.peek();
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
        return left.empty();
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