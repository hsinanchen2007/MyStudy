### 解题思路
执行用时 :95 ms, 在所有 Java 提交中击败了59.52% 的用户
内存消耗 :46.4 MB, 在所有 Java 提交中击败了100.00%的用户
### 代码

```java
class CQueue {
    private Stack<Integer> head;
    private Stack<Integer> tail;
    public CQueue() {
        head = new Stack<>();
        tail = new Stack<>();
    }

    public void appendTail(int value) {
        tail.push(value);
    }

    public int deleteHead() {
        if (head.isEmpty()) {
            if (tail.isEmpty()) return -1;
            while (!tail.isEmpty()) {
                head.push(tail.pop());
            }
        }
        return head.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```