### 解题思路
简洁明了，无需其他的辅助栈
直接在栈当中来进行这个排序得到最小值的指针就OK了

### 代码

```java
class MinStack {
   private int maxSize;        //这个是代表这个是一个最大的长度。
    private int top;            //这个是代表这个top的指针
    private int minIndex;       //这个是最小值的一个索引
    private int[] values;       //元素的数组



    /** initialize your data structure here. */
    public MinStack() {
        maxSize = 1000;
        values = new int[maxSize];
        top = -1;
        minIndex = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        if(top == maxSize-1){
            return;
        }
        top++;
        values[top]=x;
    }
    
    public void pop() {
        if(top==-1){
            return;
        }
        top--;

    }
    
    public int top() {

        return values[top];
    }
    
    public int getMin() {
        if(top == -1){
            return Integer.MIN_VALUE;
        }

        minIndex = 0;
        for(int i=1;i<=top;i++){
            if(values[minIndex]>values[i]){
                minIndex=i;
            }
        }
        return values[minIndex];
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