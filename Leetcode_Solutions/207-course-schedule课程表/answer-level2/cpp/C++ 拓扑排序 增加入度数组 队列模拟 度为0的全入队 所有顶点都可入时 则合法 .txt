```
    int n;
    bool st[10010];
    int h[10010],e[10010],ne[10010],idx,deg[10010];
    void add(int a, int b){e[idx] = b, ne[idx] = h[a], h[a] = idx++;}
    bool topSort(){
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < n; i ++ ) if(!deg[i]) q.push(i),st[i]=true,cnt++;
        while(q.size()){
            int t = q.front();
            q.pop();
            for(int i = h[t]; i!=-1; i = ne[i]){
                int j = e[i];
                if(!st[j]){
                    deg[j]--;
                    if(deg[j]==0) q.push(j),st[j] = true,cnt++;
                }
            }
        }
        return cnt==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        n = numCourses;
        memset(h,-1,sizeof(h));
        for(auto v : pre) add(v[1],v[0]),deg[v[0]]++;
        return topSort();
    }
```
