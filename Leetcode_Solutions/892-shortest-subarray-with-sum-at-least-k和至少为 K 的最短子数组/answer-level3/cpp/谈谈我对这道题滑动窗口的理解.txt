### 解题思路
**本来标签里有二分的，但想了半天也没想到该怎么定义单调函数，就借鉴了官方题解的思路。
前缀和数组是常规操作了，我们维护一个单调递增的前缀和双端队列。为什么要这么做呢？
因为在滑动窗口左边界固定的情况下，考虑右边界为i和i+1，如果从左边界加到i+1比从左边界加到i更小，那么加到i的子数组更可能超过K，更符合题目长度更小的要求。
在加入新的右边界时，可能这个数字很大，以至于左边去掉一些数字的话，子数组和也会大于K，这时候我们不断将左边界右移，找出最小的区间长度。**
（最近发现滑动窗口的题好难TAT）

### 代码

```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> pre(A.size(),A[0]);
        for(int i=1;i<pre.size();i++)
            pre[i]=pre[i-1]+A[i];
        deque<pair<int,int>> q;
        q.push_back(make_pair(-1,0));
        int res=INT_MAX;
        for(int i=0;i<pre.size();i++)
        {
            while(!q.empty()&&pre[i]<q.back().second)
                q.pop_back();
            q.push_back({i,pre[i]});
            while(q.back().second-q.front().second>=K)
            {
                res=min(res,q.back().first-q.front().first);
                q.pop_front();
            }
        }
        return res==INT_MAX?-1:res;
    }
};
```