
### 题目
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

 

### 示例 1

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
### 示例 2

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false

### 解题思路
思路：回溯法
    board矩阵中所有点作为起点，然后依据这个点进行向四个方向的递归；在递归中，不满足题目的条件会自动出栈回到上一个状态，继续再找这个符合条件的格子的四周是否存在符合条件的格子，直到k到达末尾或者不满足递归条件就停止.

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        int rows = board.length;
        int cols = board[0].length;
        char[] words = word.toCharArray();
        if(board == null || rows < 1 || cols < 1 || word == null){
            return false;
        }
        int[] visited = new int[rows*cols];//标记是否访问过
        
        int k = 0;
        ///循环遍历矩阵，找到起点等于str第一个元素的值，再递归判断四周是否有符合条件的格子
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(hasPathCore(board,rows,cols,row,col,words,k,visited)){
                    return true;
                }
            }
        }
        return false;
    }

    boolean hasPathCore(char[][] matrix,int rows,int cols,int i,int j,char[] str,int k,int[] visited){
    
       int index = i * cols + j;//矩阵对应的下标
    
       if(i>=rows || i< 0 || j>= cols || j< 0 || matrix[i][j]!=str[k] || visited[index]==1){
            return false;
       } 
      
       if(k == str.length - 1) return true;//字符串已经查找结束，说明找到该路径了
       visited[index] = 1;//标记访问过

       //向四个方向【向左，向右，向上，向下】进行递归查找
       if(hasPathCore(matrix, rows, cols, i - 1, j,     str, k + 1, visited)
          ||hasPathCore(matrix, rows, cols, i + 1, j,     str, k + 1, visited)
          ||hasPathCore(matrix, rows, cols, i,     j - 1, str, k + 1, visited)
          ||hasPathCore(matrix, rows, cols, i,     j + 1, str, k + 1, visited)){
            return true;
        }

        visited[index] = 0;
        return false;
    }
}
```