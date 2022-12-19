### 解题思路
- 生成两个堆：`small`和`large`。用`small`堆存放数据中较小的一半元素，`large`堆存放数据中较大的一半元素
- 我们只要保证两个堆有以下**其中之一**的特性：
    a)`small`的元素个数和`large`的元素个数相等
    b)`small`的元素个数比`large`的元素个数多一
- 对于上面的a)情况，我们只要返回`small`堆顶元素和`large`堆顶元素之和的一半，即`(small.top() + large.top()) * 0.5`,即当前数据个数为偶数的情况下求中位数。对于上面的b)的情况，返回`small.top()`即可，为数据个数为奇数的情况下求中位数
- **代码简单易懂，看代码！**

### 代码

```cpp
class MedianFinder {
public:
    /** initialize your data structure here. */

    //存放较小的一半元素，堆顶元素为该堆的最大值
    priority_queue<int> small;

    //存放较大的一半元素，堆顶元素为该堆的最小值
    priority_queue<int, vector<int>, greater<int>> large;

    void addNum(int num) {

        //元素一开始全都入堆small,然后将堆small的最大元素加入到堆large
        //这样可以保证堆small存放的是较小的一半元素，堆large存放的是较大的一半元素
        small.push(num);
        large.push(small.top());
        small.pop();

        //平衡两个堆的个数，使这两个堆具有特性a)或b)，即使得small的元素个数大于或等于large的元素个数
        if(large.size() > small.size()){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? double(small.top()) : (small.top()+large.top())*0.5; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```