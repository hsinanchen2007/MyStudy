### 解题思路
1、声明两个队列
2、在每次调用 push 方法时，判断队列1是否为空。为空，则将数据添加进队列1；若不为空，则遍历将队列1数据    添加进队列2，将新数据添加进队列1，然后再将队列2的数据添加进队列1
3、pop、top 则都是获取队列1的第一个数据

### 代码

```java
class MyStack {

    Queue<Integer> mQueue1;
    Queue<Integer> mQueue2;
    /** Initialize your data structure here. */
    public MyStack() {
        mQueue1 = new LinkedList<>();
        mQueue2 = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(mQueue1.peek() != null) {
            while(mQueue1.peek() != null) {
                mQueue2.offer(mQueue1.poll());
            }
            mQueue1.offer(x);
            while(mQueue2.peek() != null) {
                mQueue1.offer(mQueue2.poll());
            }
        }else {
            mQueue1.offer(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(mInQueue.peek() == null) {
            return 0;
        }
        return mInQueue.poll();
    }
    
    /** Get the top element. */
    public int top() {
        if(mInQueue.peek() == null) {
            return 0;
        }
        return mInQueue.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return mInQueue.size() == 0 ? true : false;
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