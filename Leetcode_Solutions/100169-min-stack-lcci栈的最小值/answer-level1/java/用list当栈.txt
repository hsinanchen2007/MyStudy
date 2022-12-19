### 解题思路


### 代码

```java
class MinStack {

    //长度可变栈
    private ArrayList<Integer> stack;
    //栈指针
    private int stackInx;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new ArrayList<>();
        stackInx = 0;
    }
    
    public void push(int x) {
        stack.add(x);
        stackInx++;
    }
    
    public void pop() {
        if(stackInx == stack.size() && stack.size() != 0) {
            stack.remove((int)--stackInx);
        }
    }
    
    public int top() {
        if(stackInx == stack.size() && stack.size() != 0) {
            return stack.get(stackInx - 1);
        }
        return -1;
    }
    
    public int getMin() {
        if(stack.size() == 0)  return -1; 
        ArrayList<Integer> tem = (ArrayList<Integer>)stack.clone();
        Collections.sort(tem);
        return tem.get(0);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```