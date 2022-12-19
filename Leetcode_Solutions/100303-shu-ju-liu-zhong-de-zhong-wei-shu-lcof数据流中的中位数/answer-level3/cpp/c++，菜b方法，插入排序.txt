### 解题思路


### 代码

```cpp
class MedianFinder {
    vector<double> pool;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        bool flag = true;
        for(int i=0;i<pool.size();i++){
            if(pool[i]>=num){
                pool.insert(pool.begin()+i,num);
                flag = false;
                break;
            }
        }
        if(flag){
            pool.push_back(num);
        }
    }
    
    double findMedian() {
        int len = pool.size();
        if(len%2 == 1) return pool[len/2];
        else return (pool[len/2-1]+pool[len/2])/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```