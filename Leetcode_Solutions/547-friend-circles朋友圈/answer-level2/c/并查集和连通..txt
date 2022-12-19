### 解题思路
此处撰写解题思路
我是真的被评论区震惊到了.
太他妈生猛了.
原本以为只能通过并查集来解决.
结果居然也可以通过搜索算法来解决.
震惊.
然后就发现原来并查集和连通集之间是存在联系的.
具体就是:原来它们同出一源.
并查集中的一个集合不就是相互可达或者连通的嘛?
受教受教!
### 代码

```c
int act[205],rank[205];
int find(int x)
{
    if(act[x]==x) return x;
    else return act[x]=find(act[x]);
}
void unite(int x,int y)
{
    x=find(x),y=find(y);
    if(x!=y)
    {
        if(rank[x]<rank[y]) act[x]=y;
        else if(rank[x]>rank[y]) act[y]=x;
        else act[x]=y,rank[y]++;
    }
}
int findCircleNum(int** M, int MSize, int* MColSize){
    int cnt=0;
    for(int i=0;i<205;i++) act[i]=i,rank[i]=0;
    for(int i=0;i<MSize;i++)
    {
        for(int j=0;j<MSize;j++)
        {
            if(M[i][j])
            {
                unite(i,j);
            }
        }
    }
    for(int i=0;i<MSize;i++) if(act[i]==i) cnt++;
    return cnt;
}
```