```
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        memset(vis,true,sizeof(vis));
        res=0;
        sort(A.begin(), A.end());
        vector<int> tmp(A.size());
        dfs(0, vis, tmp, A);
        return res;
    }
    void dfs(int cnt, bool* vis, vector<int>& tmp, vector<int>& A) {
        if(cnt==A.size()) {
            res++;
            return;
        }
        int selected=-1;
        for(int i=0;i<A.size();i++) {
            if(vis[i]&&A[i]!=selected) {
                if(cnt>0) {
                    double ans = sqrt(tmp[cnt-1]+A[i]);  // 剪枝
                    if(ans!=(long long)ans) {
                        continue;
                    }
                }
                selected=A[i];
                vis[i]=false;
                tmp[cnt]=A[i];
                dfs(cnt+1, vis, tmp, A);
                vis[i]=true;
            }
        }
    }
private:
    bool vis[13];
    int res;
};
```
