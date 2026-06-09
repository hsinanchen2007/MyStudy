### 解题思路
我们可以想象一下。有两个栈，怎么样实现队列呢？由于栈只能操作顶部元素，而队列可以操作首位，那么我们不妨把两个栈分别当作队列的头部和尾部。
——————————————————————————
            |
——————————————————————————
像这样，把栈变成一个中间有个隔板的队列。从左边的地方入栈。如果要进行删除，只要把左边的所有元素出栈，放到右边的栈里面就好了。

所以这就需要你对於数据结构掌握的非常熟练，才能够看出本质。
### 代码

```java
class MyQueue {
    Stack<Integer> s1;
    Stack<Integer> s2;
    /** Initialize your data structure here. */
    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(s2.isEmpty()){
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if(s2.isEmpty()){
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            }
        }
        return s2.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return s1.isEmpty()&&s2.isEmpty();
    }
}


```