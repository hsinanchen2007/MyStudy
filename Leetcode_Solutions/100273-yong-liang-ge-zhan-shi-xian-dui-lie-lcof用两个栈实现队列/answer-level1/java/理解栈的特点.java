### 解题思路
时间复杂度：入栈：O(1), 出栈：O(n), 一般情况下不会是O(n)


### 代码

```java
class CQueue {

    private Stack<Integer> sIn;
    private Stack<Integer> sOut;


    public CQueue() {
        sIn = new Stack<Integer>();
        sOut = new Stack<Integer>();
    }
    
    public void appendTail(int value) {
        sIn.push(value);
    }
    
    public int deleteHead() {
        if (sOut.isEmpty()) {
            while(!sIn.isEmpty()) {
                sOut.push(sIn.pop());
            }
        }
        return sOut.isEmpty() ? -1 : sOut.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```