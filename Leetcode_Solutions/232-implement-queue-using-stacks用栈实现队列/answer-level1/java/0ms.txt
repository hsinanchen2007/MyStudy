### 解题思路
采用两个栈s1、s2，s1入队，s2出队
元素入队offer时：元素直接入s1
元素出队poll或者取对首元素peek时：
   如果s2为空，那么把s1中所有元素出栈并入s2，然后对s2进行pop/peek;
   如果s2不为空，直接对s2进行pop/peek。
判断队是否为空时：
   只有s1、s2同时为空，队才为空。
### 代码

```java
class MyQueue {
    Stack<Integer> in,out;
    /** Initialize your data structure here. */
    public MyQueue() {
         in = new Stack<>();
         out = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(out.empty()){
            while(!in.empty()){
                out.push(in.pop());
            }
        }
        return out.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if(out.empty()){
            while(!in.empty()){
                out.push(in.pop());
            }
        }
         return out.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return(in.empty()&&out.empty());
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