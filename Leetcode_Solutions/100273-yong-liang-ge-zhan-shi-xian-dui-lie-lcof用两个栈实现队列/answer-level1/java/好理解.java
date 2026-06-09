

```java
class CQueue {

    Stack<Integer> head = new Stack<>();
    Stack<Integer> tail = new Stack<>();

    public CQueue() {
        
    }
    
    public void appendTail(int value) {//只入栈
        tail.push(value);
    }
    
    public int deleteHead() {
        if(head.empty()){//看head是否为空  不为空直接从head出，如果为空 tail的倒进来再出
            if(tail.empty()) return -1;
            while (!tail.empty()) {
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