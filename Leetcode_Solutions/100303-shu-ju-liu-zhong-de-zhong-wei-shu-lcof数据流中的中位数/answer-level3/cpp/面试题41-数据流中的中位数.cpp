### 解题思路
理解题意：要构造一中数据结构，包含两个函数，一是添加，二是返回中位数。
易想到，把输入的数排好序保存，然后取中位数的时候就只要判断奇偶数就行了。
### C++代码

```cpp
class MedianFinder {
public:
   vector<int> store; 

public:
    void addNum(int num)
    {
        if(store.empty())
        {
            store.push_back(num);
        }
        else
        {
            store.insert(lower_bound(store.begin(),store.end(),num),num);
        }
    }

    double findMedian()
    {
        if(store.empty())
            return 0;
        int len = store.size();
        return len & 1 ? store[len/2] : (store[len/2]+store[len/2-1])*0.5;
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```