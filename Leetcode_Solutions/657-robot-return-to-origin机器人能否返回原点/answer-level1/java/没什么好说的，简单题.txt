```
class Solution {
    public boolean judgeCircle(String moves) {
        int uc = 0, lc = 0, rc = 0, dc = 0;
        for(int i = 0; i < moves.length(); ++ i) {
            switch(moves.charAt(i)) {
                case 'U':
                    uc ++;
                    break;
                case 'D':
                    dc ++;
                    break;
                case 'R':
                    rc ++;
                    break;
                case 'L':
                    lc ++;
                    break;
                default:
                    break;
            }
        }
        return uc == dc && lc == rc;
    }
}



```
