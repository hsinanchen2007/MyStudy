### 解题思路
此处撰写解题思路

### 代码

```java
class MinStack {

    /** initialize your data structure here. */
  private Stack<Integer> minstack;
    private Stack<Integer> helpstack;

    public MinStack() {
        minstack = new Stack<>();
        helpstack = new Stack<>();
    }

    public void push(int x) {
        helpstack.push(x);
         if (minstack.isEmpty() || minstack.peek() >= x)
            minstack.push(x);
    }

    public void pop() {
        int x = helpstack.pop();
        if (x == minstack.peek())
            minstack.pop();
    }

    public int top() {
        return helpstack.peek();
    }

    public int min() {
        return minstack.peek();
    }


}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */
```