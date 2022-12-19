```
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int>l;
    priority_queue<int,vector<int>,greater<int>>r;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(l.empty()){
            l.push(num);
        }else{
            int lmax=l.top();
            if(num<lmax){
                l.pop();
                r.push(lmax);
                l.push(num);
            }else{
                r.push(num);
            }
            if(r.size()>l.size()){
                l.push(r.top());
                r.pop();
            }
        }
    }
    
    double findMedian() {
        if(l.size()==r.size()){
            return (l.top()+r.top())/2.0;
        }else return l.top();
    }
};


```
