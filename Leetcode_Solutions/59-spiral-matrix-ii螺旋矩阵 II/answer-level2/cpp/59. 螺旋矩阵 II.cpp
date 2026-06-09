想了好久没想出来，只好拿大佬的代码做笔记了。。
```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > vvi(n, vector<int>(n));
        int num=1;
        int t=0, b=n-1, l=0, r=n-1;
        while(num<=n*n){
            for(int i=l; i<=r; i++) vvi[t][i]=num++; //从左到右，上面消去一行
            t++;
            for(int i=t; i<=b; i++) vvi[i][r]=num++; //从上到下，右面消去一列
            r--;
            for(int i=r; i>=l; i--) vvi[b][i]=num++; //从右到左，下面消去一行
            b--;
            for(int i=b; i>=t; i--) vvi[i][l]=num++; //从下到上，左面消去一列
            l++;
        }
        return vvi;
    }
};
```