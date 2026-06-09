### 使用java自带的api解题
使用这个方式解题不得不说就是为了了解一下javaAPI而已，这样对理解数据结构，这样做没有其他好处，那么我们尝试使用数组来自己设计一个双端队列来解决该题

```
class MyStack {
    
    private ArrayDeque<Integer> queue;
    
    /** Initialize your data structure here. */
    public MyStack() {
        this.queue = new ArrayDeque<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue.addFirst(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int result =  queue.getFirst();
        queue.pop();
        return result;  
    }
    
    /** Get the top element. */
    public int top() {
        return queue.getFirst();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.size() == 0 ? true : false;
    }
}
```

### 使用数组完成双端队列
这里就是使用简单的循环队列来实现，主要是注意到循环队列其实就有固定的两根指针，其实，这样做确实有点犯规，其实本质还是个栈，不过只是有队列的功能，贴上代码以供参考
```
class MyStack {
    // 创建循环队列
    private int[] queue;
    // 用于指示队列的前端,使用与top一致，后面弃用，但是为了保证两个结构的一致性，我还是留着这里
    private int front;
    // 用于指示队列的后端
    private int rear;
    // 用于指示栈顶指针
    private int top;
    
    /** Initialize your data structure here. */
    // 初始化队列，rear指定为-1，表示不可删除，在删除过程中可作为判断条件
    public MyStack() {
        queue = new int[20];
        rear = -1;
        top = 0;
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue[top] = x;
        top = (top + 1) % queue.length;
        // 队列已满
        if(top == rear){
            return;
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        // 队列还没有元素
        if(empty()){
            return -1;
        }
        top = (top - 1) % queue.length;
        return queue[top];
    }
    
    /** Get the top element. */
    public int top() {
        return queue[(top-1)%queue.length];
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        if( (rear+1)%queue.length == top ){
            return true;
        }
        return false;
    }
}
```