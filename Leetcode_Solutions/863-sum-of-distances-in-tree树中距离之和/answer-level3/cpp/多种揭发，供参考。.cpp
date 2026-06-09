佛洛依德（超时）
```
class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>>v(N+1,vector<int>(N+1,0));
        for(int i=0;i<N;++i)
         for(int j=0;j<N;++j)
         {
             v[i][j]=10000;
         }
         for(int i=0;i<edges.size();++i)
         {
             v[edges[i][0]][edges[i][1]]=1;
             v[edges[i][1]][edges[i][0]]=1;

         }
         for(int k=0;k<N;++k)
         for(int i=0;i<N;++i)
         for(int j=0;j<N;++j)
         {
             if(v[i][j]>v[i][k]+v[k][j])
             {
                 v[i][j]=v[i][k]+v[k][j];
             }
         }
         vector<int>ans;
         for(int i=0;i<N;++i)
         {  
             int sum=0;
             for(int j=0;j<N;++j)
             {
             if(i!=j)
             {
                 sum+=v[i][j];
             }
             }
             ans.push_back(sum);
         }
         return ans;
        
    }
};
```

