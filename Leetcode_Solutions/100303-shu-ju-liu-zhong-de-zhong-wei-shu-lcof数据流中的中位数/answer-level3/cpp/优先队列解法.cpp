```
// 优先队列实现（注意“优先队列”用法类似stack，和普通队列不一样）
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num)
    {
        int grossSum = mMax.size() + mMin.size();
        if(grossSum & 1){
            if(!mMin.empty() && num > mMin.top()){
                int temp = mMin.top();
                mMin.pop();
                mMin.push(num);
                num = temp;
            }
            mMax.push(num);

        }else{
            if(!mMax.empty() && num < mMax.top()){
                int temp = mMax.top();
                mMax.pop();
                mMax.push(num);
                num = temp;
            }
            mMin.push(num);
        }

    }

    double findMedian()
    {
        int grossSum = mMax.size() + mMin.size();
        if(grossSum & 1)
            return (double)(mMin.top());
        else
            return (double)(mMax.top() + mMin.top()) / 2;
    }


private:
    // 注意这里less默认最大堆，而greater是最小堆。
    priority_queue<int, vector<int>, less<int> > mMax;     // 大根堆
    priority_queue<int, vector<int>, greater<int> > mMin;  // 小根堆

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
