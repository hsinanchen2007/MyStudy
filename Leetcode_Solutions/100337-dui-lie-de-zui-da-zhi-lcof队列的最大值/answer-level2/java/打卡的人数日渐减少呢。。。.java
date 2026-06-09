### 解题思路

运行时候那一个例子能过，但是全部样例的时候跑不过，看着密密麻麻的例子从里面找错误属实不易。题目描述也挺模糊的，函数和数组的那块输入我是半天都看不明白。或许这就是彩笔吧。

### 代码

```java
class MaxQueue {

    Queue<Integer> main;
    Deque<Integer> sort;

    public MaxQueue() {
        main=new LinkedList<Integer>();
        sort=new LinkedList<Integer>();
    }
    
    public int max_value() {
        if(sort.isEmpty()){
            return -1;
        }
        else{
            return sort.peek();
        }
    }
    
    public void push_back(int value) {
        main.offer(value);

        while(!sort.isEmpty()&&sort.peekLast()<value){
          sort.pollLast();
        }

        sort.offer(value);
    }
    
    public int pop_front() {
        if(main.isEmpty()){
            return -1;
        }
        int result=main.poll();
        if(result==sort.peek()){
            sort.poll();
        }
        return result;
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