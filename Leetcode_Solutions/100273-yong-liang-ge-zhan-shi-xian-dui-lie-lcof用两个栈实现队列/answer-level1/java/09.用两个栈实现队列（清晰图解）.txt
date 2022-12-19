### 执行结果
执行时间：88ms，击败了76.71%用户
内存消耗：74.9MB，击败了100%用户；
### 解题思路
![image.png](https://pic.leetcode-cn.com/da308b27d42154eed75878675a28051594de4de9545a296684144a0d4f8e278b-image.png)


### 代码

```java
class CQueue {
    Stack<Integer> st1=new Stack<Integer>();
	Stack<Integer> st2=new Stack<Integer>();
    public CQueue() {
        
    }
    
    public void appendTail(int value) {
        st1.push(value);
    }
    
    public int deleteHead() {
        if(!st2.isEmpty()) {
			return st2.pop();
		}else {
			if(!st2.isEmpty()) {
			return st2.pop();
		}else {
			if(st1.isEmpty()) {
				return -1;
			}else {
				while(!st1.isEmpty()) {
					st2.push(st1.pop());
				}
				return st2.pop();
			}
		}
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