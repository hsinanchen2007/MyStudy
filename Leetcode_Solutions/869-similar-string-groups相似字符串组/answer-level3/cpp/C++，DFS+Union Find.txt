#### 解法一：DFS
```
const int maxn=1e4+10;
class Solution {
public:
    vector<int>g[maxn];
    int solve(string &s1,string &s2){
        int diff=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])diff++;
            if(diff>2)return 0;
        }
        return 1;
    }
    void dfs(int i,vector<int>&vis){
        vis[i]=1;
        for(auto v:g[i]){
            if(!vis[v]){
                dfs(v,vis);
            }
        }
    }
    int numSimilarGroups(vector<string>& a) {
        int n=a.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(solve(a[i],a[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis);
            }
        }
        return cnt;
    }
};
```
#### 解法二：Union Find
```
const int maxn=1e4+10;
class Solution {
public:
    int father[maxn];
    int find(int x){
        return father[x]==x?x:find(father[x]);
    }
    void uni(int a,int b){
        int f1=find(a);
        int f2=find(b);
        father[f2]=f1;
    }
    int solve(string &s1,string &s2){//注意这里传引用更加的快一点。。。
        int diff=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])diff++;
            if(diff>2)return 0;
        }
        return 1;
    }
    int numSimilarGroups(vector<string>& a) {
        int n=a.size();
        //int father[n];
        for(int i=0;i<n;i++)father[i]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(solve(a[i],a[j])){
                    uni(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(father[i]==i)cnt++;
        }
        return cnt;
    }
};
```
