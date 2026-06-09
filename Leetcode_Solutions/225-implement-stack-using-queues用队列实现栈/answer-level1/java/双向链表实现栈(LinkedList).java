```java
class MyStack {
    /*双向链表实现栈*/
    private LinkedList<Integer> list;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {
        list = new LinkedList<Integer>();
    }
    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        list.add(x);
    }
   
    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        if (empty()) {
            return 0;
        } else {
            int pop = list.remove(list.size()-1);
            return pop;
        }

    }
    /**
     * Get the top element.
     */
    public int top() {
        if(empty()){
            return 0;
        }else{
            return list.get(list.size()-1);
        }
    }
    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return list.isEmpty();
    }
}

```