### 解题思路
此处撰写解题思路

### 代码

```java
class CQueue {
    Stack<Integer> st1 = null;
    Stack<Integer> st2 = null;
    public CQueue() {
        st1 = new Stack<Integer>();
        st2 = new Stack<Integer>();
    }
    
    public void appendTail(int value) {
        st1.push(value);
    }
    
    public int deleteHead() {
        if(!st2.empty()){
            return st2.pop();
        }else if(!st1.empty()){
            while(!st1.empty()){
                st2.push(st1.pop());
            }
            return st2.pop();
        }else{
            return -1;
        }
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```