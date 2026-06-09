### 解题思路
此处撰写解题思路
总的来说，就是从第一行开始一列列地试。
如果该点能放皇后，即该点的行列两个对角线都没有皇后，就可以放。因为是顺序寻找的，所以不用判断改行有没有皇后，只需判断该列有没有皇后，两个对角线有没有皇后即可，对角线上的元素根据坐标存在规律，45度对角线上，横纵坐标的和始终为定值，135对角线上，n-1-(row-col)为定值，因为row+col和n-1-(row-col)的大小不会超过2*n-2，所以只要定义两个大于2*n-2的数组即可，还定义一个判断列的数组，然后就是dfs,从第一行开始，一列一列地找，如果符合标准，就将queen数组对应的位置的字符变为Q，然后将该列，该点两条对角线变为true，表示已经不能再放queen了，然后完了之后就要回溯，因为会存在多种情况，回溯之前要将所有的标志都变为初始状态，否则会影响下一轮查找。
### 代码

```java
class Solution {
    private int n;
    private char[][]queen;
    private List<List<String>>ret=new ArrayList<>();
    private boolean[]usedC;
    private boolean[]used45;
    private boolean[]used135;
    public List<List<String>> solveNQueens(int n) {
        this.n=n;
        queen=new char[n][n];
        for(int i=0;i<n;i++)
           Arrays.fill(queen[i],'.');
        usedC=new boolean[n];
        used45=new boolean[2*n-1];
        used135=new boolean[2*n-1];
        solve(0);
        return ret;
    }
    private void solve(int row){
        if(row==n){
            List<String>t=new ArrayList<>();
            for(char[]c:queen){
                t.add(new String(c));
            }
            ret.add(t);
            return;
        }
    
    for(int col=0;col<n;col++){
        if(usedC[col]||used45[row+col]||used135[n-1-(row-col)]) continue;
        queen[row][col]='Q';
        usedC[col]=used45[row+col]=used135[n-1-(row-col)]=true;
        solve(row+1);
        usedC[col]=used45[row+col]=used135[n-1-(row-col)]=false;
        queen[row][col]='.';
    }
    }
}
```