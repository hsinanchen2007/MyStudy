
```
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, int> indegree;
        for(auto& v : prerequisites) {
            indegree[v[0]]++;
        }
        queue<int> que;
        for(int i=0; i<numCourses; ++i) {
           if(indegree[i] == 0) {
               que.push(i);
           }
        }
        int cnt = 0;
        while(!que.empty()) {
            int k = que.front();
            que.pop();
            cnt++;
            for(auto& v : prerequisites) {
                if(k == v[1]) {
                    if(--indegree[v[0]] == 0) {
                        que.push(v[0]);
                    }
                }
            }
        }
        if(cnt != numCourses)
            return false;
        return true;
```