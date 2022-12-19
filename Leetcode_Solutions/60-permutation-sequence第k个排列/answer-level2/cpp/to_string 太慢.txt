
jiayou
```
class Solution {
public:
    string ans;
    int n;
    int cnt;
    int k;
    int fac;
    vector<int>vis;
    void dfs(int start,string now){
        if(now.length() == n){
            cnt++;
            if(cnt == k){
                ans = now;
                return ;
            }
        }
        if(cnt == k) return ;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;
                now += char(i+'0');// to_string 太慢
                if(cnt<k){
                    dfs(1,now);
                } 
                now.pop_back();
                vis[i]=0;
            }
          
        }
    }
    /*
        剪枝呀。
    */
    string getPermutation(int n, int k) {
        this->n = n;
        this->k = k;
        cnt = 0;
        vis.assign(10,0);
        dfs(1,"");
        return ans;
    }
};
```
