### 解题思路

专门开辟一个辅助栈 assistStack 用于存储当前最小值，逻辑不复杂，看代码即可。

### 代码

```java
class MinStack {

    private Stack<Integer> stack;
    private Stack<Integer> assistStack;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<Integer>();
        assistStack = new Stack<Integer>();
    }
    
    public void push(int x) {
        stack.push(x);
        if(assistStack.isEmpty()){
            assistStack.push(x);
        }else if(x <= assistStack.peek()){
            assistStack.push(x);
        }
    }
    
    public void pop() {
        if(!stack.isEmpty()){
            int temp = stack.pop();
            if(!assistStack.isEmpty()){
                if(assistStack.peek() == temp){
                    assistStack.pop();
                }
            }
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int min() {
        if(!assistStack.isEmpty()){
            return assistStack.peek();
        }else{
            throw new IllegalArgumentException();
        }

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