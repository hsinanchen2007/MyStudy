```
class Solution {
public:
    int delta[2][2] ={{1,0},{0,1}};
    int res=0;
    int movingCount(int m, int n, int k) {
        
        if(k==0) return 1;
        vector<bool> vis(m*n+1,false);
        
        DFS(0,0,m,n,k,vis);
        return res;
    }
        void DFS(int i,int j,int m,int n,int k,vector<bool>& vis)
        {
            if(i<=m-1&&j<=n-1&&vis[i*n+j]==false)
            {
                int rowSum=GetSum(i);
                int colSum=GetSum(j);

                if(rowSum+colSum>k) return ;
                res++;
                vis[i*n+j]=true;

                for(auto d:delta)
                {
                    int n_i=i+d[0];
                    int n_j=j+d[1];

                    DFS(n_i,n_j,m,n,k,vis);
                }
            }
        }
    

    int GetSum(int val)
    {
        int res=0;
        while(val>0)
        {
            res+=val%10;
            val/=10;
        }
        return res;
    }
};
```
