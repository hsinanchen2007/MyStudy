### 解题思路
![image.png](https://pic.leetcode-cn.com/0f0fd584e40f3f47ecb7d00bb97e6bd463beb46f652d55aec89c5660115cf1af-image.png)

1.首先构造时初始化两个栈。
2.入队列时不需要判断，只需要在出队列时尽心判断即可。
    2.1首先，保证将反转为队列形式的数据全都优先出队列
    2.2未反转的数据反转为队列形式数据
    2.3校验是否为空
    2.4正常出队列


### 代码

```java
class CQueue {
    private Stack<Integer> stack1;

    private Stack<Integer> stack2;

    public CQueue() {
        this.stack1 = new Stack<>();
        this.stack2 = new Stack<>();
    }

    public void appendTail(int value) {
        stack1.push(value);
    }

    public int deleteHead() {
        if (!stack2.empty()) {
            return stack2.pop();
        }
        while (!stack1.empty()) {
            stack2.push(stack1.pop());
        }
        if (stack2.empty()) {
            return -1;
        }
        return stack2.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```