关键点：
* 维护一个最大堆和最小堆，使得size差距不超过1，且最大堆堆顶小于等于最小堆堆顶
* 获取中位数时，若两堆大小相同，则取两堆堆顶平均数，否则取size较大的那个堆的堆顶
* 更新时，把要添加的数字添加到较大的那个堆，然后弹出较大的堆的堆顶并加入另一个堆
* 容易证明上一条操作不会影响我们要维护的不变量
* Java的PriorityQueue默认是最小堆，这个要注意
* 获取时间复杂度O(1)，更新时间复杂度O(log(n)), 空间复杂度O(n)

```java
class MedianFinder {
    private PriorityQueue<Integer> minHeap, maxHeap;

    /** initialize your data structure here. */
    public MedianFinder() {
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>((a, b) -> b - a);
    }
    
    public void addNum(int num) {
        if (maxHeap.size() <= minHeap.size()) {
            minHeap.add(num);
            maxHeap.add(minHeap.remove());
        } else {
            maxHeap.add(num);
            minHeap.add(maxHeap.remove());
        }
    }
    
    public double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            if (minHeap.isEmpty()) return Double.NaN;
            else return (minHeap.peek() + maxHeap.peek()) / 2.0;
        } else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.peek();
        } else {
            return minHeap.peek();
        }
    }
}
```
