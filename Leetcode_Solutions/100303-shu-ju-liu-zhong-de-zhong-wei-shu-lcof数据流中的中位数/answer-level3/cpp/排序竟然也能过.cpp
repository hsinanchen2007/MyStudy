```
class MedianFinder {
public:
    /** initialize your data structure here. */
    // 简单的思路是维护一个size，addNum的时候插入排序，size表示个数
    vector<int> dataFlow;
    MedianFinder() {
    }
    void addNum(int num) {
        dataFlow.push_back(num);
        int len = dataFlow.size();
        int t = num;
        int i;
        for(i=len-2; i>=0 && dataFlow[i]>num; --i)
            dataFlow[i+1]=dataFlow[i];
        dataFlow[i+1]=t;
    }
    
    double findMedian() {
        int len = dataFlow.size();
        if(len==0){
            return 0;
        } 
        if(len%2){
            return dataFlow[len/2];
        }
        else{
            return (dataFlow[len/2]+dataFlow[len/2-1])/2.0;
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
