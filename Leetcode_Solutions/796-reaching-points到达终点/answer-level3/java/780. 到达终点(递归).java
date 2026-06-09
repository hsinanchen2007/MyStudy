执行用时 :1 ms, 在所有 java 提交中击败了84.13%的用户
内存消耗 :33.1 MB, 在所有 java 提交中击败了90.00%的用户
```
class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx > ty)
            return reachingPoints(sy, sx, ty, tx);
        if(sx == tx && sy == ty)
            return true;
        if(sx > tx || sy > ty)
            return false;
        if(sx == tx){
            if((ty - sy) % sx == 0)
                return true;
            return false;
        }
        return reachingPoints(sy, sx, ty % tx, tx);
    }
}
```
