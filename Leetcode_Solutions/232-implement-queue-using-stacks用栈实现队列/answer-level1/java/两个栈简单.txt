### 解题思路
此处撰写解题思路
一个栈保存倒序后的数，一个栈作为一个中转站，暂时储存上一个栈的数据，然后将要push进的数据加入到上一个栈之后，将暂时保存元素的那个栈中的元素全部放回到当前栈中。只要搞懂这个其他的就容易理解了。
一句话就是，将原本应该入栈的元素的存储顺序倒置。
### 代码

```java
class MyQueue {
    private Stack<Integer> st;
    /** Initialize your data structure here. */
    public MyQueue() {
        st=new Stack<Integer>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        Stack<Integer> temp=new Stack();
        while(!st.isEmpty()){
            temp.push(st.pop());
        }
        st.push(x);
        while(!temp.isEmpty()){
            st.push(temp.pop());
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return st.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        return st.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return st.isEmpty();
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