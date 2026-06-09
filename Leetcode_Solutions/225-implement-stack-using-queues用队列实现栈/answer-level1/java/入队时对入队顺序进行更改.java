### 解题思路
题给pop和top操作返回的是int，所以初始化为Queue<Integer> queue,构造器里初始化为LinkedList可两头操作;
主要部分是push处，因为栈是后进先出，而队列是先进先出，所以用队列实现栈只需要在入队顺序上做文章即可：
每次元素入队时，对原有队列进行顺序出队再重新入队的当前如对元素后面去。比如队列已有元素{3，2，1}，下一个插入4，如果按队列正常插入那么结果是{3，2，1，4}，而经过不断的对队首元素进行出队再入队，步骤就变为如下：
{2，1，4，3}，{1，4，3，2}，{4，3，2，1}。
### 代码

```java
class MyStack {

Queue<Integer> queue;
    /** Initialize your data structure here. */
    public MyStack() {
        queue = new LinkedList();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue.add(x);
        for(int i = 0; i<queue.size()-1;i++){
            queue.add(queue.remove());
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return queue.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.size() == 0;
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