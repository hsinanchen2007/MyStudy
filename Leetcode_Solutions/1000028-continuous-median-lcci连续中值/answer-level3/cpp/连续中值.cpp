### 解题思路
利用最大最小堆分半维护整个数字list，去中位数就跟取最大最小堆的堆顶有关了，注意要保证最大堆顶值小于最小堆顶值且两个堆size差距不超过1.

### 代码

```cpp
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> max_heap;//优先降序队列，即最大堆
    priority_queue<int, vector<int>, greater<int>> min_heap;//优先升序队列，即最小堆
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (max_heap.empty() || max_heap.top() > num) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        if (max_heap.size() - min_heap.size() == 2) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if (min_heap.size() - max_heap.size() == 2) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
    }
    
    double findMedian() {
        if (max_heap.empty() && min_heap.empty()) {
            return 0.0;
        }
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
        return max_heap.size() > min_heap.size() ? double(max_heap.top()) : double(min_heap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```