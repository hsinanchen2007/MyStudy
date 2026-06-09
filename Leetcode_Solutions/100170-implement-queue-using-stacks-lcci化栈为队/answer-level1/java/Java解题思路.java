### 解题思路
首先明确两个数据结构的特点：
    队列：先进显出
    栈：先进后出
本题需要使用两个栈来实现队列，具体实现思路如下：
1. 定义两个栈，inStack用来push数据，outStack用来读取数据
2. push方法向inStack里放数据
3. pop和peek方法都是读取数据，因为outStack是用来读取数据的栈，那么我们将inStack的数据全部压入outStack中，在outStack中的数据就是inStack数据的倒序，然后直接中outStack中获取数据即可，需要注意的是只有当outStack为空的时候才会从inStack中将数据全部压入，否则顺序会出错。

### 代码

```java
class MyQueue {

    //出栈
    private Stack<Integer> inStack = new Stack<Integer>();
    //入栈
    private Stack<Integer> outStack = new Stack<Integer>();

     /**
     * Initialize your data structure here.
     */
    public MyQueue() {

    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
       inStack.push(x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
        peek();
        return outStack.pop();
    }

    /**
     * Get the front element.
     */
    public int peek() {
        if(outStack.isEmpty()){
            //将inStack数据全部压入outStack中
            while (!inStack.isEmpty()){
                outStack.push(inStack.pop());
            }
        }
        return outStack.peek();
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
        return outStack.isEmpty() && inStack.isEmpty();
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