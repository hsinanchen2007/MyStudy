### 解题思路
主要就是一个栈stack1用来进东西，一个栈stack2用来出东西，当要进队，则stack1.push()即可，当要出队时，先看stack2中有无内容，有的话就直接弹出
没有就从stack1中从栈顶到栈底pop，push到stack2中【逐个，这样保证先进的放在stack2的最上边】，把stack1搬空后，stack2.pop，当stack2、stack1都没有东西的时候就直接返回-1即可

### 代码

```java
class CQueue {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public CQueue() {
        this.stack1 = new Stack<>();
        this.stack2 = new Stack<>();
    }
    
    public void appendTail(int value) {
        stack1.push(value);
    }
    
    public int deleteHead() {
        
        if(stack2.size()<=0){
            if(stack1.size()<=0) return -1;
            for(int i = stack1.size();i>0;i--){
                stack2.push(stack1.pop());
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