```
class Solution {
    public int minCostToMoveChips(int[] chips) {
        int[] f = new int[2];
        for(int c : chips){
            f[c%2]++;
        }
        return Math.min(f[0], f[1]);
    }
}	
```
