### 解题思路

```
用一个双端队列实现啦

### 代码

```java
class MaxQueue {
    
    Queue<Integer> queue;
    //双端队列用于保存最大元素;
    Deque<Integer> deque;

    public MaxQueue() {
        queue = new LinkedList<>();
        deque = new ArrayDeque<>();
        
    }
    
    public int max_value() {
        if(queue.isEmpty()){
            while (!deque.isEmpty()){
                deque.poll();
            }
            return -1;
        }else{
            return deque.getFirst();
        }
    }

    public void push_back(int value) {
        queue.offer(value);
        //保存当前最大元素移出queue后，下一个最大元素
        while (!deque.isEmpty() && value > deque.getLast()){
            deque.removeLast();
        }
        deque.offer(value);
    }
    
    public int pop_front() {
        if (queue.isEmpty()){
            while (!deque.isEmpty()){
                deque.poll();
            }
            return -1;
        }
        int o = queue.poll();
        if (o == deque.getFirst()){
            deque.removeFirst();
        }
        return o;
    }
}
```