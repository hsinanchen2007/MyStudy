### 解题思路
单一栈+最小值变量（min）的方法：用Deque接口创建LinkedList类型的栈的方法，比直接使用Stack类型实现的方法节省了一半的时间，在这里备忘一下。

### 代码

```java
class MinStack {

    /** initialize your data structure here. */
    // 非原创 受8ms方法启发 单一栈方法（用LinkedList队列方式表示栈） 用变量存放最小值
    Deque<Integer> stack;
    int min;    
    public MinStack() {
        stack = new LinkedList<Integer>();
        min = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        if(x <= min) {
            stack.push(min);
            stack.push(x);
            min = x;
        }
        else {
            stack.push(x);
        }
    }
    
    public void pop() {
        if(stack.pop() == min) {
            min = stack.pop(); // 两次弹出 更新最小值
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```