public class MyStack {
    private Queue<Integer> queue_1;
    private Queue<Integer> queue_2;

    /**
     * Initialize your data structure here.
     */
    private MyStack() {
        queue_1 = new LinkedList<>();
        queue_2 = new LinkedList<>();
    }

    /**
     * Push element x onto stack.
     */
    private void push(int x) {
        queue_1.offer(x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    private int pop() {
        while (queue_1.size() != 1) {
            queue_2.offer(queue_1.poll());
        }
        int temp = queue_1.poll();
        while (queue_2.size() != 0) {
            queue_1.offer(queue_2.poll());
        }
        return temp;
    }

    /**
     * Get the top element.
     */
    private int top() {
        while (queue_1.size() != 1) {
            queue_2.offer(queue_1.poll());
        }
        return queue_1.peek();
    }

    /**
     * Returns whether the stack is empty.
     */
    private boolean empty() {
        return queue_1.size() == 0;
    }
}