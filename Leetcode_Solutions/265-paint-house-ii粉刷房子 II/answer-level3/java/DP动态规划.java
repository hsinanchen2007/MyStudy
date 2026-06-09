```
class Solution {
    public int minCostII(int[][] costs) {
        if (costs.length == 0 || costs[0].length == 0) return 0;
        int n = costs.length, k = costs[0].length;
        if (n == 0 || k == 0) return 0;
        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE, minIdx = -1;
        for (int j=0; j<k; j++) {
            if (costs[0][j] < first) {
                second = first;
                first = costs[0][j];
                minIdx = j;
            } else if (costs[0][j] < second)
                second = costs[0][j];
        }
        for (int i=1; i<n; i++) {
            int tmpFirst = first, tmpSecond = second, tmpMinIdx = minIdx;
            first = Integer.MAX_VALUE; second = Integer.MAX_VALUE; minIdx = -1;
            for (int j=0; j<k; j++) {
                int val = j == tmpMinIdx ? costs[i][j] + tmpSecond : costs[i][j] + tmpFirst;
                if (val < first) {
                    second = first;
                    first = val;
                    minIdx = j;
                } else if (val < second)
                    second = val;
            }
        }
        return first;
    }
}
```
