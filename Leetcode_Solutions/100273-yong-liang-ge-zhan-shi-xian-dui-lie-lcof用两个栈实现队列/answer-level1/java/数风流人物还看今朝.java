### 解题思路
origin存放 appendTail 的数据
mirror中存放需要pop的数据，仅当mirror为空时才可以从origin pop并插入，结束后从mirror中pop出数据


### 代码

```java
class CQueue {
    private Stack<Integer> origin  = new Stack<>() ;
    private Stack<Integer> mirror  = new Stack<>() ;

    public CQueue() {

    }
    
    public void appendTail(int value) {
        origin.add(value) ;
    }
    
    public int deleteHead() {
        if (mirror.isEmpty()) {
            while (!origin.isEmpty()) {
                int v = origin.pop() ;
                mirror.add(v) ;
            }
        }
        return mirror.isEmpty() ? -1 : mirror.pop() ;
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```