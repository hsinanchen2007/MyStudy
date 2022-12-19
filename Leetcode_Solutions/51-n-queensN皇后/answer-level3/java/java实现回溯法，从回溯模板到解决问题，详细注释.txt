ps：皇后可以攻击同一行、同一列以及左上角、右上角、左下角、右下角这些角度方向上的任意单位。

**回溯法** 这道题使用回溯法的思路和[NO.37解数独](https://blog.csdn.net/qq_42758551/article/details/104478835)类似，每次填入一个元素就会导致增加后序填写时的约束条件。尝试依次填写的过程中无法继续时，就回溯并继续尝试另一种填写序列。

本题深度遍历回溯方法的骨架：

```
void dfs(棋盘board,当前行row,n){
	if(终止条件){
		保存当前序列;
		return;
	}
	for(int i=0;i<n;i++){
    	if(board[row][i]可以填写){
    		当前格子board[row][i]=1;
    		填写下一行dfs(board,row+1,n);
    		擦除填写，验证下一个序列board[row][i]=0;
    	}
    }
}
```

终止条件是什么：棋盘的0~n-1行都填写完毕，即row==n。

如何保存当前序列：棋盘使用int[\][\]数组表示，0为'.'，1为'Q'。遍历每一行转换为字符串存入list，最后list存入结果。

如何判断当前格子是否可以：遍历当前列上是否已经有皇后；遍历当前左上至右下对角线上是否已经有皇后；遍历当前右上至左下对角线上是否已经有皇后。这些遍历只需要检测小于当前的行，因为大于当前的行还没有填写到一定没有皇后。

```java
List<List<String>> res=new ArrayList<>();
public List<List<String>> solveNQueens(int n) {
    //棋盘,默认为0表示空，1表示皇后
    int[][] board=new int[n][n];
    //row当前填写得的行号
    dfs(n,0,board);
    return res;
}

//深度优先遍历
private void dfs(int n, int row, int[][] board) {
    //0~n-1都填写完毕
    if (row==n){
        res.add(track(board,n));
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isUsable(board,row,col)){
            board[row][col]=1;
            //填写下一行
            dfs(n,row+1,board);
            board[row][col]=0;
        }
    }
}

//board[row][col]是否可用
private boolean isUsable(int[][] board, int row, int col) {
    //检查列上有无皇后
    for (int i = 0; i < row; i++) {
        if (board[i][col]==1)return false;
    }
    //检查左上至右下对角线有无皇后
    for (int i = col-1; i >= 0; i--) {
        if (i+row-col<0)break;
        if (board[i+row-col][i]==1)return false;
    }
    //检查右上至左下对角线有无皇后
    for (int i = col+1; i < board.length; i++) {
        if (row+col-i<0)break;
        if (board[row+col-i][i]==1)return false;
    }
    return true;
}

//将int类型棋盘转换成输出格式
private List<String> track(int[][] board, int n) {
    List<String> list=new ArrayList<>();
    for (int i = 0; i < n; i++) {
        StringBuilder temp=new StringBuilder();
        for (int j = 0; j < n; j++) {
            if (board[i][j]==0)temp.append('.');
            else temp.append('Q');
        }
        list.add(temp.toString());
    }
    return list;
}
```

时间复杂度：O(n!)

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/) 