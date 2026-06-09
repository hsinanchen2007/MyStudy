### 解题思路
此处撰写解题思路

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
        stack1.add(value);
    }

    public int deleteHead() {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }

        int delete = -1;
        if (!stack2.isEmpty()) {
            delete = stack2.pop();
        }
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
        return delete;
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```