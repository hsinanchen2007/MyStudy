### 解题思路
由于之前写过两个栈实现队列，看到这个题目就想着用两个队列来实现栈。
- `push()`:第一个队列`q1`直接`poll()`值进去
- `pop()`:`q1`用于`offer()`另外一个队列`q2`用来临时存储，`poll()`第一个队列的最后一个值，`q2`的值返回`q1`。
- `top()`:和`pop()`差不多，只是把方法`poll()`改为方法`peek()`。
- `empty()`:就返回`q1.isEmpty()`。
想了一下觉得操作过多，于是看了一下官方，果然反而一个队列实现更简单。自己被固定思维限制住了。
只需要在`push()`上操作，不断的出队，入队，直到第一个元素是刚插进去的元素就可以。这样其他方法就简单了。

细节：
1. 需要注意`return`值
2. 队列初始化需要放在函数外，否则其他方法无法取到队列。
3. `push()`中的循环需要 - 1，因为最后一个元素不需要出队。

### 代码

```java
class MyStack {

    Queue<Integer> q = new LinkedList<>();

    /** Initialize your data structure here. */
    public MyStack() {
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q.offer(x);
        int size = q.size() - 1;
        while(size > 0){
            q.offer(q.poll());
            size--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return q.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return q.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.isEmpty();
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