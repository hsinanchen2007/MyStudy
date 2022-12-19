```
//补充一个并查集的解法
int[] parent=null;

int[] size=null;

int max=0;

public void merge(int a,int b){
    int fa=find(a);
    int fb=find(b);
    if(fa==fb) return;
    if(size[fa]>size[fb]){
        parent[fb]=fa;
        size[fa]+=size[fb]; 
        max=Math.max(max,size[fa]); //统计最大值
    }else{
        parent[fa]=fb;
        size[fb]+=size[fa];
        max=Math.max(max,size[fb]);
    }
}

public int find(int p){
    if(parent[p]==p) return p;
    parent[p]=find(parent[p]); //路径压缩
    return parent[p];
}

public int maxAreaOfIsland(int[][] grid) {
    int m=grid.length;
    int n=grid[0].length;
    //init
    parent=new int[m*n];
    size=new int[m*n];
    for (int i=0;i<m*n;i++){
        parent[i]=i;
        size[i]=1;
    }
    //1 1 1 1 
    //1 1 1 1
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if(grid[i][j]==1){
                //特判一下 hahaha~ 感觉如果不是lc有wacase我还挺难发现这个
                max=Math.max(max,1);
                //和前面,上面的合并
                if(i>0 && grid[i-1][j]==1) merge(i*n+j,(i-1)*n+j);
                if(j>0 && grid[i][j-1]==1) merge(i*n+j,i*n+j-1);
            }
        }
    }
    return max;
}
```
