### 解题思路
此处撰写解题思路

建立2个栈s1,s2。
1）当执行push操作时，如果s1为空，那么front指针指向push进来的x。将x压入栈中。
2）执行pop操作时，如果s2为空，就将s1中的数先弹出，然后再压入s2中，此时s2的顺序是s1倒过来的顺序，也就是队列的顺序，队首在栈顶。弹出s2栈顶就是弹出队列的队首。

### 代码

```java
class MyQueue {
    Stack<Integer> s1;
    Stack<Integer> s2;
    int front;

    /** Initialize your data structure here. */
    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();

    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        if(s1.empty()){
            front = x;
        }
        s1.push(x);

    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(s2.empty()){
            while(!s1.empty()){
            s2.push(s1.pop());
        }
        }
        return s2.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if(!s1.empty()){
            return front;
        }
        return s2.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;

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
```