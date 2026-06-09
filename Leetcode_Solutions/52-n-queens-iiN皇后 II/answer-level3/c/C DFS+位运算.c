![52.png](https://pic.leetcode-cn.com/59c294956bdd33757baf4494af59738b6b576690510e29501170185d427887ab-52.png)


```
int cnt = 0;
void dfs (int n, int row, int col, int pie, int na)
{
  if (row>=n){ cnt++; return;}

  int bits = (~(col|pie|na)) & ((1<<n)-1);
  while (bits>0){
    int p = bits &(-bits);
    dfs(n, row+1, col|p, (pie|p)<<1, (na|p)>>1);
    bits &= (bits-1);
  }
}

int totalNQueens(int n){
  if (n<1) return 1;
  cnt = 0;
  dfs(n, 0, 0, 0, 0);
  return cnt;
}
```
