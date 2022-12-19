### 解题思路
基础太差，只能多借鉴大佬们的解题方法，
下面是用Java双队列做的，注释的都是做的时候犯的低级错误。
### 代码

```java
class MyStack {//使用双队列解决//
    private Queue<Integer> a;
    private Queue<Integer> b;

    /** Initialize your data structure here. */
    public MyStack() {
        a=new LinkedList<>();
        b=new LinkedList<>();      
    }
    
    /** Push element x onto stack. */
public void push(int x) {
    a.add(x);
}

public int pop() {//移除
    if (a.isEmpty()!=true){
        while (a.size()>1){
            b.add(a.poll());
        }return a.poll();
    }else{
        while(b.size()>1){
            a.add(b.poll());
        }return b.poll();
    }
    
}

    /** Get the top element. */
    public int top() {//得到后再放回
            int top=0;
          if (a.isEmpty()!=true){
        while (a.size()>1){
            b.add(a.poll());
        }top= a.poll();
        b.add(top);
    }else{
        while(b.size()>1){
            a.add(b.poll());
        }top=b.poll();
        a.add(top);
    }
    return top;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
    return a.isEmpty() && b.isEmpty();//双队列必须连个都为空才为空！！！//
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