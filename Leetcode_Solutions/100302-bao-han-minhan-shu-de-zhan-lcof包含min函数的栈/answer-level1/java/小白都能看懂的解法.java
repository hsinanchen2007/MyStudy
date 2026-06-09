### 解题思路
知乎大佬写的三个有关“栈与队列“的题目（包括这个min函数的栈），超简单，小白也能看懂。
https://zhuanlan.zhihu.com/p/101265667

### 代码

```java
class MinStack {
    Stack<Integer> stack;
    Stack<Integer> min;
    /** initialize your data structure here. */
    public MinStack() {
        stack=new Stack<>();
        min=new Stack<>();
    }
    
    public void push(int x) {
        stack.push(x);
        if(min.isEmpty()){
            min.push(x);
        }else{
            int temp=x>min.peek()?min.peek():x;
            min.push(temp);
        }
    }
    
    public void pop() {
        stack.pop();
        min.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int min() {
        return min.peek();
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