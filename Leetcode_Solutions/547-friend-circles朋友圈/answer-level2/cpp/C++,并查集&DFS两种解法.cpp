方法一：
并查集：
```
const int maxn=205;
int fathers[maxn];
class Solution {
public:
//典型的并查集题目,写Union以及find函数
   // vector<int>fathers();
    int find(int i){//找父亲结点的位置
        // while(fathers[i]!=i){
        //     i=fathers[i];
        // }
        while(fathers[i]!=i)i=fathers[i];
        return i;
    }
    void uni(int i,int j){
        int f1=find(i);
        int f2=find(j);
        fathers[f2]=f1;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        if(n==0)return 0;
        //并查集将每一个点的父亲先设置成自己
        //初始化
        for(int i=0;i<n;i++){
            fathers[i]=i;//将自己设置成自己的父亲
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(M[i][j]==1){
                    uni(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(fathers[i]==i)count++;
        }
        return count;
    }

};
```
方法二：
DFS:这个DFS就是只要求解更新vis的数组，其他的不需要做，DFS一直往下搜，出现1，那么说明是一个团伙的
```
class Solution {
public:
    void dfs(vector<vector<int>>& M,int i,int n,vector<int>&vis){//更新vis这个数组的情况
        for(int j=0;j<n;j++){
            if(M[i][j]==1&&vis[j]==0){
                vis[j]=1;
                dfs(M,j,n,vis);//下一次，是从当前行进行深搜下去。。。
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        vector<int>vis(n+1,0);
        int ans=0;
        for(int i=0;i<n;i++){//先按照行进行搜索
            if(vis[i]==0){
                dfs(M,i,n,vis);
                ans++;
            }
        }
        return ans;
    }
};
```
