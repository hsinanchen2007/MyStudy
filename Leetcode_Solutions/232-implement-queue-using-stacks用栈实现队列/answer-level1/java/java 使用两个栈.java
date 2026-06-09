### 解题思路
此处撰写解题思路

### 代码

```java
class MyQueue {
    
    Stack<Integer> pushStack = new Stack();//用于存储的栈
    Stack<Integer> popStack = new Stack();//用于往外抛的栈。注意栈和队列的特点，栈先进后出，队列先进先出
    /** Initialize your data structure here. */
    public MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        if(pushStack.isEmpty()){//如果 存储的栈是空的
            while(!popStack.isEmpty()){//抛出的栈不是空的
                pushStack.push(popStack.pop());//将抛出栈的所有内容都给存储栈
            }
        }
        pushStack.push(x);//这样就是在栈的未尾给加入新的元素
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
             if(popStack.isEmpty()){//如果 抛出的栈目前 没有东西
        while(!pushStack.isEmpty()){//存储的栈不是空的
                popStack.push(pushStack.pop());//我们把存储栈的元素都 给抛出的栈，实现从队列头抛出元素
            }
            }
            int temp = popStack.pop();//上一个变量去接收抛出栈的首个元素
            while(!popStack.isEmpty()){//此时抛出栈不是空，我们就把抛出栈所有元素都 还给存储栈
                pushStack.push(popStack.pop());
            }
            return temp;//返回抛出栈首个元素变
    }
    
    /** Get the front element. */
    public int peek() {
            if(popStack.isEmpty()){同上
        while(!pushStack.isEmpty()){
                popStack.push(pushStack.pop());
            }
            }
          int ret= popStack.peek();
          while (!popStack.isEmpty()){
              pushStack.push(popStack.pop());
          }
          return ret;
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return pushStack.isEmpty();//去判断我们存储栈有没有元素就可以了。因为我们pop，peek都保证在最后，将抛出栈的元素都还给了存储栈
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