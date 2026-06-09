### 解题思路
直接插入 886ms 44.2mb
二分查找插入 344ms 44.3mb
大小顶堆辅助 136ms 44.4mb
运用大小顶堆排序的核心：
1. 保持大小顶堆数目只相差1个，可以奇数个数时插入大顶堆，偶数时插入小顶堆。
2. 大顶堆是前半截的数字，小顶堆是后半截的。在插入大顶堆时，先和小顶堆堆顶元素进行比较，如果大于，那么把该值和小顶堆top元素互换，把小顶堆堆顶元素作为待插入到大顶堆的元素。插入小顶堆时同理。
    
### 代码

```cpp
class MedianFinder {
private: 
    priority_queue<int,vector<int>,less<int> > bigq;
    priority_queue<int,vector<int>,greater<int> >smallq;
    int len = 0;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        // 如果是奇数放在左侧（大顶堆），偶数放在右侧（小顶堆）
        len++;
        if(len%2==1){
            if(!smallq.empty()&&num>smallq.top()){
                bigq.push(smallq.top());
                smallq.pop();
                smallq.push(num);
            }
            else bigq.push(num);
        }
        else{
            if(!bigq.empty()&&num<bigq.top()){
                smallq.push(bigq.top());
                bigq.pop();
                bigq.push(num);
            }
            else smallq.push(num);
        }
    }
    
    double findMedian() {
        if(len%2==1) return double(bigq.top());
        else return double(bigq.top()+smallq.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```