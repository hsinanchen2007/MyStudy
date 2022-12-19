### 回溯超时算法
```
class Solution {
public:
    vector<int> setp = {1,2};//爬楼梯步数，只能爬1或者2
    vector<int> path;
    vector<vector<int>> res;
    void DFS(int n)
    {
        //accumulate带有三个形参：头两个形参指定要累加的元素范围，第三个形参则是累加的初值。
        if (accumulate(path.begin(),path.end(),0) == n) {//路径中的代码满足爬楼梯层数要求，保存路径
            res.push_back(path);
            return ;
        }
        if (accumulate(path.begin(),path.end(),0) > n) {//爬楼梯失败，退出
            return;
        }
        for (int i = 0;i<setp.size();i++) {//不断在setp中回溯
            path.push_back(setp[i]);
            DFS(n);
            path.pop_back();
        }
    }
    int climbStairs(int n) {
        DFS(n);
        return res.size();
    }
};
```

### 动态规划代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+3,0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3;i<=n;i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
```