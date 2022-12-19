```
//求最短距离，之后从某个城市出发，遍历所有满足条件的城市，用一个计数变量求出所有满足条件的城市，之后返回数量最小的城市
const int maxn=INT_MAX;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,maxn));//二维数组初始化
        for(auto e:edges){
            dist[e[0]][e[1]]=e[2];
            dist[e[1]][e[0]]=e[2];
        }
        //Floyd算法
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j||dist[i][k]==maxn||dist[k][j]==maxn)continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int ans=maxn;
        int count=0;
        int temp=maxn;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(dist[i][j]<=distanceThreshold)count++;
            }
            if(count<=ans){
                temp=i;
                ans=count;
            }
            count=0;
        }
        return temp;

    }
};
```
