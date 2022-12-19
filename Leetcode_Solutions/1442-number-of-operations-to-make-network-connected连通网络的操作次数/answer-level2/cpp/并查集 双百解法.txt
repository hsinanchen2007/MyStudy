```
class Solution {
public:
    int getRoot(int n, vector<int>& father){
        if(father[n] != n) n = getRoot(father[n], father); 
        return n;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        if(len < n - 1)
            return -1;
        vector<int> father(n, 0);
        for(int i = 0; i < n; i ++)
            father[i] = i;
        for(auto &c:connections){
            int minnum = min(c[0], c[1]);
            int maxnum = max(c[0], c[1]);
            int x = getRoot(minnum, father);
            int y = getRoot(maxnum, father);
            if(x != y)
                father[y] = x;
        }
        set<int> res;
        for(int i = 0; i < n; i ++){
            int num = getRoot(i, father);
            res.insert(num);
        }

        return res.size() - 1;
    }
    void dfs(map<int,vector<int>> &grip, vector<int> &vis, int num){
        if(vis[num] == 1)
            return;
        else{
            vis[num] = 1;
            for(auto &g:grip[num]){
                dfs(grip, vis, g);
            }
        }
    }
};
```
