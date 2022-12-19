### 解题思路
此处撰写解题思路
之前面经里老看见这道题，没想到就这就这
执行用时 :
335 ms
, 在所有 Java 提交中击败了
25.89%
的用户
内存消耗 :
47.8 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class CQueue {
    int size;
    Stack<Integer> stack1;
    Stack<Integer> stack2;
    public CQueue() {
        this.size = 0;
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    public void appendTail(int value) {
        while (!stack1.isEmpty()){
            stack2.push(stack1.pop());
        }
        stack1.push(value);
        while (!stack2.isEmpty()){
            stack1.push(stack2.pop());
        }
        size++;
    }
    
    public int deleteHead() {
        if (size == 0) return -1;
        size--;
            return stack1.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```