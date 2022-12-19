### 解题思路
C++使用STL的优先队列求解，思路简洁清晰。

### 代码

```cpp
class Solution {
public:
    struct cmp
    {
        bool operator()(int x,int y)
        {
            return x > y;
        }
    };
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        priority_queue<int,vector<int>,cmp> pqueue;
        for(auto i:nums1)
        {
            pqueue.push(i);
        }
        for(auto j:nums2)
        {
            pqueue.push(j);
        }
        int SIZE = pqueue.size();
        double result = 0;
        if(SIZE%2==0)
        {
            int t1 = SIZE/2;
            for(int i=1;i<t1;i++)
            {
                pqueue.pop();
            }
            int temp = pqueue.top();
            pqueue.pop();
            result = (temp + pqueue.top())/2.0;
        }
        else
        {
            int t1 = SIZE/2+1;
            for(int i=1;i<t1;i++)
            {
                pqueue.pop();
            }
            double r1 = pqueue.top();
            result = r1/1.0;
        }
        return result;
    }
};
```