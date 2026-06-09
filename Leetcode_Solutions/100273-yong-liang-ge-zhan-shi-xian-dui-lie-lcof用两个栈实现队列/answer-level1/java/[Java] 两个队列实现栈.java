### 解题思路
建立两个栈，一个用来插入数据，一个用来输出。

### 代码

```java
class CQueue {
     private Stack<Integer> stack1 ;
     private Stack<Integer> stack2 ;
    
     public CQueue() {
        stack1 = new Stack<Integer>();
        stack2 = new Stack<Integer>();
    }
    
     public void appendTail(int value) {
        stack1.push(value);
        return;
    }
    
     public int deleteHead() {
        if(stack2.empty()){
            if(stack1.empty()){
            return -1; 
            }else{
                while(!stack1.empty()){
                stack2.push(stack1.pop());
                }
            }
        }
            return stack2.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```