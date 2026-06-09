### 解题思路
此处撰写解题思路
我的思路:
    用两个栈来解决的
    将添加的值放入到第一个栈中，一定要判断第二个栈是否为空，
如果为空的时候，再第一个栈中的元素压入到第二个栈中，如果不为空的话
直接返回第二个栈中的元素，查看栈顶的元素其实也是查看第二个栈中的
第一个元素用栈自带的peek()就可以返回当前栈顶的元素！
最后是判断栈中是否为空，为空就true,不为空就false,这个就要两个栈其中
一个不为空那就不能为空，必须是两个栈同时为空才可以为true.
### 代码

```java
import java.util.Stack;
class MyQueue {
    public int val;
    Stack<Integer> s1=new Stack<Integer>();
    Stack<Integer> s2=new Stack<Integer>();
    /** Initialize your data structure here. */
    public MyQueue() {
        val=0;
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(s2.empty()){
            while(!s1.empty()){
              s2.push(s1.pop());
            }
        }
        int value=s2.pop();
        return value;
    }
    
    /** Get the front element. */
    public int peek() {
        if(s2.empty()){
            while(!s1.empty()){
              s2.push(s1.pop());
            }
        }
        int value=s2.peek();
        return value;
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        if(!s2.empty() || !s1.empty()){
            return false;
        }
        return true;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
```