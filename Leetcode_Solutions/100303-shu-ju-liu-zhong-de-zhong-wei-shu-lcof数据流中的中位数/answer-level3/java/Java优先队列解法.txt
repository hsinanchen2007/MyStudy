```Java
    private PriorityQueue<Integer> minHeap;  // 小根堆
    private PriorityQueue<Integer> maxHeap;  // 大根堆
    private int count;
    /** initialize your data structure here. */
    public MedianFinder() {
        minHeap = new PriorityQueue();
        maxHeap = new PriorityQueue(Collections.reverseOrder());
        count = 0;
    }
    public void addNum(Integer num) {
        if ((count & 1 ) == 1) { // 奇数，新数据插入最大堆（左侧）
            // 新数据和最小堆的最小数字对比，比它大；最小堆的最小值插入最大堆，新数据插到最小堆
            minHeap.add(num);
            maxHeap.add(minHeap.poll());
        } else { // 偶数，新数据插入最小堆（右侧）
            // 新数据和最大堆的最大数字对比，比它小；最大堆的最大值插入最小堆，新数据插到最大堆
            maxHeap.add(num);
            minHeap.add(maxHeap.poll());
        }
        count++;
    }
    // 注意数目不同时，中位数如何去求？
    public double findMedian() {
        double result;
        if((count & 1) == 1)
            result = Double.valueOf(minHeap.peek());
        else
            result = (minHeap.peek()+maxHeap.peek())/2.0;
        return result;
    }
```