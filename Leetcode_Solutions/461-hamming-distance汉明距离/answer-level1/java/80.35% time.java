```
class Solution {
    public int hammingDistance(int x, int y) {
        int res = 0;
        for(int i = 0; i < 32 && (x > 0 || y > 0); ++ i) {
            if(((x % 2) ^ (y % 2)) == 1)
                res ++;
            //System.out.println(Integer.toBinaryString(x) + ", " + Integer.toBinaryString(y));
            x >>= 1;
            y >>= 1;
        }
        return res;
    }
}
```
