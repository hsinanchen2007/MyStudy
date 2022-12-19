执行结果：
通过
显示详情
执行用时 :
107 ms
, 在所有 Java 提交中击败了
53.13%
的用户
内存消耗 :
44.9 MB
, 在所有 Java 提交中击败了
52.78%
的用户
```
class MinStack {
    Stack<Integer> st = new Stack<Integer>();
    Stack<Integer> st2 = new Stack<Integer>();
    /** initialize your data structure here. */
    public MinStack() {
        
    }
    
    public void push(int x) {
        st.push(x);
        if(st2.isEmpty()||x<=st2.peek()){
            st2.push(x);
        }
    }
    
    public void pop() {
        int x = st.pop();
        if(!st2.isEmpty()&&st2.peek()==x)st2.pop();
        
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        if(!st2.isEmpty()){
            return st2.peek();
        }else if(!st.isEmpty()){
            return st.peek();
        }else{
            return 0;
        }
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
