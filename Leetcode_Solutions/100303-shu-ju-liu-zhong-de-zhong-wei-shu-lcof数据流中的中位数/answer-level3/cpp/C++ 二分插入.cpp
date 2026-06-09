### 解题思路
插入的时候用二分插入排序。取出的时候可以O(1).

### 代码

```cpp
class MedianFinder {
private:
    vector<int> vec;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (vec.size() == 0) {
            vec.emplace_back(num);
            return;
        }
        auto index = lower_bound(vec.begin(), vec.end(), num);
        vec.insert(index, num);
    }
    
    double findMedian() {
        long size = vec.size();
        if (size%2 == 0) {
            return ((double)(vec[size/2] + vec[size/2-1]))/2;
        } else {
            return vec[size/2];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```