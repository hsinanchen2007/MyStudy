### 解题思路
col，pie，na 中二进制为1 的位置 表示当前行所在格子在3个方向上(列，正向对角线，反向对角线)是否有皇后攻击。与(1<<n)-1做与运算，是为了将高位清0，如n=4 我们只关注最后4位。
bits = (~(col | pie | na)&(1<<n)-1)，bits结果中二进制位为1所在的列，就是当前行可以放置皇后的位置。
举例说明，初始状态 col=pie=na=0，那么 bits=1111(2),表示第一行，所有的格子都可以放置皇后。
现在来看while循环，p = bits&-bits 我们得到了最低位的1，也就是0001，也就是第一行决定皇后放在最后一列上。
接下来看下一层递归row = row+1 = 2；
col = col | p=0001 ,即第二行第4个格子在列的方向会有皇后攻击。
pie = (pie | p)<<1 = 0010，即第二行第3个格子在正向对角线方向有皇后攻击。
na = (na | p)>>1 = 0000,即第二行反向对角线上没有皇后攻击。(右移将row=1时的0001的1移除棋盘外了)。
bits = (~(0001 | 0010 | 0000))&(1<<n-1) = 1100。
row = 2时可以在第一列，第二列放置皇后。
如果在递归到某一行出现bits=0了，说明获取不到可以摆放皇后的位置了，需要回溯。bit = bits&(bits-1)，将最低位的1清零。再获得下一个有效的位置，继续求解。
### 代码

```java
class Solution {
    int count = 0;
    public void dfs(int row,int col,int pie,int na,int n){
        if(row>=n){
            count++;
            return;
        }
        int bits = (~(col|pie|na)&(1<<n)-1);
        while(bits>0){
            int p = bits&-bits;
            dfs(row+1,col|p,(pie|p)<<1,(na|p)>>1,n);
            bits = bits&(bits-1);
        }
    }
    public int totalNQueens(int n) {
        dfs(0,0,0,0,n);
        return count;
    }
}
```