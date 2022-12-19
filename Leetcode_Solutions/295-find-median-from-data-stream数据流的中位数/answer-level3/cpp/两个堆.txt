### 解题思路
动态维护一个最大堆和一个最小堆，最大堆存储一半数据，最小堆存储一般数据，维持最大堆的堆顶比最小堆的堆顶小即可。

### 代码

```cpp
class MedianFinder {
private:
    priority_queue<int> Max_heap;
    std::priority_queue<int, vector<int>, greater<int> > Min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int max_size = Max_heap.size();
        int min_size = Min_heap.size();
        if(max_size==0)
        {
            Max_heap.push(num);
            return;
        }
        //若最大堆和最小堆元素个数相同
        if (max_size == min_size) {
            if (num > Max_heap.top()) {
                //要添加的元素比最大堆的堆顶大，则加入最小堆
                Min_heap.push(num);
            } else {
                Max_heap.push(num);
            }

        } else if (max_size > min_size) {
            //最大堆元素个数比最小堆大
            if (num < Max_heap.top()) {
                //要添加的元素比最大堆顶小，将最大堆顶加入最小堆，该元素加入最大堆
                Min_heap.push(Max_heap.top());
                Max_heap.pop();
                Max_heap.push(num);                
            } else {
                //直接将元素加入最小堆
                Min_heap.push(num);
            }
        } else {
            if (num > Min_heap.top()) {
                Max_heap.push(Min_heap.top());
                Min_heap.pop();
                Min_heap.push(num);
            } else {
                Max_heap.push(num);
            }
        }        
    }
    
    double findMedian() {
        int max_size = Max_heap.size();
        int min_size = Min_heap.size();
        double res;
        if (max_size == min_size) {
            res = ((double)(Max_heap.top())+(double)(Min_heap.top()))/2;
            
        } else {
            if (max_size > min_size) {
                res = Max_heap.top();
            } else {
                res = Min_heap.top();
            }
        }
        return res;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```