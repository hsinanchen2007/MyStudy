### 解题思路一

单向BFS，把合法的节点及转移预先构图。

执行用时 :1436 ms, 在所有 C++ 提交中击败了5.14% 的用户
内存消耗 :416.6 MB, 在所有 C++ 提交中击败了5.03%的用户

实际上，可以一边BFS一边构图，无序预先 buildGraph()，可以提高计算和内存效率。

### 代码一

```cpp
class Solution {
private:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, bool> visited;
    unordered_set<string> dead;
public:
    int openLock(vector<string>& deadends, string target) {
        dead.insert(deadends.begin(), deadends.end());
        buildGraph();
        string source = "0000";
        
        queue<string> Q;
        int level = 0;
        Q.push(source);
        visited[source] = true;
        
        while(!Q.empty()) {
            int n = Q.size();
            for(int i=0; i<n; i++) {
                string cur = Q.front();
                Q.pop();
                if(cur == target)
                    return level;
                for(string& next: graph[cur]) {
                    if(!visited[next]) {
                        Q.push(next);
                        visited[next] = true;
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
    
    void buildGraph() {   
        for(int i=0; i<10000; i++) {
            string base = getNumber(i);
            if(dead.count(base) > 0)
                continue;

            for(int j=0; j<4; j++) {
                string next = base;
                int d = base[j] - '0';
                int inc = (d + 1) % 10;
                int dec = (d + 9) % 10;
                next[j] = '0' + inc;
                if(dead.count(next) == 0)
                    graph[base].push_back(next);
                next[j] = '0' + dec;
                if(dead.count(next) == 0)
                    graph[base].push_back(next);
            }
        }
    }
    
    string getNumber(int x) {
        if(x < 10)
            return "000" + to_string(x);
        if(x < 100)
            return "00" + to_string(x);
        if(x < 1000)
            return "0" + to_string(x);
        return to_string(x);
    }
};
```

### 解题思路二

双向BFS，从“0000“ 和 target这两端相向搜索。

### 代码二

```cpp
class Solution {
private:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, bool> visited;
    unordered_set<string> dead;
public:
    int openLock(vector<string>& deadends, string target) {
        dead.insert(deadends.begin(), deadends.end());
        buildGraph();
        string source = "0000";
        
        deque<string> startQ;
        startQ.push_back(source);
        visited[source] = true;
        deque<string> endQ;
        endQ.push_back(target);
        visited[target] = true;
        
        return bfs(startQ, endQ, target, 0);
    }
    
    int bfs(deque<string>& startQ, deque<string>& endQ, string target, int level) {
        if(startQ.size() == 0)
            return -1;
        // 从状态少的一端开始搜索
        if(startQ.size() > endQ.size())
            return bfs(endQ, startQ, target, level);
        
        /* debugging code
        cout << "Level: " << level << endl;
        cout << "Start: ";
        for(auto s: startQ)
            cout << s << ",";
        cout << endl;
        cout << "End: ";
        for(auto s: endQ)
            cout << s << ",";
        cout << endl;
        */
        
        int n = startQ.size();
        for(int i=0; i<n; i++) {
            string cur = startQ.front();
            startQ.pop_front();
            
            //if(cur == target)
            //    return level;             // 相遇才算找到
                
            for(string& next: graph[cur]) {
                if(find(endQ.begin(), endQ.end(), next) != endQ.end()) {
                    return level + 1;
                }
                if(!visited[next]) {
                    startQ.push_back(next);
                    visited[next] = true;
                }
            }
        }

        return bfs(startQ, endQ, target, level + 1);
    }
    
    void buildGraph() {   
        for(int i=0; i<10000; i++) {
            string base = getNumber(i);
            if(dead.count(base) > 0)
                continue;

            for(int j=0; j<4; j++) {
                string next = base;
                int d = base[j] - '0';
                int inc = (d + 1) % 10;
                int dec = (d + 9) % 10;
                next[j] = '0' + inc;
                if(dead.count(next) == 0)
                    graph[base].push_back(next);
                next[j] = '0' + dec;
                if(dead.count(next) == 0)
                    graph[base].push_back(next);
            }
        }
    }
    
    string getNumber(int x) {
        if(x < 10)
            return "000" + to_string(x);
        if(x < 100)
            return "00" + to_string(x);
        if(x < 1000)
            return "0" + to_string(x);
        return to_string(x);
    }
};
```