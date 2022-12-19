### 题目图解
![001.png](https://pic.leetcode-cn.com/0f209f9896005c27ca33e3784d0f5bfe8b7a339a20eeebf923624d4d5ab439ba-001.png)

### 题解
- 创建两个堆，一个大顶堆，一个小顶堆
	- 大顶堆 `PriorityQueue<Integer> maxQueue = new PriorityQueue<>(Collections.reverseOrder());`
	- 小顶堆 `PriorityQueue<Integer> minQueue = new PriorityQueue<>();`

- 如果是偶数，选取两个堆的对顶除以二
- 如果奇数，我们规定用大顶堆存放
- 数据每一次从大顶堆涌入，大顶堆变大把最大值在次涌入小顶堆，保持新的中值在两个堆之间
- 但是第一次放入数据，会导致数据只在小顶堆，这样就产生了两个堆的大小不平衡
- 看以看出最多大顶堆大于小顶堆1，所以如果小顶堆大于大顶堆
- 小顶堆反涌回大顶堆一次，以保持二堆平衡

### 代码
```
class MedianFinder {

/** initialize your data structure here. */
PriorityQueue<Integer> maxQueue,minQueue;
public MedianFinder() {
    maxQueue = new PriorityQueue<>(Collections.reverseOrder());
    minQueue = new PriorityQueue<>();
}

public void addNum(int num) {
    maxQueue.add(num);
    minQueue.add(maxQueue.poll());
    if (minQueue.size()>maxQueue.size()){
        maxQueue.add((minQueue.poll()));
    }
}

public double findMedian() {
    if (maxQueue.size()==minQueue.size())
    {
        return (maxQueue.peek()+minQueue.peek()) *0.5;
    }
    return maxQueue.peek();
}
}
```
