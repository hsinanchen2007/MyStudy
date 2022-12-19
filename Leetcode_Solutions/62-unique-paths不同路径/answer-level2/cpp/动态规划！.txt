我终于也自己动规写出来了。。。
```
int dp(int m ,int n){
        //if(cm==m && cn==n)
            //return res+1;
        vector<vector<int>>v(m,vector<int>(n,0));
        for(int j=1;j<n;j++)
            v[0][j]=1;
        for(int i=1;i<m;i++)
            v[i][0]=1;
        v[0][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                    v[i][j]+=v[i-1][j]+v[i][j-1];
            }
        }
        return v[m-1][n-1];
    }
```
菜鸟在路上