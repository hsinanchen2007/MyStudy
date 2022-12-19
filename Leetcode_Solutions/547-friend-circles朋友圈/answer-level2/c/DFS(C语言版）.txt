### 解题思路
错误思想：一直以为邻接矩阵只有一半有用。。。。。
1.我们先创建一个矩阵，来判断这个人是否已经被有圈子，最开始没遍历时候都是0，开始遍历----只要有人和他有关系那么这个人就已经有圈子了，后序我们就不需要在找他的圈子了，对于没圈子的人，我们再找他的圈子。

### 代码

```c
int findCircleNum(int** M, int MSize, int* MColSize){
    if (MSize==1)
        return 1;
    int *frd,count=0;
    frd = (int*)malloc(sizeof(int)*MSize);
    memset(frd,0,sizeof(int)*MSize);
    void DFS(int x){
        frd[x] = 1;
        for (int i=0;i<MColSize[x];i++){
            if (M[x][i]==1 && frd[i]==0)
                DFS(i);
        }
    }
    for (int i=0;i<MSize;i++){
        if (frd[i]==0){
            DFS(i);
            count++;
        }
    }
    return count;
}
```