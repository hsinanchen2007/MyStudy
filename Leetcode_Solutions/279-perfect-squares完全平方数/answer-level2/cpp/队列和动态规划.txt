### 解题思路
此处撰写解题思路

### 代码

```cpp

// 队列：广度优先遍历
int numSquares(int n) {
    queue<pair<int,int>> q;
    vector<bool> vis(n+1, false);
    q.push(make_pair(n, 0));
    vis[n] = true;

    while(!q.empty()) {
        int num = q.front().first;
        int step = q.front().second;
        q.pop();
        if(num == 0){
            return step;
        }
        for(int i = 1; num - i * i >= 0; i++) {
            if(!vis[num - i * i]) {
                q.push(make_pair(num - i * i, step + 1));
                vis[num - i * i] = true;
            }
        }
    }
}
// DP:
int numSquares(int n) {
    if(n == 0) {
        return 0;
    }
    vector<int> memo(n+1, INT_MAX);
    memo[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; i - j * j >= 0; j++) {
            memo[i] = min(memo[i], 1 + memo[i - j * j]);
        }
    }
    return memo[n];
}
```