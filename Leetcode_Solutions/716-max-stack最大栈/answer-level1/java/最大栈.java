### 解题思路
此处撰写解题思路

### 代码

```java
class MaxStack {

    /** initialize your data structure here. */
    Stack<Integer> stack;
    Stack<Integer> maxstack;
    public MaxStack() {
        stack=new Stack<>();
        maxstack=new Stack<>();
    }
    
    public void push(int x) {
        int max=maxstack.isEmpty()? x:maxstack.peek();
        maxstack.push(max>x? max:x);
        stack.push(x);
    }
    
    public int pop() {
        maxstack.pop();
        return stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int peekMax() {
        return maxstack.peek();
    }
    
    public int popMax() {
        int max=peekMax();
        Stack<Integer> buffer=new Stack();
        while(top()!=max){
            buffer.push(pop());
        }
        pop();
        while(!buffer.isEmpty()){
            push(buffer.pop());   //这里注意重新push回去时不能忘了push最大栈
        }
        return max;
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
```