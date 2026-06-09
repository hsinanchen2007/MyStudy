### 解题思路
1，单栈思路(未实现)：
具体做法是 假设一个栈 要押入的元素是 1 2 3 4 ，押入1为栈底，然后押入2，押入2的时候1出栈 再重新入栈 这样从栈底来看就是 2 1，然后再押入3，让原栈内元素出栈再入栈 这样就是 3 2  1
2.双栈思路：
（1）一个栈push，当要pop的时候，把push栈的值弹出押入到pop栈里。实现队列的先进先出。
     * 注意该操作只在 stackPop 里为空的时候才操作，否则会破坏出队入队的顺序
     * 在 peek 和 pop 操作之前调用该方法
     * 否则队列顺序会被打乱
### 代码

```java
class MyQueue {

    /** Initialize your data structure here. */
    
          private Stack<Integer>stackPush;
          private Stack<Integer>stackPop;
    
        public MyQueue() {
        stackPush = new Stack<>();
        stackPop = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stackPush.push(x);

    }
    
    public void shift(){
        if(stackPop.isEmpty())
        while(!stackPush.isEmpty())
        {
            stackPop.push(stackPush.pop());
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
           shift();
            if (!stackPop.isEmpty()) {
            return stackPop.pop();
        }
        throw new RuntimeException("队列里没有元素");
    }
    
    /** Get the front element. */
    public int peek() {
          shift();
        if (!stackPop.isEmpty()) {
            return stackPop.peek();
        }
        throw new RuntimeException("队列里没有元素");
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