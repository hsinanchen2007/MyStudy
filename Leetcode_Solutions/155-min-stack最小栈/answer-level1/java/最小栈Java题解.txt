### 解题思路
首次发题解，望大佬们指点。
1. 创建一个helper stack；
2. 执行push时候，去比较辅助栈中当前的最小元素，如果更小，则进栈；
3. 由于最小的元素才会进辅助栈，所以最先的那个元素才会是最小。执行peek()直接就能找到答案；
4. 当原栈中执行pop()，那就要确定是否踢出的是最小元素，如果是，则辅助栈也要pop();

### 代码

```java
class MinStack {
    Stack<Integer> stack;
    Stack<Integer> minStack;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }
    
    public void push(int x) {
        if (stack.isEmpty()) {
            minStack.push(x);
        } else {
            int currMin = minStack.peek();
            if (currMin >= x) {
                minStack.push(x);
            }
        }
            stack.push(x);
    }
    
    public void pop() {
        if (stack.isEmpty()) {
            return;
        }
        int ele = stack.pop();
        if (minStack.peek() == ele) {
            minStack.pop();
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return minStack.peek();
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