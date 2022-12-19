### 解题思路
此处撰写解题思路

### 代码

```java
class MaxQueue {
    Queue<Integer> queue1;
    Deque<Integer> queue2;

    public MaxQueue() {
        queue1=new LinkedList<>();
        queue2=new LinkedList<>();
    }
    
    public int max_value() {
        if(queue2.isEmpty()){
            return -1;
        }
        return queue2.peek();
    }

    public void push_back(int value) {
        queue1.add(value);
        if(queue1.isEmpty()){
            queue2.add(value);
        }
        else{
            int count=0;
            while(!queue2.isEmpty() && value>queue2.getLast()){
                queue2.pollLast();
                count++;
            }
            while(count>=0){
                queue2.add(value);
                count--;
            }
        }

    }

    public int pop_front() {
        if(queue1.isEmpty()){
            return -1;
        }
        else {
            queue2.poll();
            return queue1.poll();
        }
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