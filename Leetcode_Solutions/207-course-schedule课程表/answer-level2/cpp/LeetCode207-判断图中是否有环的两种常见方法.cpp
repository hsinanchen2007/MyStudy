## 思路

* 要按题目给定拓扑序列构建拓扑图，若要能顺利完成所有课程，说明图中不能存在课程的死锁，即循环等待。说白了就是图中不能有环。
* 所以题目就是裸题判断图中是否有关。一般有两种方法判断图中是否存在环。
    1. 拓扑排序： 若不存在拓扑排序，说明图中有环。（证明略）
    2. dfs：通过查看每个点是否会走回到自己来判断是否有环。（通过设立3种状态优化dfs速度）

### 拓扑排序判环
建图
1. 把所有把所有入度为0的点全部加进队列
2. 拿一个入度为0的点，然后把以该点t为入度的点的入度减一，若入度减成0，加入队列
3. 若全部节点都被访问才说明有 拓扑序

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> inDegree(numCourses);
        // 1. 建图 
        for (auto &v : prerequisites) {
            int from = v[1], to = v[0];
            g[from].push_back(to);
            ++inDegree[to];
        }
        
        // 初始化
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        
        // 拓扑排序
        int cnt = 0;
        while (!q.empty()) {
            int t = q.front(); q.pop();
            cnt++;
            for (int v : g[t]) {
                if (--inDegree[v] == 0)
                    q.push(v);
            }
        }
        
        return cnt == numCourses;
    }
};
```

### DFS判环

建图
1. 遍历每一个节点，若该节点有环说明图中存在环
2. used设置成3种状态： 0:未访问节点， 1当前正在被访问，-1已经确定过的点
3. 访问该节点的时候，把当前节点标记成1，正在被访问。所继续往下走，**走到了原来走过的点说明存在环了**，没走过继续走到没得走为止或者剩余点都确认过。
4. 访问完了就把当前节点置成-1说明该点已经确认过了。
5. 返回确认结果

```cpp
class Solution {
public:
    vector<vector<int>> g;
    vector<int> used;   // 0:未访问节点， 1当前正在被访问，-1已经确定不存在环的点
    
    // dfs(x)判断经过该点x是否会有环，若有环返回false，无环返回true
    bool dfs(int x) {
        used[x] = 1;  // 标记正在访问
        
        for (int v : g[x]) {
            if (used[v] == 1) return false; // 走过了说明有环
            if (used[v] == 0 && !dfs(v)) return false; // 如果没走过该点，但走了该点后会发生环也说明有环
        }
        
        used[x] = -1;  // 当前点已经确定过了，不存在环
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g = vector<vector<int>>(numCourses);
        used = vector<int>(numCourses);
        // 建图
        for (auto &v : prerequisites) {
            int from = v[1], to = v[0];
            g[from].push_back(to);
        }
    
        for (int i = 0; i < numCourses; i++)
            if (used[i] == 0 && !dfs(i)) 
                return false;  // 说明有环

        return true;   // 说明无环
    }
};
```