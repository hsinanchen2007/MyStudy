完全按顺序找满足要求的正方形，规律是从前往后找1，找到1后，从后遍历他右下方对角线是否存在1，如果存在再判断以这两点为正方形顶点是否能构成正方形，如果能构成则计算他的面积，从头到尾找完返回最大值。
```
int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize){
    int n=gridSize,m=gridColSize[0];
    int N=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]==1)
                for(int k=n-1;k>=i;k--)
                    if(j+k-i<m&&grid[k][j+k-i]==1){
                        int t=0;
                        for(int i1=0;i1<=k-i;i1++)
                            if(grid[i+i1][j]==0||grid[i+i1][j+k-i]==0||grid[i][j+i1]==0||grid[k][j+i1]==0){
                                t=1;
                                break;
                            }
                        if(t==0&&N<pow(k-i+1,2)){
                            N=pow(k-i+1,2);
                            break;
                        }
                    }
    return N;
}
```
