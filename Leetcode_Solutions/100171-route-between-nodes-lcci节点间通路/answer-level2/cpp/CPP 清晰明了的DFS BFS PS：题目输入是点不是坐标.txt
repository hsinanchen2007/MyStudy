### 解题思路
1. 其实题目挺简单的，毕竟蛋疼的是这个输入，开始我以为是点的坐标，纠结了好久。实际上就是点vec[0]->vec[1]
2. BFS、DFS时间差不多，具体肯定是要看用例的类型的。

### 代码

```cpp
class Solution {
public:   

    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        map<int, set<int>> nodeMap;        
        set<int> visited;        
        for (auto vec : graph) {
            int p1 = vec[0];
            int p2 = vec[1];            
            nodeMap[p1].insert(p2);
        }
                
        queue<int> s;        
        s.push(start);
        while (!s.empty()) {
            int p = s.front();            
            s.pop();
            if (p == target) {
                return true;
            }
            visited.insert(p);
            set<int>& nexts = nodeMap[p];
            for (int val : nexts) {
                if (visited.find(val) == visited.end()) {
                    s.push(val);
                }
            }
        }
        return false;
    }
};
```
```cpp
class Solution {
public:   

    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        map<int, set<int>> nodeMap;        
        set<int> visited;        
        for (auto vec : graph) {
            int p1 = vec[0];
            int p2 = vec[1];            
            nodeMap[p1].insert(p2);
        }
                
        stack<int> s;        
        s.push(start);
        while (!s.empty()) {
            int p = s.top();
            s.pop();
            if (p == target) {
                return true;
            }
            visited.insert(p);
            set<int>& nexts = nodeMap[p];
            for (int val : nexts) {
                if (visited.find(val) == visited.end()) {
                    s.push(val);
                }
            }
        }
        return false;
    }
};
```