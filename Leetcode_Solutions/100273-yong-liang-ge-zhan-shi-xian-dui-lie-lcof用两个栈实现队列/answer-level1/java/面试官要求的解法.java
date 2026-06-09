### 解题思路
没必要一直stack1  stack2一直倒腾；
只有当stack2为空时，再遍历stack1，向stack2中加入所有元素；新增元素，不管什么情况，只往stack1中添加；
这样效率最高。

### 代码

```java
class CQueue {
    Stack<Integer> stack1;
    Stack<Integer> stack2;

    public CQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    public void appendTail(int value) {
        stack1.push(value);
    }
    
    public int deleteHead() {
        if(!stack2.empty()){
            return stack2.pop();
        }
        //stack2为空
        if(!stack1.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.pop());
            }
        }else{
            return -1;
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