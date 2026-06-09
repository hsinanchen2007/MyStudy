### 解题思路
这里注意，要先把st2的数据全部拿出后才能再从st1中拿数据去st2

### 代码

```java
class CQueue {
	private Stack<Integer> st1 ;
	private Stack<Integer> st2 ;
    public CQueue() {
    	st1= new Stack<Integer>();
    	st2 = new Stack<Integer>();
    }
    
    public void appendTail(int value) {
    	st1.push(value);
    }
    
    public int deleteHead() {
		if(st2.size()==0) {
			if(st1.size()!=0) {
				int size = st1.size();
		    	for(int i=0;i<size;i++) {
					st2.push(st1.pop());
				}
	    	
			}
		}
		if(st2.size()==0) return -1;
		return st2.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```