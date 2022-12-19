### 解题思路
思想：用两个双端队列，numList保存正常的数据；maxList一个保存当前队列中的最大值；
取最大值时：直接返回maxList的队首位置；
添加时：numList正常添加，maxList用滑动窗口思想，只保存有可能成为最大值的元素
pop时，numList正常pollFirst(),如果numList.pollFirst()的元素等于maxList的队首元素，则maxList也执行pollFirst();

### 代码

```java
class MaxQueue {
    LinkedList<Integer> numList;
    LinkedList<Integer> maxList;
    public MaxQueue() {
        numList=new LinkedList<>();
        maxList=new LinkedList<>();
    }
    
    public int max_value() {
        if(!maxList.isEmpty()) return maxList.peekFirst();//返回队首位置
        else return -1;
    }
    
    public void push_back(int value) {
        while(!maxList.isEmpty()&&value>maxList.peekLast()) maxList.pollLast();
        maxList.add(value);//只添加有可能成为最大值得元素
        numList.add(value);//numList正常添加
    }
    
    public int pop_front() {
        int temp=-1;
        if(!numList.isEmpty())  temp=numList.pollFirst();//numList正常出队
        if(!maxList.isEmpty()&&maxList.peekFirst()==temp) maxList.pollFirst();//如果出队元素等于maxList的队首元素，则maxList也出队；
        return temp;
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