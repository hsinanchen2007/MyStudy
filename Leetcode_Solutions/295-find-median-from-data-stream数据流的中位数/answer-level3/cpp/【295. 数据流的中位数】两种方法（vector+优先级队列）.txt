## 思路一：vector模拟堆
设置两个堆，一个为大顶堆，一个为小顶堆，大顶堆用于小于中位数的数，小顶堆用于保存大于中位数的数。
**添加数据：**
- 当数据总数为偶数时，将数据加入小顶堆中。如果添加的数小于大顶堆堆顶元素时，需要先将该数加入大顶堆，然后从大顶堆中弹出堆顶元素再放入小顶堆中。
- 当数据总数为奇数时，将数据加入大顶堆中。如果添加的数大于小顶堆堆顶元素时，需要先将该数加入小顶堆，然后从小顶堆中弹出堆顶元素再放入大顶堆中。

**取中位数：**
- 如果数据总数为偶数，则中位数为大顶堆和小顶堆堆顶元素除以2。
- 如果数据总数为奇数，则中位数为小顶堆堆顶元素。

### 代码
```c++
class MedianFinder {
    vector<int> min;
    vector<int> max;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //总数为偶数，放入小顶堆，即右侧
        if ((max.size() + min.size()) % 2 == 0) {
            if (max.size() > 0 && num < max[0]) {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }    
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        } else {//总数为奇数，放入大顶堆，即左侧
            if (min.size() > 0 && num > min[0]) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
        
    }
    
    double findMedian() {
        double mid = 0;
        if ((max.size() + min.size()) % 2 == 0) {
            mid =  (max[0] + min[0]) / 2.0;
        } else {
            mid = min[0];
        }
        return mid;
    }
};
```

## 思路二：利用优先级队列
利用优先级队列实现自动排序。
**添加元素**
数据优先放入大顶堆中，然后将大顶堆堆顶元素放入小顶堆中。为了维持大顶堆元素数量不小于小顶堆元素数量（即大顶堆元素数量要么和小顶堆元素数量相等，要么多一个元素），如果大顶堆元素数量小于小顶堆元素数量，则从小顶堆中弹出一个元素放入大顶堆中。
**取中位数**
如果数据总量为奇数，则中位数为大顶堆堆顶元素，否则为大顶堆和小顶堆元素和除以2。
### 代码
```c++
class MedianFinder {
    priority_queue<int> max;    
    priority_queue<int, vector<int>, greater<int>> min;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max.push(num);
        min.push(max.top());
        max.pop();
        if (max.size() < min.size()) {
            max.push(min.top());
            min.pop();
        }        
    }
    
    double findMedian() {
        int size = max.size() + min.size();
        return size % 2 == 1 ? max.top() : (max.top() + min.top()) / 2.0;
    }
};
```
