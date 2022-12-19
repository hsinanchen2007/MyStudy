### 解题思路
95击败
找入度为0
### 代码

```cpp
class Solution {
public:
    vector<int> h, e, ne;
    int idx = 0;
    vector<int> d;//代表入度
    int n;
    int ans = 0;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        int t = numCourses + 10;
        h = vector<int>(t, -1); e = vector<int>(10*t, -1); ne = vector<int>(10*t, -2);
        d = vector<int>(t, 0);
        //构建邻接表
        for(int i = 0;i < prerequisites.size();++i){
            add(prerequisites[i][1], prerequisites[i][0]);
            d[prerequisites[i][0]] ++;
        }
        return topsort();
    }
    void add(int a, int b){
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx ++;
    }
    bool topsort(){
        queue<int> q;
        for(int i = 0;i < n;++i)
            if(d[i] == 0) q.push(i);
        while(!q.empty()){
            int t = q.front();
            q.pop(); ans++;
            for(int i = h[t];i != -1;i = ne[i]){
                int j = e[i]; -- d[j];
                if(d[j] == 0) q.push(j);
            }
        }
        return ans == n ? true : false;
    }
};
```