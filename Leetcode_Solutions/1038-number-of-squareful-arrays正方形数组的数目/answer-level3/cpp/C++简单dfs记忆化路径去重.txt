```
//#define map unordered_map
#define ll long long
class Solution {
public:
    bool f[14]={false};
    int a=0;
    map<vector<int>,int>mp;
    void dfs(vector<int>& A,int x,vector<int>&re){
        int n=A.size();
        f[x]=true;
        re.push_back(A[x]);
        if(mp.find(re)!=mp.end()){
            re.pop_back();
            f[x]=false;
            return ;
        }
        else
        {
            mp[re]++;
        }
        if(re.size()==n){
            a++;
        }
        for(int i=0;i<x;i++){
            int t=A[x]+A[i];
            int e=sqrt(t);
            if(!f[i]&&(e*e)==t){
              dfs(A,i,re);
            }
        }
        for(int i=x+1;i<n;i++){
             int t=A[i]+A[x];
            int e=sqrt(t);
            if(!f[i]&&(e*e)==t){
                dfs(A,i,re);
             }
        }
        re.pop_back();
        f[x]=false;        
    }
    int numSquarefulPerms(vector<int>& A) {
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            dfs(A,i,ans);
        }
        return a;
    }
};                                                                                              
```
