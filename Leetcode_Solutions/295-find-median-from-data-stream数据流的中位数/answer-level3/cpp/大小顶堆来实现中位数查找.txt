### 解题思路
保持大小顶堆的平衡，大小差不超过1

### 代码

```cpp
class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num)
    {
        if (((greaterHeap.size() + lessHeap.size()) & 1) == 0) {
            if (greaterHeap.size() > 0 && greaterHeap.top() > num) {
                greaterHeap.push(num);
                num = greaterHeap.top();
                greaterHeap.pop();
            }
            lessHeap.push(num);
        } else {
            if (lessHeap.size() > 0 && lessHeap.top() < num) {
                lessHeap.push(num);
                num = lessHeap.top();
                lessHeap.pop();
            }
            greaterHeap.push(num);
        }
    }
    
    double findMedian()
    {
        if (lessHeap.size() == 0) {
            return 0;
        } else if (((lessHeap.size() + greaterHeap.size()) & 1) == 0) {
            return (lessHeap.top() + greaterHeap.top()) / 2.0;
        } else {
            return lessHeap.top();
        }
    }
private:
    priority_queue<int, vector<int>, less<int>> greaterHeap;
    priority_queue<int, vector<int>, greater<int>> lessHeap;
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```