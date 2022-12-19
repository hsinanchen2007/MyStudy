### 解题思路
用一个辅助栈，与原栈同步入栈出栈，入栈时入的数是该数入栈后栈内的最小值。
辅助栈内存放的每个值即为该栈点以下的所有点中的最小值。
空间换时间的操作
### 代码

```java
class MinStack {

    private Stack<Integer> s;
    private Stack<Integer> helper;

    /** initialize your data structure here. */
    public MinStack() {
        s = new Stack<>();
        helper = new Stack<>();
    }
    
    public void push(int x) {
        s.push(x);

        if (helper.isEmpty()){
            helper.push(x);
        }else {
            helper.push(Math.min(x, helper.peek()));
        }
    }
    
    public void pop() {
        s.pop();
        helper.pop();
    }
    
    public int top() {
        return s.peek();
    }
    
    public int getMin() {
        return helper.peek();
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