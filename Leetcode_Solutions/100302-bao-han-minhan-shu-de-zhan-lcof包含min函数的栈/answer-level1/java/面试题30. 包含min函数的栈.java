### 解题思路
借助链表。进出栈都判断是否为最小值。

### 代码

```java
class MinStack {
    List<Integer> list;
    int rear;
    int MinValue;
    /** initialize your data structure here. */
    public MinStack() {
        list=new ArrayList<>();
        rear=-1;
    }
    
    public void push(int x) {
        if(rear==-1)MinValue=x;
        else{
            if(MinValue>x)MinValue=x;
        }
        list.add(x);
        rear++;
    }
    
    public void pop() {
        if(rear!=-1){
        	int n=list.remove(rear);
            rear--;
            int i=0;
            if(rear!=-1)if(n==MinValue)MinValue=list.get(0);
            while(i<=rear) {	
            	if(MinValue>=list.get(i))MinValue=list.get(i);
            	i++;
            } 
        }
    }
    
    public int top() {
        return list.get(rear);
    }
    
    public int min() {
        return MinValue;
    }
}
```