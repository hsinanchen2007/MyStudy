### 解题思路
不能进入行坐标和列坐标的数位之和大于k的格子,也不能越过`行坐标和列坐标的数位之和大于k的格子`组成的`隔离线`

### 代码

```c
int bitSum(int x){
    int sum=0;
    do{
        sum+=x%10;
        x/=10;
    }while(x!=0);
    return sum;
}
int movingCount(int m, int n, int k){
    if(!k) return 1;
    int areaSize=1;
    bool vis[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=0;
        }
    }
    vis[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if((i==0 && j==0) || bitSum(i)+bitSum(j)>k) continue;
            if(i-1>=0) vis[i][j] |= vis[i-1][j];         
            if(j-1>=0) vis[i][j] |= vis[i][j-1];
            areaSize+=vis[i][j];         
        }
    }
    //printf("%d",bitSum(4));
    return areaSize;
}
```