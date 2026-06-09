基于两个优先队列
max 存中位数左侧的最大值，
min 存中位数右侧的最小值
```
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) 
    {
        int temp=0;
        if(((max.size()+min.size())&1)==0)
        {       
            if(!max.empty() && num<max.top())
            {
                temp=max.top();
                max.pop();
                max.push(num);
                min.push(temp);
            }
            else
                min.push(num);
            
        }
        else
        {
            if(!min.empty() && num>min.top())
            {
                temp=min.top();
                min.pop();
                min.push(num);
                max.push(temp);
            }
            else
                max.push(num);
           
        }
    }
    
    double findMedian() 
    {
        if(((max.size()+min.size())&1)==0)
        {       
            return ((double)max.top()+(double)min.top())/2.0;
        }
        return min.top();
    }
    private:
    priority_queue<int,vector<int>,greater<int>> min;
    priority_queue<int,vector<int>,less<int>> max;
};
```
