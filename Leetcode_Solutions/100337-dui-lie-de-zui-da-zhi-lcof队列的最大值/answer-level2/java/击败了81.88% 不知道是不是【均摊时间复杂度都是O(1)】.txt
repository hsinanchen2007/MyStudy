### 解题思路
需要两个队列：
1. 数据队列，用来储存数据
2. 最大值队列，用来储存最大值

最大值队列的操作：
- push一个新数时，从前向后依次比较最大值队列中的既存数，如果大于其中某一个，将其替换，并删去之后的所有数
- 如果都不大于既存的数字，则把新数加入队尾

- pop一个数时，比较是否与最大值队列的队首数相同，如果相同，则一并删去
- 如果不同，则对最大值队列不进行操作

- 按照以上规则操作，最大值队列将按从大到小的顺序排列，其中队首为数据队列的最大值，求max时直接返回队首数即可

⚠️注意：在删除队尾的时候list的size是会随着删除而变化的

### 代码

```java
class MaxQueue {
    
    Queue<Integer> queue;
    List<Integer> list;

    public MaxQueue() {
        queue = new LinkedList<>();
        list = new ArrayList<>();
    }
    
    public int max_value() {
        if(queue.isEmpty()) {
            return -1;
        }
        return list.get(0);
    }
    
    public void push_back(int value) {
        queue.add(value);
        for(int i=0; i<list.size(); i++) {
            if(value > list.get(i)) {
                list.set(i, value);
                //remove until tail
                int len = list.size();
                for(int j=i+1; j<len; j++) {
                    list.remove(i+1);
                }
                return;
            }
        }
        list.add(value);
    }
    
    public int pop_front() {
        if(queue.isEmpty()) {
            return -1;
        }
        int val = queue.remove();
        if(val == list.get(0)) {
            list.remove(0);
        }
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