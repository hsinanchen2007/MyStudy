### 解题思路
假设要添加的元素分别为：5 3 2 4
1. queue：5 ; deque：5
2. queue：5 3 ; deque：5 3
3. queue：5 3 2; deque：5 3 2
4. queue：5 3 2 4; deque：5 4
当添加的元素小于deque队尾元素时，把该元素同时添加至queue和deque
当添加的元素大于deque队尾元素时，以此从deque队尾取出元素，直至deque的队尾元素大于待添加的元素

### 代码

```java
class MaxQueue {

    public Deque<Integer> deque;//双端队列
    public Queue<Integer> queue;//队列

    public MaxQueue() {
        deque = new LinkedList<Integer>();//单调队列
        queue = new LinkedList<Integer>();//双端队列
    }
    
    public int max_value() {
        if(deque.size() == 0){            
            return -1;
        }

        return deque.peekFirst();
    }
    
    public void push_back(int value) {
        queue.offer(value);
        
        while(deque.size() > 0){
            if(deque.getLast() < value){
                deque.removeLast();
            }else if(deque.getLast() > value){
                deque.offerLast(value);
            }else{
                return;
            }
        }
       
        if(deque.size() == 0){
            deque.offer(value);
        }
    }
    
    public int pop_front() {
        if(queue.size() == 0){           
            return -1;
        }

        **//这里是大坑**
        **//我们的队列是Integer对象类型，添加进去和取出来的元素本质上都是Object**
        **//他们的引用可能不相等，因此要用intValue()函数手动拆箱，比较值，而不是引用的地址**
        if(queue.peek().*intValue*() == deque.peekFirst().*intValue*()){
            deque.poll(); 
        }
        return queue.poll();    
    }
}
```