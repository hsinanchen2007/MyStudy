### 解题思路
本题思考了很久也没想到怎么写，后来看别人的解析，构造一个对象，于是问题引刃而解。
构造一个内部数据对象InternalData
```java
private class InternalData{
	int index;
    int number;
    public InternalData(int index, int number){
		this.index = index;
		this.number = number;
	}
}
```
这样就可以保存对应数的index。方便进行用上一题所提到的方法进行处理。

定义两个数据结构，一个用于存储队列里的数，另一个作为最大队列存储（该队列的头部存储着当前队列中的最大的数）。
定义index，记录每一个加进来的数的索引，在每一次push_back的时候加1.
push_back的时候，首先将对应的data存到dataQueue中。
	紧接着判断与maxQueue的关系。
	如果maxQueue不为空，且maxQueue的最后一个元素的值小于当前push进来的值，那么就把maxQueue最后的值弹出。直到满足条件位置。
	最后将这个数加到maxQueue中。index++
	
pop_front的时候，首先判空，不为空则pop出来
	处理maxQueue,
	如果当maxQueue中的第一个不是pop出来的值，则没事，
	如果是，那么就要把maxQueue的第一个值也一并pop出来。
	最后返回pop出来的值。
max_value就是maxQueue中第一个元素对应的值。

### 代码

```java
class MaxQueue {

    private ArrayDeque<InternalData> dataQueue = new ArrayDeque<>();
    private ArrayDeque<InternalData> maxQueue = new ArrayDeque<>();
    private int index = 0;

    private class InternalData{
        int index;
        int number;
        public InternalData(int index, int number){
            this.index = index;
            this.number = number;
        }
    }

    public MaxQueue() {
        
    }
    
    public int max_value() {
        if(maxQueue.isEmpty()){
            return -1;
        }else{
            return maxQueue.peekFirst().number;
        }
    }
    
    public void push_back(int value) {
        InternalData data = new InternalData(index, value);
        dataQueue.addLast(data);

        while(!maxQueue.isEmpty() && maxQueue.peekLast().number<value){
            maxQueue.pollLast();
        }
        maxQueue.addLast(data);
        index++;
    }
    
    public int pop_front() {
        if(dataQueue.isEmpty()){
            return -1;
        }
        InternalData data = dataQueue.pollFirst();
        if(data.index == maxQueue.peekFirst().index){
            maxQueue.pollFirst();
        } 
        return data.number;
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