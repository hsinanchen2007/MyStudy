### 解题思路
    1.当插入时，直接插入stack1
    2.当删除时，当stack2不为空，弹出stack2栈顶元素，如果stack2为空，判断stack1是否为空，如果不为空，将stack1中全部数逐个出栈放进stack2中，在弹出stack2的栈顶元素，如果stack1为空，返回-1.

### 代码

```java
class CQueue {
    public Stack<Integer> stack1 =new Stack<>();
    public Stack<Integer> stack2 =new Stack<>();
    public CQueue() {
        
    }
    
    public void appendTail(int value) {
        stack1.push(value);

    }
    
    public int deleteHead() {
        if(stack2.isEmpty()){
            if(!stack1.isEmpty()){
                while(!stack1.isEmpty()){
                    stack2.push(stack1.pop());
                }
                return stack2.pop();
            }else{
                return -1;
            }
                
        }else{
            return stack2.pop();
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