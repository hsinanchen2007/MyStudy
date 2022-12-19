### 解题思路
此处撰写解题思路

### 代码

```java
class MedianFinder {
    
    Queue<Integer> max;
    Queue<Integer> min;
    int size;

    /** initialize your data structure here. */
    public MedianFinder() {
        max = new PriorityQueue<>((o1, o2) -> o2 - o1);
        min = new PriorityQueue<>();
        size = 0;
    }
    
    public void addNum(int num) {
        int k = size / 2 + 1;
        if(max.size() < k) {
            if(!min.isEmpty() && min.peek() < num) {
                max.add(min.poll());
                min.add(num);
            } else {
                max.add(num);
            }
        } else {
            if(num < max.peek()) {
                min.add(max.poll());
                max.add(num);
            } else {
                min.add(num);
            }
        }
        size++;
    }
    
    public double findMedian() {
        return (size & 1) == 1 ? max.peek() : (max.peek() + min.peek()) * 1.0 / 2;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```