### 解题思路
n皇后问题：用 n 行 n 列的矩阵表示一个国际象棋棋盘，若两个皇后位于同一行、同一列、同一对角线上（包括下图所示的各主对角线和次对角线），则称为它们为互相攻击。n皇后问题是指找到这 n 个皇后的互不攻击的布局。

![image.png](https://pic.leetcode-cn.com/c8baa2eab88c666f40daaa2df8d738bdfe1656eb9f9328cab8b3b62652e17538-image.png)

每行每列正好一个皇后
按行的顺序，检查所有可能放置皇后的情况，每次判断是否与已有皇后冲突

### 代码

```cpp
class Solution {
public:
    int res=0;
    vector<bool> d,ud; //d为主对角线，ud为次对角线，用于记录该条斜线上是否已有皇后
    vector<bool> col;  //col用于记录相应列上是否已有皇后

    void dfs(int row,int n){
        if(row == n){  //一共n-1列，说明一种情况成立
            res ++;
            return;
        }
        for(int i = 0;i < n;i ++){
            if(!col[i] && !d[row + i] && !ud[n + row - i -1]){
                col[i] = d[row + i] = ud[n + row - i -1] = true;
                dfs(row + 1,n);
                col[i] = d[row + i] = ud[n + row - i -1] = false;
            }
        }
    }

    int totalNQueens(int n) {
        d = ud = vector<bool>(2 * n,false);
        col = vector<bool>(n,false);
        dfs(0,n);
        return res;
    }
};
```