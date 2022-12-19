```
class MedianFinder {
public:
    multiset<int> set;
    multiset<int>::iterator it;
    int size = 0;
    MedianFinder() {}
    
    void addNum(int num) {
        set.insert(num);
        size++;
        if (size == 1) it = set.begin();
        else if (num >= *it && size % 2 == 1) it++;
        else if (num < *it && size % 2 == 0) it--;
    }
    
    double findMedian() {
        if (size % 2 == 1) return *it;
        else return (*it + *next(it, 1)) / 2.0;
    }
};
```
