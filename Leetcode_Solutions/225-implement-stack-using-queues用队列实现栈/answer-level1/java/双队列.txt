### 解题思路
双队列法解决

### 代码

```java
class MyStack {
    //双队列
    /** Initialize your data structure here. */
    LinkedList<Integer> queue1=new LinkedList<>();
    LinkedList<Integer> queue2=new LinkedList<>();
    public MyStack() {

    }
    //队列轮流使用
    /** Push element x onto stack. */
    public void push(int x) {
        if(!queue1.isEmpty())
        queue1.offer(x);
        else
        queue2.offer(x);
    }
    //出栈的时候将有数据的队列除队尾外入队到另一个队列，剩下的一个即是栈顶
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(!queue1.isEmpty()){
        while(queue1.size()>1)
        queue2.offer(queue1.poll());
        return queue1.poll();
       }else{
        while(queue2.size()>1)
        queue1.offer(queue2.poll());
        return queue2.poll();   
       }
    }
    //与出队同理
    /** Get the top element. */
    public int top() {
        int top=0;
        if(!queue1.isEmpty()){
        while(queue1.size()>1)
        queue2.offer(queue1.poll());
        top=queue1.poll();
        queue2.offer(top);
       }else {
        while(queue2.size()>1)
        queue1.offer(queue2.poll());
        top=queue2.poll();
        queue1.offer(top);   
       }
       return top;
    }
    //要两个队列为空才为空
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue1.isEmpty()&&queue2.isEmpty();
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