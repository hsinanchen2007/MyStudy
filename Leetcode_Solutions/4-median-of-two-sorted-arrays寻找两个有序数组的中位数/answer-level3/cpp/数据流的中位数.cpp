### 解题思路
就是剑指offer中的数据流的中位数，把两个数组都插入进去
[具体解题思路](https://blog.csdn.net/liuyuchen282828/article/details/104206135)

### 代码

```cpp
class Solution {
    priority_queue<int,vector<int>,less<int>> max;
    priority_queue<int,vector<int>,greater<int>> min;
public:
    void Insert(int num)
    {
        if(max.empty() || num<= max.top())
            max.push(num);
        else
            min.push(num);
        
        //保证两个堆的元素个数之差小于1
        if(max.size() == min.size()+2)
        {
            min.push(max.top());
            max.pop();
        }
        if(max.size()+1 == min.size())
        {
            max.push(min.top()); 
            min.pop();
        }
    }
    double GetMedian()
    { 
        return max.size() == min.size() ? (max.top()+min.top())/2.0 : max.top();
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i<nums1.size();++i)
        {
            Insert(nums1[i]);
        }
        for(int i = 0;i<nums2.size();++i)
        {
            Insert(nums2[i]);
        }
        double res =GetMedian();
        return res;
    }
};
```