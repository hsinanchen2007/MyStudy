### 解题思路
此处撰写解题思路

### 代码

```java
class MaxQueue {
    private ArrayList<Integer> queue;
    private int first;
    private int last;
    private int max;


    public MaxQueue() {
        queue = new ArrayList<>();
        first = 0;
        last = 0;
        max = 0;

    }
    
    int max_value() {
        if(first == last)
            return -1;
        else
            return max;

    }
    
    void push_back(int value) {
        queue.add(value);
        last++;
        if(value>max)
            max = value;

    }
    
    int pop_front() {
        if(first == last)
            return -1;
        else{
            int front = 0;
            //若队头是最大元素，则需要重新找最大值，记录为max
            if(max == queue.get(first)){
                max = 0;
                for(int i=first+1;i<last;i++){
                    if(queue.get(i)>max)
                        max = queue.get(i);

                }
            
            }
            front = queue.get(first);
            first++;
            return front;
        }
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```