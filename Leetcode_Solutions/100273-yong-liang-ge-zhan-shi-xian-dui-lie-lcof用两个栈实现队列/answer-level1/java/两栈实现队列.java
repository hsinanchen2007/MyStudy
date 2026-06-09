### 解题思路
此处撰写解题思路

### 代码

```java
class CQueue {
    //两个栈实现队列，一个栈负责入队，一个栈负责出队
    Stack<Integer> s1;
    Stack<Integer> s2;
    public CQueue() {
        s1=new Stack<>();
        s2=new Stack<>();
    }
    
    public void appendTail(int value) {
        s1.push(value);
    }
    
    public int deleteHead() {
        if(!s2.isEmpty())
            return s2.pop();
        else
        {
            while(!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
            if(!s2.isEmpty())
                return s2.pop();
            else    
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