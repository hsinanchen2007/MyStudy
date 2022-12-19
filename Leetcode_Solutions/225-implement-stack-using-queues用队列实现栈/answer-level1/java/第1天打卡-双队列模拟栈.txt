### 解题思路
考虑栈的特点是先进后出，队列的特点是先进先出。所以选择用两个队列来模拟栈的行为。
始终维持一个队列为空，将空队列作为数据在另一个队列模拟栈行为的中转区域（不知道用什么词来描述）。
1、push:哪个队列为空，则插入到另一个队列中；
2、pop:将非空队列A的数据一个个取出放到空队列B中，当非空队列还剩最后1个元素时，就是栈顶元素，由于需
要移除该值，所以非空队列A的最后一个元素不放到原空队列B中；
3、top:和pop行为很像，唯一不同的点就是作为栈顶的元素只是取其值，而不用移除，因此选择用临时变量来
保存每次移动的值;
4、empty：判断两个队列是否为空即可。
### 代码

```java
class MyStack {

    Queue<Integer> q0 = new LinkedList<Integer>();
    Queue<Integer> q1 = new LinkedList<Integer>();

    /** Initialize your data structure here. */
    public MyStack() {
        
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(q1.isEmpty()){
            q0.add(x);
        }else{
            q1.add(x);
        }

    }
    // 4 3 2

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int res = 0;
        
        if(q1.isEmpty()){
            while(q0.size()>1){
                q1.add(q0.poll());
            }
            res = q0.poll();
            return res;
        }

        if(q0.isEmpty()){
            while(q1.size()>1){
                q0.add(q1.poll());
            }
            res = q1.poll();
            return res;
        }
        return res;
    }
    
    /** Get the top element. */
    public int top() {
        int res = 0;
        
        if(q1.isEmpty()){
            while(!q0.isEmpty()){
                res = q0.poll();
                q1.add(res);
            }
            return res;
        }

        if(q0.isEmpty()){
            while(!q1.isEmpty()){
                res = q1.poll();
                q0.add(res);
            }
            return res;
        }
        return res;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return (q0.isEmpty()&&q1.isEmpty());
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