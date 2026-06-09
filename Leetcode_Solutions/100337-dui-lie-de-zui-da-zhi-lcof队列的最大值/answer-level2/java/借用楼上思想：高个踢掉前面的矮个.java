### 解题思路
借用前面高手评论内容：
思想很简单：矮个儿后有高个儿进来，那矮个儿永无出头之日，直接踢掉即可。

很明显，只记录一个最大值是不够的，因为一旦队首的最大值被删除，还需要找到新的最大值，这时再想找新的最大值，就绝对不是O(1)了。如果要实现O(1)，必须此时新的最大值已经存在某个位置了，我们直接取出来，才是O(1)
所以需要另外维护一个最大值 逐渐递减的队列。其实维护最大值队列不算是完全的O(1)，因为要和最大值队列从尾部开始的前面k(k<=n)个元素进行比较，所以复杂度又不到O(n)，但也算满足题目要求，因为题目要求是均摊O(1)。

最大值队列必须是双端队列，因为既要能从队尾正常的取出最大值，还要能从队尾把小个子清理出去，留位置给新来的高个子。

新元素来时：
1. 数据队列直接入队
2. 最大值队列：
新元素与队尾比较，若大于队尾，从队尾把队尾删掉，重复直到：队尾是更高个或者队空，然后新元素在队尾入队。


num  数据
q1   数据队列
q2   最大值队列
(1)  从最大值队列尾部删除1

1
() 1
1

1 2
(1) 2
2

1 2 7
(2) 7
7

1 2 7 4
7 4

1 2 7 4 6
7 (4) 6 从队尾踢掉4，再入队6
7 6

删除时，q1 == q2 则队首同时出队，否则，仅q1出队

### 代码

```java
class MaxQueue {

    public Deque<Integer> deq = null;//双端队列，链表结构，维护很多的最大值
    public Queue<Integer> que = null;//数据队列

    public MaxQueue() {
        deq = new LinkedList<Integer>();
        que = new LinkedList<Integer>();
    }
    
    public int max_value() {
        if(que == null || que.size()==0){
            return -1;
        }else{
            return (int)deq.peekFirst();  //最大值队列的队首
        }
    }
    
    public void push_back(int value) {
        que.add(Integer.valueOf(value));
        //最大值队列,is a 双端队列
        //思想：矮个儿后有高个儿进来，那矮个儿永无出头之日，直接踢掉即可。
        //value 若比队尾大，删除队尾（一直重复，直到value比队尾小），value 入队
        //总结起来，就是从队尾开始踢，把前面比我小的全踢掉。自己入队

        while(
            (deq.peekLast() != null) 
            && 
            ((int)deq.peekLast() < value)
        )
        {
            deq.pollLast();
        }
        deq.addLast(Integer.valueOf(value));

    }
    
    public int pop_front() {
        //两个队列 队首相同，就同时队首 出队
        //否则，仅需 数据队列出队
        if( que.peek()!=null && deq.peekFirst()!=null){
            if((int)que.peek()==(int)deq.peekFirst()){
                deq.pollFirst();
            }
            return (int)que.poll();
        }else{
            return -1;
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