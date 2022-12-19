```cpp
#include <queue>
using namespace std;
class MedianFinder {
private:
    priority_queue<int> pq_less; // 最大堆
    priority_queue<int, vector<int>, greater<int>> pq_more; // 最小堆
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        // 最小堆的size不超过最大堆
        // 最大堆的size大于最小堆
        if (pq_less.empty() || num <= pq_less.top())
            pq_less.push(num);
        else
            pq_more.push(num);
        if (pq_less.size() > pq_more.size() + 1) { // 不可以使用if (pq_less.size() - pq_more.size() > 1) 因为产生的无符号数非常大
            pq_more.push(pq_less.top());
            pq_less.pop();
        }
        if (pq_more.size() > pq_less.size()) {
            
            pq_less.push(pq_more.top());
            pq_more.pop();
        }

    }
    
    double findMedian() {
        int size = pq_less.size() + pq_more.size();
        //cout << size << endl;
        if (size % 2 == 1) 
            return pq_less.top();
        else
            return (pq_less.top() + pq_more.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```