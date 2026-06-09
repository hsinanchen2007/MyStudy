![image.png](https://pic.leetcode-cn.com/8e32914b041decc5b68f463c02e55a0a606fa62a1f67b7e8ec3873ae96399258-image.png)


```
class MinStack {
    List<Integer> data;
    int min;
    /** initialize your data structure here. */
    public MinStack() {
        data = new ArrayList<>();
        min = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        if(min > x)
            min = x;
        data.add(x);
        
    }
    
    public void pop() {
        if(!data.isEmpty()){
            int top = data.size() - 1;
            
            if(data.get(top) == min){//更新最小值
                min = Integer.MAX_VALUE; 
                for(int i = 0; i < top ; i++){
                    if(data.get(i) < min)
                        min = data.get(i);
                }
            }
            data.remove(top);
            
        }
            
    }
    
    public int top() {
        if(!data.isEmpty())
            return data.get(data.size() - 1);
        else
            return -1;
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
