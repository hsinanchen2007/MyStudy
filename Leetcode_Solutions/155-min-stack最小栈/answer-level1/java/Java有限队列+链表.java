### 解题思路
此处撰写解题思路

### 代码

```java
class MinStack {

    public static PriorityQueue<Integer> pq;
    public static LinkedList<Integer> l;
    /** initialize your data structure here. */
    public MinStack() {
        pq = new PriorityQueue<Integer>();
        l = new LinkedList<Integer>();
    }
    
    public void push(int x) {
        pq.offer(x);
        l.addLast(x);
    }
    
    public void pop() {
        int x = l.pollLast();
        pq.remove(x);
    }
    
    public int top() {
        return l.peekLast();
    }
    
    public int getMin() {
        return pq.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```