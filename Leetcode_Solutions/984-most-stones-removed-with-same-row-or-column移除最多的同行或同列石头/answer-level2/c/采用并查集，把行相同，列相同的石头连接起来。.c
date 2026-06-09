### 解题思路
找到集合的个数，就是剩余石头的个数，移动最多的次数就是总次数减去集合个数。
### 代码

```c


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

int removeStones(int** stones, int stonesSize, int* stonesColSize){

if(stonesSize == 0 || stones == 0) {
    return 0;
}
a = malloc(sizeof(int) * stonesSize);
pre = malloc(sizeof(int) * stonesSize);
int unit = 0;
for(int i = 0; i < stonesSize; i++) {
   a[i] = i;
   pre[i] = i;
}

for(int i = 0; i < stonesSize; i++) {
    for(int j = i; j < stonesSize; j++){
                if(stones[i][0] == stones[j][0] || 
                    stones[i][1] == stones[j][1]){
                        merge(i,j);
                    }
    }
}

for(int i = 0; i < stonesSize; i++) {
   if(pre[i] == i) {
       unit++;
   }
}
//printf("%d %d \r\n", stonesSize, unit);

return stonesSize - unit;

}
```