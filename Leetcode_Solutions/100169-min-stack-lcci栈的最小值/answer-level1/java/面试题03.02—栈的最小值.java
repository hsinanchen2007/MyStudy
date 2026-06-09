### 解题思路


### 代码

```java
class MinStack {
    int min;
    int top;
    int[] stack;
    /** initialize your data structure here. */
    public MinStack() {
        stack= new int[10000];
        top=-1;
    }
    private boolean isEmpty(){
        if(top==-1){return true;}
        else return false;
    }
    public void push(int x) {
        if(isEmpty()){min=x;}
        else if(x<min){
            min=x;
        }
        top++;
        stack[top]=x;
    }
    
    public void pop() {
 if(!isEmpty()){
     top--;
     if(min==stack[top+1]){
         int temp=stack[0];
         for(int i=1;i<=top;i++){
             if(stack[i]<temp)  temp=stack[i];
         }
         min=temp;

     }
 }
    }
    
    public int top() {
return stack[top];
    }
    
    public int getMin() {
return min;
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