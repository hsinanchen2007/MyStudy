### 解题思路
push,pop操作时自动更新Min,lalalall

### 代码

```java
class MinStack {
    private int[] Ele;
    private int length;
    private int real;
    private int Min;
    /** initialize your data structure here. */
    public MinStack() {
        this.real=1024;
        this.Ele=new int[this.real];
        this.length=0;
        this.Min=0;
    }
    
    public void push(int x) {
        int[] tmp=Ele;
        if(length==0)
            Min=x;
        if(length+1==real){
            Ele=new int[real*2];
            real*=2;
            System.arraycopy(Ele,0,tmp,0,real/2);
        }
        Ele[length]=x;
        length++;
        if(x<Min)
            Min=x;
    }
    
    public void pop() {
        length--;
        if(Ele[length]==Min){
            Min=Ele[0];
            for(int i=1;i<length;i++){
                if(Ele[i]<Min)
                    Min=Ele[i];
            }
        }
    }
    
    public int top() {
        return Ele[length-1];
    }
    
    public int getMin() {
        return Min;
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