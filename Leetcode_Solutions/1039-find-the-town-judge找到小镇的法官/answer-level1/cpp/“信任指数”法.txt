### 解题思路
计算一个“信任指数”=被信任的次数-信任别人的次数。
显然只有法官的信任指数是N-1。

### 代码

```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n=trust.size();
        vector<int> can(N,0);
        int i=0;
        int j;
        for (i=0;i<n;i++)
        {
            j=trust[i][0]-1;
            can[j]--;
            j=trust[i][1]-1;
            can[j]++;
        }
        
        for (i=0;i<N;i++)
            if (can[i]==N-1) return i+1;
        return -1;
    }
};
```