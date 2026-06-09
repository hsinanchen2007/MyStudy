class MinStack {
    int arr[];
    int top;
    /** initialize your data structure here. */
    public MinStack(int x) {
        arr = new int [x];
        top = 0;
    }
     public MinStack() {
        arr = new int [5];
        top = 0;
    }
    
    public void push(int x) {
        if(top==arr.length){
                int[] kuo=arr;
                arr=new int[top*2];
                for (int i = 0; i < kuo.length; i++) {
                    arr[i]=kuo[i];
                }
            }
        arr[top++]=x;
    }
    
    public void pop() {
         --top;
    }
    
    public int top() {
        return arr[top-1];
    }
    
    public int getMin() {
        int a =arr[0];
        int value=a;
        for (int i = 1; i < top; i++) {
            if(value>arr[i]){
                value=arr[i];
            }
        }
        return value;
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