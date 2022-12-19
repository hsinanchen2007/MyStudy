### 解题思路
通过dfs找到从root到target的路径，然后找到路径上每个点的儿子节点数
路径上所有节点(不包括target))的儿子节点数相乘就是分母fm，结果是1/fm

对于特殊情况
1. target = 1
此时，若根节点无儿子节点，则结果必为1，否则青蛙会跳走，结果为0
2. 可以走到target，但是时间仍有多余，即代码中的flag && !time_flag
此时，需要判断青蛙是否会一直在target停留，若target是叶子节点，则结果不为0，否则结果为0

### 代码

```cpp
class Solution {
public:
    vector<int> graph[105];
    bool vis[105];
    bool flag = false;  // 标记青蛙是否可在规定时间内到达target
    bool time_flag = false; // 标记青蛙是否在给定时间恰好到达target
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        // 目标节点是根节点，直接判断
        if(target == 1) {
            if(graph[1].size() == 0) return 1.0;
            else return 0;
        }
        vector<int> trace;
        dfs(t, 0, 1, target, trace);
        // 可以走到target并且时间刚刚好
        if(flag && time_flag) {
            return output(trace);
        }
        else {
            // 可以走到target但是时间有多余，且在target无法往下走了
            if(flag && (int)graph[target].size() == 1) {
                return output(trace);
            }
            // 走不到targe
            return 0.0;
        }
    }

    void dfs(int t, int tm, int root, int target, vector<int>& trace) {
        if(root == target) {
            flag = true;
            time_flag = (tm == t);
            return ;
        }
        if(tm >= t) return ;
        vis[root] = true;
        trace.push_back(root);
        for(int i = 0; i < graph[root].size(); i++) {
            if(!vis[graph[root][i]]) {
                dfs(t, tm + 1, graph[root][i], target, trace);
                if(flag) return ;
            }
        }    
        trace.pop_back();
        vis[root] = false;
    }

    double output(vector<int>& trace) {
        double fm = 1.0;
        for(int i = 0; i < trace.size(); i++) {
            if(i) fm *= (double(graph[trace[i]].size()) - 1);
            else fm *= double(graph[trace[i]].size());
        }
        return 1 / fm;
    }
};
```