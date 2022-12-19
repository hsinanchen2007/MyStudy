

Kahn 算法

执行用时 :20 ms, 在所有 C++ 提交中击败了97.90% 的用户

内存消耗 :14.3 MB, 在所有 C++ 提交中击败了43.81%的用户

```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);

        for(auto &p : prerequisites){
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        stack<int> stk;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) stk.push(i);
        }

        stack<int> order;
        while(!stk.empty()){
            int c = stk.top();
            stk.pop();
            order.push(c);
            for(auto & pre : graph[c]){
                indegree[pre]--;
                if(indegree[pre] == 0){
                    stk.push(pre);
                }
            }
        }

        vector<int> res;
        if(order.size() < numCourses) return res;
        while(!order.empty()){
            res.push_back(order.top());
            order.pop();
        }
        return res;
    }
};
```


BFS; 和Kahn算法不同之处仅仅在于使用queue而不是stack
```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);

        for(auto &p : prerequisites){
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }

        stack<int> order;
        while(!q.empty()){
            int c = q.front();
            q.pop();
            order.push(c);
            for(auto & pre: graph[c]){
                if(--indegree[pre] == 0){
                    q.push(pre);
                }
            }
        }

        vector<int> res;
        if(order.size() < numCourses) return res;
        while(!order.empty()){
            res.push_back(order.top());
            order.pop();
        }
        return res;
    }
};
```

DFS

执行用时 :24 ms, 在所有 C++ 提交中击败了91.92% 的用户

内存消耗 :16 MB, 在所有 C++ 提交中击败了20.10%的用户

```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        for(auto &p : prerequisites){
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        unordered_map<int, int> visited;
        vector<int> res;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                if(dfs(graph, i, visited, res)){
                    return vector<int>();
                }
            }
        }
        if(res.size() < numCourses) return vector<int>();
        return res;
    }

    // return TRUE if loop detected.
    bool dfs(unordered_map<int, vector<int>> & graph, int course, 
            unordered_map<int, int> & visited, vector<int> & res){
        if(visited[course] == 2) return false;
        if(visited[course] == 1) return true;  // Loop detected

        visited[course] = 1;
        for(auto & p: graph[course]){
            if(dfs(graph, p, visited, res)){
                return true;
            }
        }
        visited[course] = 2;
        res.push_back(course);
        return false;
    }
};
```