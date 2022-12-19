```
class MinStack {

    Stack<Integer> stack1;
    Stack<Integer> stack2;
    /** initialize your data structure here. */
    public MinStack() {
        stack1=new Stack<Integer>();
        stack2=new Stack<Integer>();
    }
    
    public void push(int x) {
       stack1.push(x);
       if(stack2.isEmpty()){
           stack2.push(x);
       }else if(stack2.peek()<x){
           stack2.push(stack2.peek());
       }else{
           stack2.push(x);
       }
    }
    
    public void pop() {
        stack1.pop();
        stack2.pop();
    }
    
    public int top() {
        return stack1.peek();
    }
    
    public int getMin() {
        
    return stack2.peek();
    }
}
```
例子：
stack1:-3，-2，-5，-4,0
stack2:-3，-3，-5，-5，-5
