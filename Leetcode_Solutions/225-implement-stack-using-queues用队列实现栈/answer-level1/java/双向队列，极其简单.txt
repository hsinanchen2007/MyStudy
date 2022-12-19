class MyStack {

   Deque<Integer> queue = new LinkedList<>();
    /** Initialize your data structure here. */
    public MyStack() {
        queue = new  LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        queue.add(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.pollLast();
    }

    /** Get the top element. */
    public int top() {
        return queue.peekLast();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        if(queue.size() == 0){
            return true;
        }else{
            return false;
        }
    }
}