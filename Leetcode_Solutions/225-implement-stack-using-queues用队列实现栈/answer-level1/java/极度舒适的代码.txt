### 解题思路
此处撰写解题思路

### 代码

```java
class MyStack {

    private Queue<Integer> a;//输入队列
    private Queue<Integer> b;//输出队列
    
    public MyStack() {
        a = new LinkedList<>();
        b = new LinkedList<>();
    }
    
    public void push(int x) {
        a.add(x);
        // 将b队列中元素全部转给a队列中新加入元素的后面，这样满足栈的定义
        while(!b.isEmpty())
            a.add(b.poll());
        // 交换a和b,使得输入队列a队列始终为空队列
        Queue<Integer> temp = new LinkedList<>(a);
        a = b;
        b = temp;
    }
    
    public int pop() {
        return b.poll();
    }
   
    public int top() {
        return b.peek();
    }
    
    public boolean empty() {
        return b.isEmpty();
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