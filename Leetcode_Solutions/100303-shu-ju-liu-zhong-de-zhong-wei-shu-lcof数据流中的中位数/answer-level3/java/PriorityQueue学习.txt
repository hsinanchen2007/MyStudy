### 解题思路


### 代码

```java
class MedianFinder {
    PriorityQueue<Integer> maxQueue = new PriorityQueue<>((o1, o2) -> o2-o1);
    PriorityQueue<Integer> minQueue = new PriorityQueue<>();
    int count = 0;
    /** initialize your data structure here. */
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        count ++;
        maxQueue.add(num);
        minQueue.add(maxQueue.poll());
        if((count & 1) != 0)
            maxQueue.add(minQueue.poll());
        
    }
    
    public double findMedian() {
        if((count & 1) == 0){
            return (double)(maxQueue.peek() + minQueue.peek()) / 2;
        }else {
            return (double) maxQueue.peek();
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```