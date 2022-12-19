### 解题思路
记录上一次房子刷不同颜色的最小花费，然后将当前房子刷不同颜色的最小花费算出来，遍历完成后取最小的花费即可。

### 代码

```java
class Solution {
    public int minCost(int[][] costs) {
        if (costs.length == 0) {
            return 0;
        }
        int lastRedCost = costs[0][0];
        int lastBlueCost = costs[0][1];
        int lastGreenCost = costs[0][2];
        for (int i = 1; i < costs.length; i++) {
            int[] colorCosts = costs[i];
            int currentRedCost = colorCosts[0] + Math.min(lastBlueCost, lastGreenCost);
            int currentBlueCost = colorCosts[1] + Math.min(lastRedCost, lastGreenCost);
            int currentGreenCost = colorCosts[2] + Math.min(lastRedCost, lastBlueCost);
            lastRedCost = currentRedCost;
            lastBlueCost = currentBlueCost;
            lastGreenCost = currentGreenCost;
        }
        
        return Math.min(lastRedCost, Math.min(lastBlueCost, lastGreenCost));
    }
}
```