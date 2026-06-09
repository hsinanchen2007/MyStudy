### 解题思路
在看了细胞生存工作后，觉得对于整个矩阵最特殊的就是边边的行和列。这些特殊的元素和矩阵中其他内嵌(自己取的名字，代表周围的8个值都存在)元素是不一样的，如果也对搜索这些特殊元素周围的8个值的话可能会出现越界的情况。所以准备直接检索board，找到这些特殊的元素，对特殊元素和内嵌元素分别使用不同的判断8值方法，说白了就是对于特殊元素判断的时候，控制索引值，防止数组越界。然后我就开始写写……

写了一会会发现，哇，顶点的元素更特殊！对于边边的行和列还要重新判断元素是不是顶点，如果按照之前的方法就还需要编写新的防止对顶点的操作越界的方法，而且四个顶点还不一样……，这是也发现上下左右的边边也不能使用相同的防止数组越界的方法进行8值判断。好麻烦……

这时候，统一就很重要了，天下总要归为一统。

对于这些特殊的顶点和边边，它们没有邻居怎么办，当然是没有条件就要创造条件，给它们加邻居！这样原来特殊的元素就变成之前的内嵌元素。我们就可以使用相同的8值搜索方法。

对于邻居为什么加的是0，不是1，是因为一开始我用0试了试发现不会改变结果。现在想想可以不用试的，因为生存条件里主要统计的就是活细胞(1)，所以1的存在是会影响结果的。

PS:
本来我是想把8值搜索抽成函数来调用，准备传入new_board, i, j, 返回8值中1的个数。但是我二维数组传值并未成功。求大神赐教:)!

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int new_row = boardSize +2;
    int new_col = *boardColSize+2;
    int new_board[new_row][new_col];
    //把board的元素填入new_board，新加的邻居设为0
    for(int i=0; i<new_row; i++) {
        for(int j=0; j<new_col; j++) {
            if(i>=1 && i<= boardSize && j>=1 && j<=*boardColSize) {
                new_board[i][j] = board[i-1][j-1];
            } else {
                new_board[i][j] = 0;
            }
        }
    }
    //检索new_board中填入的board
    for(int i=1; i<=boardSize; i++){
        for(int j=1; j<=*boardColSize; j++){
            if(new_board[i][j]==0){
                int cont1 = 0;
                for(int m=i-1; m<=i+1; m++) {
                     for(int n=j-1; n<=j+1; n++) {
                         if(new_board[m][n]==1) {
                              cont1++;
                        }
                     }
                }
                if(cont1==3){
                    board[i-1][j-1]=1;
                }
            }else{
                int cont2 = -1;  //-1是因为下面的循环计算中会加上本来的那个1
                for(int m=i-1; m<=i+1; m++) {
                     for(int n=j-1; n<=j+1; n++) {
                         if(new_board[m][n]==1) {
                                 cont2++;
                        }
                     }
                }
                if(cont2<2 || cont2>3){
                    board[i-1][j-1]=0;
                }
            }
        }
    }
}
```