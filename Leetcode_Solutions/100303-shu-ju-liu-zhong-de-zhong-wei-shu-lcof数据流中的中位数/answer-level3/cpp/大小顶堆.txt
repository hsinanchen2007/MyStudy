### 解题思路
若当前已插入偶数个数据，则将待插入数据先插入到大顶堆，然后将大顶堆的顶部数据插入到小顶堆，大顶堆pop；
若当前已插入奇数个数据，则将待插入数据先插入到小顶堆，然后将小顶堆的顶部数据插入到大顶堆，小顶堆pop；
最后返回中位数时，若当前已插入偶数个数据，则中位数为(double)(大顶堆的顶部+小顶堆的顶部)/2；若当前已插入奇数个数据，则中位数为小顶堆的顶部。

### 代码

```cpp
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(c % 2 == 0)
        {
            //已插入偶数个数据
            //那就先将num插入到大顶堆，然后将大顶堆的最大值放到小顶堆
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else
        {
            //已插入奇数个数据
            //那就先将num插入到小顶堆，然后将小顶堆的最小值放到大顶堆
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        ++c;
    }
    
    double findMedian() {
        if(c % 2 == 0)
            return (static_cast<double>(maxHeap.top() + minHeap.top()))/2;  //注意转换成double
        return minHeap.top();  //若已插入奇数个数据，则中位数在小顶堆顶部
    }
    priority_queue<int, vector<int>, greater<int>> minHeap;  //小顶堆
    priority_queue<int, vector<int>, less<int>> maxHeap;  //大顶堆
    int c = 0;  //记录已插入的数据量
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```