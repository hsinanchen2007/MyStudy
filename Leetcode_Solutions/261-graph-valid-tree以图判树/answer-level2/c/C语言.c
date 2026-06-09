**出错用例：**
`        输入：
        4
        [[0,1],[2,3]]
        输出：
        true
        预期：
        false`
出错原因：没有判断count的值，加上return count==1;，则运行正确。
如果不写这个count值的判断，就没有判断边不够用的情况，count>1是两个联通图，在这道题里面也就是两个树。

```
bool UnionFind(int x,int y,int *count,int *roots,int *rank){
    int rootx=Find(x,roots);
    int rooty=Find(y,roots);
    if(rootx==rooty)return false; //证明存在环，边还没有加进去，点就已经是联通的了
    if(rank[rootx]>rank[rooty]){
        roots[rooty]=rootx;
    }else if(rank[rootx]<rank[rooty]){
        roots[rootx]=roots[rooty];
    }else {
        roots[rooty]=rootx;
        rank[rootx]+=1;
    }
    (*count)--;
    return true;
}
int Find(int i,int *roots){
    while(i!=roots[i])i=roots[i];
    return i;
}
bool validTree(int n, int** edges, int edgesSize, int* edgesColSize){
    if(edgesSize>=n)return false;
    int count=n;
    int *roots=(int*)malloc(sizeof(int)*n);
    int *rank=(int*)malloc(sizeof(int)*n);
    memset(rank,0,sizeof(int)*n);
    for(int i=0;i<n;i++){
        roots[i]=i;
    }
    for(int i=0;i<edgesSize;i++){
        if(!UnionFind(edges[i][0],edges[i][1],&count,roots,rank))
            return false;
    }
    return count==1;
}
```