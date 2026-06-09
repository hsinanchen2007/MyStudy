### 解题思路
此处撰写解题思路

### 代码

```java
class MyStack {

    List<Integer> list = new ArrayList<Integer>();
    //创建list
    
    /** Initialize your data structure here. */
    public MyStack() {

    }
    
    /** Push element x onto stack. */
    public void push(int x) {

        list.add(x);
        // 添加元素
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        //分两种情况，一种是list不为空的时候，就找最后一个元素，如果为空就返回-1
        if(!list.isEmpty()){
            //先找到list里面的最后一个元素，其index是list.size()-1
            int lastElement = list.get(list.size() - 1);
            //调用remove函数，移除最后一个元素
            list.remove(list.size() - 1);
            return lastElement;
        }
        else
            return -1;
    }
    
    /** Get the top element. */
    public int top() {
        return list.get(list.size() - 1);
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {

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