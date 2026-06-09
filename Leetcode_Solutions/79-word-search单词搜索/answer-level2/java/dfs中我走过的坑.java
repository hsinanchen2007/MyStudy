### 解题思路
就是dfs没啥好说的，我就是说说编码的时候遇到的坑
对于四个方向都可以走的情况，如果没有限制，直接走四个循环，就会变成死循环
1 2
3 4   1->2->3->4->1 
所以，可以加上一个visited表，在递归中，每次访问一个节点，标记一次，但是要记住，访问完要把节点清空，不要影响下次访问
算出结果后标记，直接返回，不要纠缠。
注意边界情况。

### 代码

```java
class Solution {
    private boolean Isok;
    private int [][] make;
    private void _Work(char[][] board,String word,int lever,int j,int k,int forward){
        if(make[j][k]==1||Isok==true){
            return;
        }
        else
            make[j][k]=1;
        if(lever==word.length()) {
            Isok=true;
            return;
        }
        if(j>=board.length||k>=board[0].length) {
            return;
        }
        if((j+1>=0&&j+1<board.length)) {
            if(board[j+1][k]==word.charAt(lever)&&forward!=-1)
                _Work(board, word, lever + 1, j + 1, k,0);
        }
        if((j-1>=0&&j-1<board.length)) {
            if(board[j-1][k]==word.charAt(lever)&&forward!=0)
                _Work(board, word, lever + 1, j -1, k,-1);
        }
        if((k+1>=0&&k+1<board[0].length)&&forward!=2) {
            if(board[j][k+1]==word.charAt(lever))
                _Work(board, word, lever + 1, j, k + 1,1);
        }
        if((k-1>=0&&k-1<board[0].length)&&forward!=1) {
            if(board[j][k-1]==word.charAt(lever))
                _Work(board, word, lever + 1, j, k - 1,2);
        }
        make[j][k]=0;
    }
    public boolean exist(char[][] board, String word) {
        Isok=false;
        make=new int[board.length][board[0].length];
        for(int j=0;j<board.length;j++){
            for(int k=0;k<board[0].length;k++){
                if(word.charAt(0)==board[j][k]){
                    _Work(board,word,1,j,k,-2);
                }
            }
        }
        return this.Isok;
    }
}
```