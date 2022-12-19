### 解题思路
单调队列

### 代码

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        int ans = INT_MIN;           
        vector<int> sum(2*n);
        sum[0] = A[0];
        for(int i = 0;i < n;++i)A.push_back(A[i]);
        for(int i = 1;i < 2*n;++i)sum[i] = sum[i-1] + A[i];
        deque<int> q;
        for(int i = 0;i < 2*n;++i){
            //注意有效的子序列为q.front < i-n
            if(!q.empty() && q.front() < i-n)q.pop_front();
            //注意在这里更新答案
            if(!q.empty())ans = max(ans,sum[i]-sum[q.front()]);
            while(!q.empty() && sum[i] < sum[q.back()])q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};
```