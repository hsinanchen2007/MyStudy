### 解题思路
技巧：把环形展开为一个长度为2n的线段，好处是所有区间长度在n内都可以在线段找到
 1<=长度<=n
 滑动窗口求极值

 Si - Sj 代表j+1,j+2...i的和

### 代码

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        for(int i = 0 ; i < n; i++)A.push_back(A[i]);
        vector<int> sum(n * 2 + 1);
        for(int i = 1; i <= n * 2; i++)//从1开始，不会越界
        {
            sum[i] = sum[i - 1] + A[i - 1];
        } 
        int res = INT_MIN;
        deque<int>q;
        q.push_back(0);//前0个数的和是0 先放入边界
        for(int i = 1; i <= n* 2;i++)
        {
            if(q.size() && i - n > q.front())q.pop_front();//最大长度为n
            if(q.size()) res = max(res,sum[i] - sum[q.front()]); 
            while(q.size() && sum[q.back()] >= sum[i])q.pop_back();//求最小的队首
            q.push_back(i);

        }
        return res;
        
    }
};
```