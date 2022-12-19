### 解题思路
解题思路
原地算法：利用较少的资源，获得最终的结果。比如对于数组的输出，不复制数组，而是直接在原数组中修改数值。
对于这道题，如何在原来的数组上修改数值，并且最终能得知修改前和修改后的数值分别是多少。这时就需要用复合法，即一个数值可以代表原数组和现数组的值。
比如：
(0,1)->-1//代表原来是0，现在是1
(0,0)->0//代表原来是0，现在是0
(1,0)->1//代表原来是1，现在是0
(1,1)->2//代表原来是1，现在是1
这样，没变的为0，变了但原来是0的变为<=0，通过判断是否为<=0数值来判断是否为0；同理可判断是否为1
规定了这个规则后，就可以运用三步来解题
1、如果相邻数值>=1，则原数组值为1，活细胞数目加一
2、根据题目变化规则，综合本细胞为活细胞还是死细胞，邻细胞的活细胞数来判断本细胞的生死，并按照上述规则来赋值
3、最后遍历，根据上述规则还原更新后的细胞状态
解题方法：
1、自己用的是手写if语句来遍历每个邻细胞的状态，更新活细胞数，这样的话时间复杂度较低，只用0ms即可，打败97%
```java
                if(row-1>=0){
                    if(cols-1>=0){
                        if(board[row-1][cols-1]>=1){
                            count++;
                        }
                    }
                    if(board[row-1][cols]>=1){
                        count++;
                    }
                    if(cols+1<board [row].length){
                        if(board[row-1][cols+1]>=1){
                            count++;
                        }
                    }
                }
                if(row+1<board.length){
                    if(cols-1>=0){
                        if(board[row+1][cols-1]>=1){
                            count++;
                        }
                    }
                    if(board[row+1][cols]>=1){
                        count++;
                    }
                    if(cols+1<board [row].length){
                        if(board[row+1][cols+1]>=1){
                            count++;
                        }
                    }
                }
                if(cols-1>=0){
                    if(board[row][cols-1]>=1){
                        count++;
                    }
                }
                if(cols+1<board[row].length){
                    if(board[row][cols+1]>=1){
                        count++;
                    }
                }
```
2、优化思路是，创建邻居数组neighbours，对于本细胞双循环遍历邻居细胞，根据状态赋值。这个思路使得代码更加简洁，但时间复杂度较高，用了1ms打败了38%
### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int count=0;
        int[] neighbours={0,-1,1};
        for (int row =0 ; row < board.length; row++) {
            for (int cols =0 ; cols < board [row].length; cols++) {
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(!(neighbours[i]==0&&neighbours[j]==0)){
                            int r=row+neighbours[i];
                            int c=cols+neighbours[j];
                            if(r<board.length&&r>=0&&c<board [0].length &&c>=0&&board [r][c]>=1){
                                count++;
                            }
                        }
                    }
                }

                if(board [row][cols]==0){
                    if(count ==3)board[row][cols]=-1;
                    else board[row][cols]=0;
                }
                if(board [row] [cols]==1){
                    if(count <2)board [row] [cols] =1;
                    else if(count>3) board[row][cols]=1;
                    else {
                        board[row][cols]=2;
                    }
                }
                count=0;
            }
        }
        for (int i =0 ; i < board.length; i++) {
            for (int j =0 ; j < board [i].length; j++) {
                if(board [i] [j] ==1||board [i] [j] ==0)board [i] [j] =0;
                else board[i][j]=1;
            }
        }
    }
}
```