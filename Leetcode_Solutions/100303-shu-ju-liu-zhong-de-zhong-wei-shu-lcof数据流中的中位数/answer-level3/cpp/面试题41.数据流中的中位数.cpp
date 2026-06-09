### 解题思路
- 核心要点：设置两个优先队列，分别存数据流前半部分和后半部分，前半部分用大顶堆存，后半部分用小顶堆存。
- 添加num：先添加到大顶堆（前半部分），再把大顶堆首移入小顶堆，判断一下前半部分是否长于后半部分，如是则把小顶堆首移入大顶堆。
- 找中位数：若前半部分长于后半部分（共有奇数个num），返回大顶堆首；否则返回大小顶堆首的平均值。
### 代码

```cpp
class MedianFinder {
    priority_queue<int>lo;
    priority_queue<int,vector<int>,greater<int>>hi;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();

        if(lo.size()<hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size()>hi.size()?lo.top():(lo.top()+hi.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```