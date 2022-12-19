```c++
class MedianFinder {
public:
    priority_queue<int,vector<double>,less<int>> max;
    priority_queue<int,vector<double>,greater<int>>min;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(max.empty() || num<= max.top())
            max.push(num);
        else
            min.push(num);
        if(max.size() == min.size()+2)
        {
            //max多 min push max的
            int num = max.top();
            min.push(num);
            max.pop();
        }
        if(max.size()+1 == min.size())
        {
            //min多  max  push min的
            int num = min.top();
            max.push(num);
            min.pop();
        }
    }
     double findMedian() {
        return max.size() == min.size() ? (max.top() + min.top())/2 : max.top();
    }
};
```
