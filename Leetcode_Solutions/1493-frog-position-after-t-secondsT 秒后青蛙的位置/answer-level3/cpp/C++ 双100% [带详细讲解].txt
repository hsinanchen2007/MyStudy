### 这道题因为青蛙每跳都要计算时间，因此使用BFS可以很方便的对每次的时间进行记录。

### 题解如下：
```
class Solution {
private:
    // node结构体用于保存节点信息
    struct node {
        int v;     // 节点值
        int time;  // 到达该节点所花费的时间
        double p;  // 到达该节点的概率
        
        node(int vv, int tt, double pp) : v{vv}, time{tt}, p{pp} {}
    };
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> mat(n+1); // 用于保存树型结构
        vector<int> visit(n+1, 0);  // 记录节点是否已经访问
        
        // 用链表法建树
        for (int i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0], v = edges[i][1];
            mat[u].push_back(v);
            mat[v].push_back(u);
        }
        
        // 按BFS遍历
        queue<node> que;
        que.push(node(1, 0, 1.0));
        while (!que.empty())
        {
            node no = que.front();

            que.pop();
            visit[no.v] = 1;
            
            // 统计它的子节点数量
            int count = 0;
            for (int i = 0; i < mat[no.v].size(); ++i)
            {
                int u = mat[no.v][i];
                if (visit[u] == 0) 
                    count++;
            }
            // 如果达到target节点，那么进行时间判定
            if (no.v == target)
                // 满足条件有两种情况，一是准时到达，二是提早到达但原地踏步
                if (t > no.time && count == 0 || t == no.time)
                    return no.p;
    
            // 将它的所有未访问的子节点加入到队列中
            for (int i = 0; i < mat[no.v].size(); ++i)
            {
                int u = mat[no.v][i];
                if (visit[u] == 0)
                    que.push(node(u, no.time+1, no.p * 1.0 / count));
            }
        }
        return 0.0;
    }
};
```
