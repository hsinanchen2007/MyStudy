1. 单链表维护栈， head指针指向栈顶，出栈入栈只需操作head指针；
2. 全局变量保存当前最小值，入栈时判断是否更新；
3. 每个节点记录入栈前的最小值，出栈时将入栈前的最小值回写；

```java
class MinStack {
    
    LinkNode head;
    int min;
    
    /** initialize your data structure here. */
    public MinStack() {
        this.head = null;
    }
    
    public void push(int x) {
        LinkNode node = new LinkNode(x);
        if(head == null) {
            head = node;
            this.min = x;
        } else {
            node.preMin = this.min;
            node.next = head;
            head = node;
            this.min = this.min < x ? this.min : x;
        }
        
    }
    
    public void pop() {
        if(head != null) {
            this.min = head.preMin;
            head = head.next;
        }
    }
    
    public int top() {
        if(head != null) {
            return head.val;
        }
        throw new RuntimeException("empty stack!");
    }
    
    public int getMin() {
        if(head != null) {
           return this.min; 
        }
        throw new RuntimeException("empty stack!");
    }
    
    class LinkNode {
        int val;
        int preMin;
        LinkNode next;
        LinkNode(int val) {
            this.val = val;
        }
    }
}
```
