### 解题思路
此处撰写解题思路

### 代码

```cpp
class MedianFinder {
 
    vector<int > lit;
    vector<int > gra;
    int mid;
    bool begining;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        lit.clear();
        gra.clear();
       begining = false;
    }
    
    void addNum(int num) {
        if(!begining){mid = num;begining = true;return;}
       if(num > mid){gra.push_back(num);}else{lit.push_back(num);}
       if(gra.size() > lit.size()){
           auto newmid = min_element(gra.begin(),gra.end());
           lit.push_back(mid);
           mid = *newmid;
           gra.erase(newmid);
       }else if(lit.size() > gra.size()+1){
           auto newmid = max_element(lit.begin(),lit.end());
           gra.push_back(mid);
           mid = *newmid;
           lit.erase(newmid);
       }

    }
    
    double findMedian() {
       if(gra.size() == lit.size()) { return mid; }
       if(lit.size() > gra.size()){ 
           auto left = max_element(lit.begin(),lit.end());
           double x = mid + *left;
           return x / 2.0;
       }
       
        return -0.4571111111111;
       
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```