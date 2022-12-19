### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int i=0,j=0;
        char[] cs = null;
        for (boolean noR = true; i < board.length && noR; i++){
            cs = board[i];
            for (j=0; j < board.length && cs[j] != 'R'; j++);
            if(j<board.length){
                noR=cs[j]!='R';
            }
        }
        --i;
        return east(j, cs) + west(j, cs) + south(i, j, board) + north(i, j, board);
    }

    // 东
    public int east(int j, char[] cs){
        while(++j < cs.length && cs[j] == '.');
        return j<cs.length?(cs[j]=='B'?0:1):0;
    }

    // 西
    public int west(int j, char[] cs){
        while(--j > -1 && cs[j] == '.');
        return j>-1?(cs[j]=='B'?0:1):0;
    }

    // 南
    public int south(int i, int j, char[][] cs){
        while(++i < cs.length && cs[i][j] == '.');
        return i<cs.length?(cs[i][j]=='B'?0:1):0;
    }

    // 北
    public int north(int i, int j, char[][] cs){
        while(--i > -1 && cs[i][j] == '.');
        return i>-1?(cs[i][j]=='B'?0:1):0;
    }
}
```