### 解题思路
仔细读了5遍题目，才理解原题的意思。

规则就是己方（R）会吃掉与它同行或同列的对方的卒（p），题目问一个R最多有几个p可以吃。

直接按照题目意思搜索即可。

首先，找到己方的R，获得R索引i,j;

然后，分别在上下左右四个方向查找，每个方向最多1个（如果遍历到边界或者己方的象，直接返回0，遍历到某个p即返回1，p后面不管有没有，R都不能吃到它。）

最后，把四个方向的搜索结果加起来就行。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length;j++){
                if(board[i][j] == 'R'){
                    return searchUp(board, i, j)+searchDown(board, i, j)+searchLeft(board, i, j)+searchRight(board, i, j);
                }
            }
        }
        return 0;
    }
    private int searchUp(char[][] board, int i, int j){
        while(i >-1){
            if(board[i][j]=='B'){
                return 0;
            }
            else if(board[i][j]=='p'){
                return 1;
            }
            i--;
        }
        return 0;
    }
    private int searchDown(char[][] board, int i, int j){
        while(i < board.length){
            if(board[i][j]=='B'){
                return 0;
            }
            else if(board[i][j]=='p'){
                return 1;
            }
            i++;
        }
        return 0;
    }
    private int searchLeft(char[][] board, int i, int j){
        while(j >-1){
            if(board[i][j]=='B'){
                return 0;
            }
            else if(board[i][j]=='p'){
                return 1;
            }
            j--;
        }
        return 0;
    }
    private int searchRight(char[][] board, int i, int j){
        while(j < board[0].length){
            if(board[i][j]=='B'){
                return 0;
            }
            else if(board[i][j]=='p'){
                return 1;
            }
            j++;
        }
        return 0;
    }
}
```