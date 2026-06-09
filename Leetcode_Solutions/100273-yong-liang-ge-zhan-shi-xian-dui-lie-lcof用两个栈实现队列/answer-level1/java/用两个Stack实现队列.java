### 解题思路
一个栈用于存放数据，另一个栈用于辅助。我们把栈顶看作是队首，栈底看作是队尾，由于无法在栈底直接插入元素，所以我们先把栈中原来的元素都移到另一个栈里，然后在栈底插入新元素就相当于在队尾插入了元素。要在队首删除元素则直接弹出栈顶元素即可。

### 代码

```java
class CQueue {
    Stack<Integer> s1;
    Stack<Integer> s2;
    int size;
    
    public CQueue() {
        s1=new Stack<>();
        s2=new Stack<>();
        size=0;
    }
    
    public void appendTail(int value) {
        while(!s1.empty()){
            s2.push(s1.pop());
        }
        s1.push(value);
        while(!s2.empty()){
            s1.push(s2.pop());
        }
        size++;
    }
    
    public int deleteHead() {
        if(size==0){
            return -1;
        }
        size--;
        return s1.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```