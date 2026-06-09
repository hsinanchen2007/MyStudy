### 解题思路
1、首先看题目条件,三个O(1);遍历求最大值的方式排除，结合题目可以联想到辅助队列和单调栈相关的结构来保存最大值。
2、接下来考虑数字进出的问题，我是拿了4，3，2，1，这个数字进行了一遍模拟，然后思考，什么时候max队列里面应该留下怎样的值才能O(1)，然后得出进出方式


### 代码

```java
class MaxQueue {
    LinkedList<Integer> queue;
    LinkedList<Integer> max;
    public MaxQueue() {
        queue = new LinkedList<>();
        max = new LinkedList<>();
    }
    
    public int max_value() {
        if(queue.size()==0) return -1;
        return max.peekFirst();
    }
    
    public void push_back(int value) {
        queue.add(value);
        if(max.size()==0||value<=max.peekLast()){
            max.add(value);
            return;
        } 
        while(max.size()!=0&&value>max.peekLast()){
            max.pollLast();
        }
        max.add(value);
    }
    
    public int pop_front() {
        if(queue.size()==0) return -1;
        int val = queue.pollFirst();
        if(val==max.peekFirst()) max.pollFirst();
        return val;
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