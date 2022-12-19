### 解题思路
单调队列

### 代码

```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int sum = 0;
        pair<int,int>st[50001];
        int top = -1;
        int be = 0;
        int ans = 1e8;
        for(int i=0;i<A.size();i++)
        {
            pair<int,int> a;
            a.first = sum;
            a.second = i-1;
            while(top >=be && st[top].first >= sum)
                top -- ;
            st[++top] = a;

            sum += A[i];

            while(be <= top && sum - st[be].first >= K)
            {
                ans = min(ans, i - st[be].second);
                be++;
            }
            
        }
        if(ans == 1e8)
            ans = -1;
        return ans;

    }
};
```