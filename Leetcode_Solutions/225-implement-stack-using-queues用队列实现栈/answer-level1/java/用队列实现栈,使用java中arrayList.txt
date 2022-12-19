### 解题思路
此处撰写解题思路
1.使用ArrayList作为存储结构
2.使用pos作为栈顶元素标识
3.入Push,加入list,pos++,如果是第一个元素pos=0
4.pop弹出栈顶元素，记录pos所在位置的值，删除这个值，pos--返回值
5.top 弹出pos所在位置值
6.empty列表中没有元素

### 代码

```java
class MyStack {
 private List<Integer> stack;
    private volatile  int pos;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {
       stack=new ArrayList<>();
       pos=0;
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {

        stack.add(x); pos++;
        if(stack.size()==1){
            pos=0;
        }
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {

      int a =stack.get(pos);
      stack.remove(pos);
      pos--;
      return a;
    }

    /**
     * Get the top element.
     */
    public int top() {

        return stack.get(pos);
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return stack.size()==0;
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