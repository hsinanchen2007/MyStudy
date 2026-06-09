### 解题思路
此处撰写解题思路
维持两个堆的数量差值小于等于1
### 代码

```cpp
class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(pq1.empty()){
            pq1.push(num);
        }
        else if(pq1.size()==pq2.size()){
            if(num>pq2.top()){
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(num);
            }
            else{
                pq1.push(num);
            }
        }
        else{
            if(num<pq1.top()){
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            }
            else{
                pq2.push(num);
            }
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size()){
            return ((double)(pq1.top()+pq2.top()))/2;
        }
        else{
            return pq1.top();
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