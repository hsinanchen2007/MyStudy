```
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        q1.push(num);
        q2.push(q1.top());
        q1.pop();
        while(q1.size() < q2.size()) {
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    double findMedian() {
        double res;
        if(q1.size() == q2.size())
            return (q1.top() + q2.top()) * 0.5;
        else 
            return q1.top();

    }
private:
    priority_queue<int> q1; // 存放较小的那一部分元素(从大到小)
    priority_queue<int, vector<int>, greater<int>> q2; // 存放较大的那一部分元素(从小到大)
};
```
