执行用时 :4 ms, 在所有 Java 提交中击败了99.26%的用户   
内存消耗 :41.6 MB, 在所有 Java 提交中击败了85.15%的用户  
```angelscript
class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i=0;i<9;i++) {
            if(!check(board[i])) {
                return false;
            }
            
        }
        for(int i=0;i<9;i++) {
            char[] t = new char[9];
            for(int j=0;j<9;j++) {
                t[j]=board[j][i];
            }
            if(!check(t)) {
                return false;
            }
            
        }
        for(int i=0;i<9;i+=3) {
            for(int j=0;j<9;j+=3) {
                char[] t = new char[9];
                int index = 0;
                for(int k=0;k<3;k++) {
                    for(int w=0;w<3;w++) {
                        t[index++] = board[i+k][j+w];
                    }
                }
                //System.out.println(t);
                if(!check(t)) {
                    return false;
                }
            }
        }
        return true;
    }
    private boolean check(char[] a) {
        int[] tmp = new int[10];
        for(int i=0;i<9;i++) {
            if(a[i]!='.') {
                tmp[a[i]-'0']++;
                if(tmp[a[i]-'0']>1) {
                    return false;
                }
            }
        }
        return true;
    }
}
```