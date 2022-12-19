```
class Solution {
    public int countBattleships(char[][] b) {
        int rs = 0;
        for(int r = 0; r < b.length; ++ r) {
            for(int c = 0; c < b[0].length; ++ c) {
                if(b[r][c] == 'X') {
                    rs ++;
                    // 垂直
                    if(r > 0 && b[r - 1][c] == 'X'
                    || r < b.length - 1 && b[r + 1][c] == 'X') {
                        //System.out.println("垂直" + r + ", " + c);
                        int d = r - 1, u = r + 1;
                        while(d >= 0 && b[d][c] == 'X') {
                            b[d --][c] = '.';
                            //System.out.println("变变变hh");
                        }
                        while(u < b.length && b[u][c] == 'X') {
                            b[u ++][c] = '.';
                            //System.out.println("变变变");
                        }
                    } 
                    // 水平
                    else {
                        //System.out.println("垂直");
                        int l = c - 1, rt = c + 1;
                        while(l >= 0 && b[r][l] == 'X') {
                            b[r][l --] = '.';
                        }
                        while(rt < b[0].length && b[r][rt] == 'X') {
                            b[r][rt ++] = '.';
                        }
                    } 
                    b[r][c]  = '.';
                }
            }
        }
        return rs;
    }
}
```
