### 解题思路
方法二：单个队列实现
1、声明队列
2、在新数据offer进队列后，判断队列的长度是否大于1,。若大于，则将队列最后一个元素之前的数据都转移到该    元素之后。

### 代码

```java
class MyStack {

    Queue<Integer> mQueue1;
    /** Initialize your data structure here. */
    public MyStack() {
        mQueue1 = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        mQueue1.offer(x);
        int i = 0;
        while(i < (mQueue1.size() - 1)){
            mQueue1.offer(mQueue1.poll());
            i++;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(mQueue1.peek() == null) {
            return 0;
        }
        return mQueue1.poll();
    }
    
    /** Get the top element. */
    public int top() {
        if(mQueue1.peek() == null) {
            return 0;
        }
        return mQueue1.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return mQueue1.size() == 0 ? true : false;
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