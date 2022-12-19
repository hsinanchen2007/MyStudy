思路来自Liuyubobobo大神
将这个问题转化为图论问题：
从n走到0，每一个数字代表一个节点，
如果两个数字x到y，相差一个完全平方数，则可以连接一条边，
这样得到一个无权图

找到这个无权图中，从n到0的最短路径，
上代码：
```
int numSquares(int n) {
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));

        vector<bool> visited(n+1, false);
        visited[n] = true;
        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            for(int i = 1; ;i++){
                int a = num - i * i;
                if(a < 0) break;
                if(a == 0) return step + 1;

                if(!visited[a])
                    q.push(make_pair(a, step + 1));
                    visited[a] = true;
            }            
        }
        return n;
    }
```

我这个菜鸡弟中弟是不可能想出这么优美的算法的
只能跪服了
