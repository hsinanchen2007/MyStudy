### 解题思路

两个队列同时BFS，分别代表先走红边和先走蓝边两种情况。

### 代码

```cpp
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> red(n, -1);
        vector<int> blue(n, -1);
        queue<int> redQ;
        queue<int> blueQ;
        vector<vector<int>> red_graph(n);
        vector<vector<int>> blue_graph(n);
        
        for(auto& e: red_edges) {
            red_graph[e[0]].push_back(e[1]);
        }
        for(auto& e: blue_edges) {
            blue_graph[e[0]].push_back(e[1]);
        }
        
        redQ.push(0);
        blueQ.push(0);
        red[0] = 0;
        blue[0] = 0;
        int level = 0;
        while(!redQ.empty() || !blueQ.empty()) {
            level++;
            queue<int> newRed, newBlue;
            int rN = redQ.size();
            for(int i=0; i<rN; i++) {
                int u = redQ.front();
                redQ.pop();
                for(int v: blue_graph[u]) {
                    if(blue[v] == -1) {
                        newBlue.push(v);
                        blue[v] = level;
                    }
                }
            }
            int bN = blueQ.size();
            for(int j=0; j<bN; j++) {
                int u = blueQ.front();
                blueQ.pop();
                for(int v: red_graph[u]) {
                    if(red[v] == -1) {
                        newRed.push(v);
                        red[v] = level;
                    }
                }
            }
            redQ = newRed;
            blueQ = newBlue;
        }
        vector<int> res(n);
        for(int i=0; i<n; i++) {
            if(red[i] == -1 && blue[i] == -1)
                res[i] = -1;
            else if(red[i] == -1)
                res[i] = blue[i];
            else if(blue[i] == -1)
                res[i] = red[i];
            else
                res[i] = min(red[i], blue[i]);
        }
        return res;
    }
};
```