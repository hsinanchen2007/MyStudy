### 解题思路
第一种解法如代码所示
第二种解法比较简单就是使用插入排序,不过使用插入排序的比较复杂度为O(n)，可以使用二分查找减少比较次数

### 代码

```cpp
class MedianFinder {
public:
    //方法一，优先队列（使用堆实现）
    //定义两个优先队列（一个是最大堆，存放中位数右边的数，一个是最小堆，存放中位数右边的数）
    priority_queue<int,vector<int>,less<int>> maxheap;//大顶堆
    priority_queue<int,vector<int>,greater<int>> minheap;//小顶堆
    int media;
    bool flag; //media是否有值
    /** initialize your data structure here. */
    MedianFinder() {
        flag=false;
        media=-1;
    }
    
    void addNum(int num) {
        if(flag)
        {
            if(num>media)
            {
                minheap.push(num);
                maxheap.push(media);
            }
            else
            {
                minheap.push(media);
                maxheap.push(num);
            }
            flag=false;
        }
        else
        {
            if(!maxheap.empty()&&num<maxheap.top())
            {
                media=maxheap.top();
                maxheap.pop();
                maxheap.push(num);
            }
            else if(!maxheap.empty()&&num>minheap.top())
            {
                media=minheap.top();
                minheap.pop();
                minheap.push(num);
            }
            else
            {
                media=num;
            }
            flag=true;
        }
    }
    
    double findMedian() {
        if(flag)
        {
            return media;
        }
        else
        {
            return (1.0*(minheap.top()+maxheap.top())/2.0);
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