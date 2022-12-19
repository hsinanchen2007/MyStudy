### 解题思路
此处撰写解题思路
优先队列必用
method1:暴力遍历，再出队k个
method2:事件触发机制，挤牙膏，每出队一个，再双指针中滑动一个
时间复杂度：优先队列建立O(n*logn)，入队O(logn)

### 代码
m1:
```cpp
//brutal

#include <queue>

class Solution {
    struct cmp{
        bool operator ()(vector<int> &a, const vector<int> &b)
        {
            // < :大顶堆
            // > :小顶堆
            return a[0]+a[1] > b[0]+b[1];
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
priority_queue<vector<int>, vector<vector<int>>, cmp> myQue;
    for(auto n1:nums1)
    {
        for(auto n2:nums2)
        { 
            vector<int> tmp{n1,n2};
            myQue.push(tmp);
        }
    }
vector<vector<int>> resVec;
    for(int i = 0; i < k; ++i)
    {
        if(myQue.empty()) break;
        resVec.push_back(myQue.top());
        myQue.pop();
    }
    return resVec;
    }
};

```

m2:
```cpp
//改brutal为
//事件触发机制：挤牙膏式得结果!!!!
//避免无意义的遍历
//哪个出队就移动对应的base
//[nums1pos, nums2pos]出队了
//则[nums1pos, nums2pos+1]入队
//初始状态[0,0] [1,0] [2,0] ...[nums1.size()-1,0]都得入队

//算法有了，now设计数据结构

class Solution {
    struct cmp{
        bool operator()(pair<int,pair<int,int>> &A, const pair<int,pair<int,int>>&B)
        {
            //小顶堆： 用>号
            return A.first > B.first;
        }
    };

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> myQue;
vector<vector<int>> resVec;
        if(nums1.empty() || nums2.empty()) return resVec;
        for(int i = 0; i < nums1.size(); ++i)
        {
            myQue.push(pair<int,pair<int,int>>(nums1[i]+nums2[0],pair<int,int>(i,0)));
        }
        while(resVec.size() < k && !myQue.empty())
        {
            vector<int> tmp{nums1[myQue.top().second.first], nums2[myQue.top().second.second]};
            resVec.push_back(tmp);
            if(myQue.top().second.second+1 < nums2.size())
            {
                myQue.push(
                pair<int,pair<int,int>>(nums1[myQue.top().second.first]+nums2[myQue.top().second.second+1],pair<int,int>(myQue.top().second.first, myQue.top().second.second+1))
                ); 
            }
            myQue.pop();
        }
        return resVec;
    }
};
```