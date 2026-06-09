### 解题思路
入栈就是正常入栈，每次deleteHead直接调用removeElementAt(0)

### 代码

```java
class CQueue {
    Stack<Integer> out;
    
    public CQueue() {
        out = new Stack<Integer>();
    }
    
    public void appendTail(int value) {
        out.add(value);
    }
    
    public int deleteHead() {
        if(!out.empty()) {
        	int ans = out.elementAt(0);
        	out.removeElementAt(0);
        	return ans;
        }
        	
    	return -1;
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```