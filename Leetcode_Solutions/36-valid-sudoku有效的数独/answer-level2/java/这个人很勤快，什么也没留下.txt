执行用时 :2 ms, 在所有 java 提交中击败了98.31% 的用户
内存消耗 :41.8 MB, 在所有 java 提交中击败了84.26%的用户
```
class Solution {
    public boolean verify(char[][] board,int i,int j){
        int[] num = new int[9];
        
        for(int g = i; g < i + 3; g++){
            for(int h = j; h < j + 3; h++){
                char ch = board[g][h];
                if(ch == '.'){}
                else if(num[ch - '1'] != 0)
                    return false;
                else num[ch - '1']++; 
            }
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
        
        for(int i = 0; i < 9; i++){
            int[] numsRow = new int[9];
            int[] numsCol = new int[9];
            
            for(int j = 0; j < 9; j++){
                char charRow = board[i][j];
                char charCol = board[j][i];
                int numRow = charRow - '1';
                int numCol = charCol - '1';
                if(charRow == '.'){}
                else if(numsRow[numRow] != 0)
                    return false;
                else numsRow[numRow]++;
                
                if(charCol == '.'){}
                else if(numsCol[numCol] != 0)
                    return false;
                else numsCol[numCol]++;
            }
        }
        if(verify(board,0,0) == false)
            return false;
        if(verify(board,0,3) == false)
            return false;
        if(verify(board,0,6) == false)
            return false;
        if(verify(board,3,0) == false)
            return false;
        if(verify(board,3,3) == false)
            return false;
        if(verify(board,3,6) == false)
            return false;
        if(verify(board,6,0) == false)
            return false;
        if(verify(board,6,3) == false)
            return false;
        if(verify(board,6,6) == false)
            return false;
        
        return true;
    }
}
```
