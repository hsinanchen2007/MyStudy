### 解题思路
使用两个队列模拟，详情见代码

### 代码

```java
class MyStack {

    /** Initialize your data structure here. */
    Queue<Integer> q,p;
    public MyStack() {
        q=new LinkedList<>();
        p=new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        if(q.isEmpty()) p.offer(x);
        else q.offer(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(q.size()!=0){
            while(q.size()>1){
                p.add(q.poll());
            }
            return q.poll();
        }
        else if(p.size()!=0){
            while(p.size()>1){
                q.add(p.poll());
            }
            return p.poll();
        }
        else return -1;
       
    }

    /** Get the top element. */
    public int top() {
        int top=0;
        if(q.size()>0){
            while(q.size()>=1){
                top=q.poll();
                 p.add(top);
             }
        }
        else if(p.size()>0){
            while(p.size()>=1){
                top=p.poll();
                q.add(top);
            }
        }
        
        return top;
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return p.isEmpty()&&q.isEmpty();
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