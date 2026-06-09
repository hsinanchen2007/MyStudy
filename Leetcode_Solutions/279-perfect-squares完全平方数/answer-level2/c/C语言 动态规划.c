对每个n，比较小于sqrt（n）的所有数的平方和及n-其平方和的状态。
```
int numSquares(int n){
    int *ans = (int *)malloc(sizeof(int)*(n+1));
    ans[0]=0;
    ans[1]=1;
    for(int i=2; i<=n; i++){
        int min=999;
        int r=sqrt(i);
        for(int j=1; j<=r; j++){
            min=min<1+ans[i-j*j]?min:1+ans[i-j*j];
        }
        ans[i]=min;
    }
    return ans[n];
}
```
