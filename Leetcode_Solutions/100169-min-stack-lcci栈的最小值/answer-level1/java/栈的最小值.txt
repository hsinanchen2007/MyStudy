### 解题思路
借助两个列表分别存储数据和最小值

### 代码

```java
class MinStack {
    private int index=0;
    private List<Integer> nums=new ArrayList();
    private List<Integer> mins=new ArrayList();
    /** initialize your data structure here. */
    public MinStack() {

    }
    
    public void push(int x) {
        nums.add(x);
        if(index==0){
            mins.add(x);
        }else{
            mins.add(Math.min(x,mins.get(index-1)));
        }
        index++;
    }
    
    public void pop() {
        if(index<0){
            return;
        }
        index--;
        nums.remove(index);
        mins.remove(index);
    }
    
    public int top() {
        return nums.get(index-1);
    }
    
    public int getMin() {
        return mins.get(index-1);
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