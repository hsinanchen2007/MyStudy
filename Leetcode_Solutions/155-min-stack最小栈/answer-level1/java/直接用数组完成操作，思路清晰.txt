class MinStack {

    /** initialize your data structure here. */
    int cnt = 0;
    int arr[] = new int[10005];  
    int brr[] = new int[10005];
    public MinStack() {
        
    }
    
    public void push(int x) {
        if(cnt == 0 ){     //栈中无元素
            arr[cnt] = x;   
            brr[cnt] = x;
        }else{
            if(brr[cnt-1]  >= x){
                brr[cnt] = x;
            }else{
                brr[cnt] = brr[cnt-1];
            }
        }
        arr[cnt] = x;
        cnt ++;
    }
    
    public void pop() {
        cnt -- ;
    }
    
    public int top() {
        return arr[cnt-1];
    }
    
    public int getMin() {
        return brr[cnt-1];
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