### 解题思路
使用List及其已有方法实现栈
   
### 代码

```java
class MyStack {

    List<Integer> list = new ArrayList<Integer>();
    /** Initialize your data structure here. */
    public MyStack() {
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
       list.add(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int num = list.get(list.size() - 1);
        list.remove(list.size() - 1);
        return num;
    }
    
    /** Get the top element. */
    public int top() {
       int num = list.get(list.size() - 1);
       return num;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
       //return list.size() == 0;
        return list.isEmpty();
    }

}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
```