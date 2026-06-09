### 解题思路

把一个栈作为输入输出，一个栈作为中间变量

### 代码

```java
class CQueue {

    Stack<Integer> stack1;
    Stack<Integer> stack2;
    public CQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    public void appendTail(int value) {
        stack1.push(value);
    }
    
    public int deleteHead() {
        if(stack1.isEmpty()) return -1;
        int len = stack1.size();
        for(int i = 0; i < len; i ++) {
            stack2.push(stack1.pop());
        }
        int out = stack2.pop();
        for(int i = 1; i < len; i ++) {
            stack1.push(stack2.pop());
        }
        return out;
    }
}
```