### 解题思路
这里采用双栈进行实现队列的基本操作：
- 实例化两个栈 stack1、stack2
- Queue.push(int x)
    这里 push 进 stack1 用来存数
``` Java
stack1.push(x);
```
- Queue.pop();
    首先，判断 stack2 中是否为空，如果不为空，直接从 stack2 弹出数据，当 stack2 为空时，此时说明之前没有弹出过数据，所以此时需要一层循环弹出 stack1 中的数据，stack2 进行 push
```
if(!stack2.empty()){
    return stack2.pop();
}else{
    while(!stack1.empty()) {
        stack2.push(stack1.pop());
    }
    return stack2.pop();
}
```
- peek()
    同 pop 算法，只需要把 pop() 改成栈的 peek() 即可
- empty()
    return stack1.empty() && stack2.empty()
- size()
    retrun stack1.size() + stack2.size()


### 代码

```java
class MyQueue {
    Stack<Integer> stack1 = new Stack<>();
    Stack<Integer> stack2 = new Stack<>();
    /** Initialize your data structure here. */
    public MyQueue() {
        // stack = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stack1.push(x);
        // System.out.println(stack1);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(!stack2.empty()){
            return stack2.pop();
        }else{
            while(!stack1.empty()) {
                stack2.push(stack1.pop());
            }
            return stack2.pop();
        }
    }
    
    /** Get the front element. */
    public int peek() {
        if(!stack2.empty()){
            return stack2.peek();
        }else {
            while(!stack1.empty()){
                stack2.push(stack1.pop());
            }
            return stack2.peek();
        }
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stack1.empty() && stack2.empty();
    }

    public int size() {
        return stack1.size() + stack2.size();
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