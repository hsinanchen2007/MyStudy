```java
class Solution {
    public int minCostToMoveChips(int[] chips) {
        int[] magic = new int[2];
        for (int chip :
                chips) {
            magic[chip&1]++;
        }
        return magic[0]<magic[1]?magic[0]:magic[1];
    }
}
```
