### 解题思路
找到具有getMin功能的栈，采用集合替换对应的功能即可；

### 代码

```java
class MinStack {

    //采用集合假扮栈的功能即可
    /** initialize your data structure here. */
    LinkedList<Integer> list;
    public MinStack() {
        list = new LinkedList<>();
    }
    
    public void push(int x) {
        list.add(x);
    }
    
    public void pop() {
        list.pollLast();
    }
    
    public int top() {
        return list.peekLast();
    }
    
    public int min() {
        int min = Integer.MAX_VALUE;
        for(int i:list){
            min = Math.min(min,i);
        }
        return min;
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