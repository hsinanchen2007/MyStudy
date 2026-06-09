### 解题思路
此处撰写解题思路

### 代码

```cpp
class MedianFinder {
public:
    /** initialize your data structure here. */   
    priority_queue<int,vector<int>,greater<int>> LeftPart;  //数组左半部分为最大堆
    priority_queue<int,vector<int>,less<int>> RightPart;    //数组右半部分为最小堆
    MedianFinder() {

    }
    
    void addNum(int num) {
        //维护左右数量差小于1；维护左半部分所有数值都小于右半部分
        //左右部分数量均衡则插入最小堆
        if(LeftPart.size()==RightPart.size())
        {
            //先插入最大堆，然后把最大堆的最大值(堆顶)弹出压入最小堆
            LeftPart.push(num);
            RightPart.push(LeftPart.top());
            LeftPart.pop();
        }            
        //左右部分数量不均衡则插入最大堆
        else
        {
            //先插入最小堆，然后把最小堆的最小值(堆顶)弹出压入最大堆
            RightPart.push(num);
            LeftPart.push(RightPart.top());
            RightPart.pop();
        }                    
    }
    
    double findMedian() {
        if(RightPart.empty())
            return -1;
        double Median;
        if(LeftPart.size()==RightPart.size())
            Median=(LeftPart.top()+RightPart.top())/2.0;
        else
            Median=double(RightPart.top());  
        return Median;      
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```