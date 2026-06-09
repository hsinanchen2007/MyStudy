### 解题思路
一个栈用于存放数据，另一个栈用于辅助。我们把栈顶看作是队首，栈底看作是队尾，由于无法在栈底直接插入元素，所以我们先把栈中原来的元素都移到另一个栈里，然后在栈底插入新元素就相当于在队尾插入了元素。要在队首删除元素则直接弹出栈顶元素即可。为了实现取队首元素操作，我们维护front这个变量，时刻保存当前栈顶元素的值。队列的判空操作则和栈一样。

### 代码

```java
class MyQueue {
    
    Stack<Integer> s1;
    Stack<Integer> s2;
    int front;
    int size;
    
    /** Initialize your data structure here. */
    public MyQueue() {
        s1=new Stack<>();
        s2=new Stack<>();
        front=0;
        size=0;
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        if(s1.empty()){
            front=x;
        }
        while(!s1.empty()){
            s2.push(s1.pop());
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.pop());
        }
        size++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(size==0){
            return -1;
        }
        size--;
        int p=s1.pop();
        if(!s1.empty())
            front=s1.peek();
        return p;
    }
    
    /** Get the front element. */
    public int peek() {
        return front;
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return s1.isEmpty();
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