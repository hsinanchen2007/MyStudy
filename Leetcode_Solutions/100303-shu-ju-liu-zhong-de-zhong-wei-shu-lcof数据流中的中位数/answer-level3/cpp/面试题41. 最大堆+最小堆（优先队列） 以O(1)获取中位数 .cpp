优先队列，top()获得队列头（堆顶）
```cpp
class MedianFinder {

private:
    priority_queue<int> maxHeap;                              // 大顶堆
    priority_queue<int, vector<int>, greater<int>> minHeap;   // 小顶堆

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
   
    void addNum(int num) {
        int size = minHeap.size() + maxHeap.size();
        if (size % 2 == 0) {   // size 为偶数时，始终push进最小堆
            minHeap.push(num);
            if (!maxHeap.empty() && maxHeap.top() > minHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                minHeap.pop();  
            }
        }
        else {   // size 为奇数时，始终push进最大堆，保证始终与最小堆的size相差不超过1
            maxHeap.push(num);
            if (maxHeap.top() > minHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                minHeap.pop();  
            }
        }
    }
    
    double findMedian() {
        int size = maxHeap.size() + minHeap.size();
        if (size % 2 == 0) 
            return (minHeap.top() + maxHeap.top()) / 2.0;
        else 
            return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```