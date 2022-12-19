```
class Solution {
    public int hammingDistance(int x, int y) {
        int dis = 0;
        for(int i=0; i<32; i++) {
           dis += ((x >> i) & 1 ) ^ ((y >> i) &1);
        }
        return dis;
    }
}
```