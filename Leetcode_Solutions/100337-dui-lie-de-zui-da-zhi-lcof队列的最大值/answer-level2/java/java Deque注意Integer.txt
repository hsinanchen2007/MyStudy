### 解题思路
Integer有缓存池，自动装箱时-128~127使用同一个对象，同时重写了equals方法，比较的是intVal。
所以下面在压入弹出比较时，避免自动装拆箱

### 代码

```java
class MaxQueue {

    private Deque<Integer> numQ=new LinkedList();
    private Deque<Integer> maxQ=new LinkedList();

    public MaxQueue() {

    }
    
    public int max_value() {
        if(maxQ.size()==0) return -1;
        return maxQ.peekFirst();
    }
    
    public void push_back(int value) {
        Integer in=new Integer(value);//这里直接new,避免装箱不用缓存池
        numQ.add(in);
        if(maxQ.size()==0) maxQ.add(in);
        else{
            while(maxQ.size()>0&&maxQ.peekLast()<value) //实际上这里是<，不是<=，使用装拆箱也是可以的，只是首先想起、注意到了这个知识点
                maxQ.pollLast();
            maxQ.add(in);
        }
    }
    
    public int pop_front() {
        if(numQ.size()==0) return -1;
        Integer out=numQ.poll();
        if(out==maxQ.peekFirst()) //因此这里可以用==比较，
            maxQ.pollFirst();
        return out;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
```