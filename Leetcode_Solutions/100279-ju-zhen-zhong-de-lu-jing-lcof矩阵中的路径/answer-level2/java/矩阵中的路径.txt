**解题思路：**

首先查找其在矩阵中的路径，先把其在矩阵中移动的方向表示出来：
dh = {0,1,0,-1}
dw = {1,0,-1,0}
分别对应的是上下左右；

定义一个boolean[][]数组，代表矩阵中的每个字符是否被使用过，在判断完之后，需要将这个位置的字符使用情况复原，以便于第二次回溯的时候继续能够使用这个字符；

同时需要一些边界条件的判断，以及递归的终止条件，当右边匹配到了对应word的最后一个字符时，即可返回true;
代码如下：
```java
class Solution {
    //定义上下左右
    int[] dh = {1,0,-1,0};
    int[] dw = {0,1,0,-1};
    public boolean exist(char[][] board, String word) {
        boolean[][] viewed = new boolean[board.length][board[0].length];
        if(board.length==0){
            return false;
        }
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(dfs(board,word,i,j,0,viewed)){
                    return true;
                }
            }
        }
        return false;
    }

    public boolean dfs(char[][] board,String word,int row,int column,int index,boolean[][] viewed){
        //回溯剪枝
        if(row<0||row>board.length-1||column<0||column>board[0].length-1
        ||viewed[row][column]||board[row][column]!=word.charAt(index)){
            return false;
        }
        //递归终止条件
        if(++index==word.length()){
            return true;
        }
        viewed[row][column] =true;//代表该字符被使用过；
        for(int i=0;i<4;i++){
            if(dfs(board,word,row+dh[i],column+dw[i],index++,viewed)){
                return true;
            }
        }
        //将该位置的字符还原，未使用过;
        viewed[row][column] = false;
        return false;
    }
}
```


