```
class Solution {
    public boolean isValidSudoku(char[][] board) {
        char[] c = new char[9];//存列的值
        char[][] t = new char[3][9];
        for(int i = 0; i < 9; i++){
            if(!distinctChar(board[i])) return false;//判断某行是否满足要求
            for(int f = 0 ;f < 9 ; f ++){
                //填充纵轴
                c[f] = board[f][i];
                //填充3x3的块
                t[f/3][(f % 3) + (i % 3) * 3] = board[i][f];
                if((i + 1) % 3 == 0 && (f + 1) % 3 == 0){//点也就是横轴纵轴分别都为2、5、8等点时表示已经遍历完某3x3块，可以进行校验
                    if(!distinctChar(t[f / 3])) return false;//判断某块是否满足要求
                }
            }
            if(!distinctChar(c)) return false;//判断某列是否满足要求
        }
        return true;
    }
    
    public boolean distinctChar(char[] board){
        StringBuilder sb =new StringBuilder();
        for(char c : board){
            if(c != '.'){
                if(sb.indexOf(c+"") != -1) return false;
                sb.append(c);
            }
        }
        return true;
    }
}
```
