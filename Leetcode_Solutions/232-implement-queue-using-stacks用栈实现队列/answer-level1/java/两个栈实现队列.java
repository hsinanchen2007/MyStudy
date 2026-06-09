### 解题思路
1 两个栈一个负责 push 一个负责 pop
2 当 pop栈 没有元素的时候才需要 将 push栈 的元素导入,非空导入会打乱顺序

### 代码

```java
class MyQueue {

    Stack<Integer> stackPush;
    Stack<Integer> stackPop;
    /** Initialize your data structure here. */
    public MyQueue() { // 构造函数中只能赋值 不能声明 否则编译不通过
        stackPush = new Stack<>();
        stackPop = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stackPush.push(x);
    }
    
    // 在 pop peek 前检查stackPop是不是空的 
    // 空的就把 stackPush中的元素全部倒进来
    private void shift(){
        if (stackPop.isEmpty()){
            while (!stackPush.isEmpty()){
                int i = stackPush.pop();
                stackPop.push(i);
            }
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        shift();
        return stackPop.pop();
                
    }
    
    /** Get the front element. */
    public int peek() {
        shift();
        return stackPop.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stackPush.isEmpty() && stackPop.isEmpty();
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