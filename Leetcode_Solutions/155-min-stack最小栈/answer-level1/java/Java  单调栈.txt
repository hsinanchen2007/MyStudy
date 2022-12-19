### 解题思路
执行用时 :7 ms, 在所有 Java 提交中击败了92.28% 的用户
内存消耗 :39.2 MB, 在所有 Java 提交中击败了96.48%的用户

两个栈，一个栈存放真实数据，另一个栈维护 前n个数的最小值。
例如：
stack 栈顶：  2  0 5  栈底
stackMin 栈顶：0  0  5 栈底  

解释stackMin:  前一个数的最小值是5，前两个数的最小值是0，前三个数的最小值是0。


### 代码

```java
class MinStack {

    Stack<Integer> stack = new Stack<>();
    Stack<Integer> stackMin = new Stack<>();

    /** initialize your data structure here. */
    public MinStack() {
        
    }
    
    public void push(int x) {
        stack.push(x);

        if (stackMin.isEmpty()) stackMin.push(x);        // 维护最小栈,表示前n个数的最小值
        else stackMin.push(Math.min(x,stackMin.peek()));
    }
    
    public void pop() {
        stack.pop();            // 两个栈同步弹出
        stackMin.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return stackMin.peek();  // 栈顶即最小值
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