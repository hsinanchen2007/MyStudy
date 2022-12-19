### 解题思路
C++ 多种解法
### 代码

```cpp
class Solution{
public:
    //                      11
    //       10                      7             2
    //9      6        1         6         3        1
    //动态规划 
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            //6 最大 1+1+1+1+1+1 全1
            dp[i] = i;
            for(int j = 1;j * j <= i;j++){
                //比如求4的最小完全平方数 f(4) -> min(f(3) ,f(0))+1
                //4 - 1 * 1   4 - 2 * 2
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }

    //使用递归树 记忆化
    int numSquares2_(vector<int>&dp,int n){
        if(dp[n]) return dp[n];
        
        int val = (int)sqrt(n);
        //结束条件
        if(val * val == n){
            return dp[n] = 1;
        }
        int res = n;
        for (int i = 1; i * i <= n; i++) {
            res = min(res, numSquares2_(dp, n - i * i) + 1);
        }
        return dp[n] = res;
    }

    int numSquares2(int n) {
        vector<int>dp(n+1,0);
        numSquares2_(dp, n);
        return dp[n];
    }
    
    //BFS
    int numSquares3(int n) {
        if(n <= 1) return 1;

        vector<bool> visited(n+1, false);
        visited[n] = true;
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        
        while(!q.empty()){
            int n = q.front().first;
            int step = q.front().second;
            q.pop();
            //一层一层的遍历  每m遍历一层step + 1 所以最开始等于0的step就是最小的
            if(n == 0) return step;

            for(int i = 1; i * i <= n; i++){
                int target = n - i * i;
                if(visited[target]) continue;

                q.push(make_pair(target, step + 1));
                visited[target] = true;
            }
        }
        return -1;
    }
};