### 解题思路
创建两个Stack，每当插入一个新元素的时候，先检查stack1里面是否为空，如果不空，就将Stack1中元素放入stack2中，然后size+1，将新元素放入stack1中。当删除元素的时候，先检查size是否为0，如果为0返回-1；接着检查stack2中是否空，不空就将stack2中元素依次pop（）再push进stack1，这样就能保证先进的元素在stack1的顶部。

### 代码

```java
class CQueue {

    Stack<Integer> stack1;
    Stack<Integer> stack2;
    int size;
    public CQueue() {
        stack1=new Stack<>();
        stack2=new Stack<>();
        size=0;

    }

    public void appendTail(int value) {

        while (!stack1.isEmpty()){
            stack2.push(stack1.pop());
        }
        stack1.push(value);
        size++;
    }

    public int deleteHead() {
        if(size==0)return -1;
        else{
            while(!stack2.isEmpty()){
                stack1.push(stack2.pop());
            }
        }
        size--;
        return stack1.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```