### 解题思路
主要是使用两个queue,
其中一个queue 用来存放, 另一个queue用来当临时queue, 每次pop的时候 把不空的queue里面的值(除了最后一个) 都导到另一个空的queue里面, 然后把最后一个poll出去, 如果是top的话 poll完了 还要再自己push回去就好了.

### 代码

```java
class MyStack {

    Queue<Integer> queue1;
    Queue<Integer> queue2;
    /** Initialize your data structure here. */
    public MyStack() {
       queue1 = new LinkedList<>();
       queue2 = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(!queue1.isEmpty()){
            queue1.add(x);
        } else {
            queue2.add(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        Queue<Integer> q2 = move();
        return q2.poll();
    }

    private Queue move(){
        Queue<Integer> q1;
        Queue<Integer> q2;
        if(queue1.isEmpty()){
            q1 = queue1;
            q2 = queue2;
        } else {
            q1 = queue2;
            q2 = queue1;
        }
        while(!q2.isEmpty() && q2.size() > 1){
            q1.add(q2.poll());
        }
        return q2;
    }
    
    /** Get the top element. */
    public int top() {
       Queue<Integer> q2 = move();
       int res = q2.poll();
       push(res);
       return res;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue1.isEmpty() && queue2.isEmpty();
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