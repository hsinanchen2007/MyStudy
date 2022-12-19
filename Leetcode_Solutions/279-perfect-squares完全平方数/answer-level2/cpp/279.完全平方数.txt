# 动态规划
若至少dp[i]个完全平方数相加为i，则dp[i] = min(dp[i], dp[i-j*j]+1)。
```c++
class Solution {
public:
    int numSquares(int n) {
       vector<int> dp(n+1, 0);
       for (int i = 1; i <= n; ++i){
           dp[i] = i;
           for (int j = 1; j*j <= i; ++j){
               dp[i] = min(dp[i], dp[i-j*j]+1);
           }
       } 
       return dp[n];
    }
};
```

# BFS
类似于最短路算法的暴力解法。
```c++
class Solution {
public:
    typedef pair<int, int> pi;
    map<int, bool> vis; // lower time & room by unique the queue_element.
    int numSquares(int n) {
        int up = int(sqrt(n)), t;
        queue<pi> q;
        pi tmp(0, 0);
        q.push(tmp); // !!!!!!!!!!!!
        // vis[0] = true;
        while(!q.empty()){
            tmp = q.front(); q.pop();
            for (int i = (int)sqrt(n-tmp.first); i >= 1; --i){ // decrease the counting time, save room as well.
                t = tmp.first + i*i;
                if (t == n){
                    return tmp.second + 1;
                }else if (t < n && !vis[t]){
                    // printf("%d %d\n", tmp.second+1, tmp.first+i*i);
                    q.push(make_pair(t, tmp.second+1));
                    vis[t] = true;
                }
            }
        }
        return 0;
    }
};
```

>dp较之bfs时空复杂度都更低，代码也更为简洁。
