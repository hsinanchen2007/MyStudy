### 解题思路
使用并查集。

### 代码

```c
#define MAX 500

int *a, *pre;

int find(int x) {
  if (x != pre[x])
    //找到其祖先节点
    pre[x] = find(pre[x]);
  //由父节点继续向上递归查询 ,并将其父节点变成找到的
  return pre[x];
}
void merge(int x, int y) {
  //分别查询两点的祖先节点。
  int prex = find(x);
  int prey = find(y);
  //如果二者的祖先节点不一致，那么任意让二者中某一个认另一个为祖先，保证同集合。
  if (prex == prey) {
    return;
  }
  //应该是祖先节点进行组合。而不是当前节点！
  pre[prey] = prex;
  a[prex] += a[prey];
}


int findCircleNum(int** M, int MSize, int* MColSize){

if(MSize == 0){
    return 0;
}
a = malloc(sizeof(int)*(MSize+1));
pre = malloc(sizeof(int)*(MSize+1));

for(int i = 0 ;i < MSize+1; i++)
{
    a[i] = i;
    pre[i] = i;
}
//对于i，j->i*n+j --->转换成一个点。
for(int i= 0 ;i < MSize; i++)
{
    for(int j = 0; j < *MColSize; j++) {
        if(i == j) {continue;}
        if(M[i][j] == 1){
            merge(i,j);
        }
    }
}

int total = 0;
for(int i = 0 ;i < MSize; i++)
{
    if(pre[i] == i)
    {
        total++;               
    }
}
free(a);
free(pre);

return total;

}
```