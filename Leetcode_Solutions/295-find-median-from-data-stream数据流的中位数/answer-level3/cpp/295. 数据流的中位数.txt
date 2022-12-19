### 解题思路
直接看注释吧，这题和滑动窗口的中位数解法类似
https://leetcode-cn.com/problems/sliding-window-median/

### 代码

```cpp
class MedianFinder {
public:
    multiset<int> int_set;
    multiset<int>::iterator it_median;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {//插入元素的时候就把中位数找出来，避免再去排序
        int_set.insert(num);
        int size = int_set.size();
        if(size == 1){
            it_median = int_set.begin();
        }else if(((size % 2) == 1) && (*it_median <= num)){
            it_median++;
        }else if(((size % 2) == 0) && (*it_median > num)){
            it_median--;
        }
    }
    
    double findMedian() {//根据中位数的定义和窗口所含元素的奇偶个数获取中位数。
        int size = int_set.size();
        if(size % 2 == 1){//k是奇数
            return *it_median;
        }

        return 0.5 * ((double)*it_median + (double)*next(it_median));//k是偶数
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```