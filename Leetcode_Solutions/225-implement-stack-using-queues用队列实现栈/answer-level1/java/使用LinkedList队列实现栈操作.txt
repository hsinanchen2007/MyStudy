### 解题思路
队列是先进先出，栈是先进后出。他们两个的特点可以说是完全相反，所以单个队列想让他的功能变成栈的功能是不可能的，所以这里，我用了两个队列。题目上的push方法传入的参数是int，所以这道题的数据都是int类型的，给LinkedList设泛型为Integer，否则获取到的数据还需要强转成Integer。
存数据的时候，就往里放数据，其实队列和栈是看不出来区别的。我这里在放数据的时候，将数据都放入到q2当中，在取数据的时候，因为要取最后放进去的数据，而队列又只能先进先出。所以将q2中的所有数据先都放到q1中，然后留下最后一个数据，将前面的数据再放回到q2中。这时q1中就只有一个数据，也就是最后放进去的数据。
这时，如果是删除数据，则再次存数据就不会有影响，而如果只是取数据不删除，再次存数据直接放到q2中就会有影响。所以当只是取数据时，需要在取完后将数据放回q2中。

### 代码

```java
class MyStack {

    private LinkedList<Integer> q1;
    private LinkedList<Integer> q2;
    /** Initialize your data structure here. */
    public MyStack() {
        q1 = new LinkedList<Integer>();
        q2 = new LinkedList<Integer>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q2.offer(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        makeQ1OnlyHaveOneElement();
        return q1.poll();
    }
    
    /** Get the top element. */
    public int top() {
        makeQ1OnlyHaveOneElement();
        int i = q1.getFirst();
        q2.offer(q1.poll());
        return i;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        if (q1.size() == 0 && q2.size() == 0){
            return true;
        }
        return false;
    }

    private void makeQ1OnlyHaveOneElement(){
        if (empty()){
            return;
        }
        if (q1.size() == 1){
            q2.offer(q1.poll());
        }
        int size = q2.size();
        for (int i = 0; i < size; i++){
            q1.offer(q2.poll());
        }
        for (int i = 0; i < size-1; i++){
            q2.offer(q1.poll());
        }
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
```