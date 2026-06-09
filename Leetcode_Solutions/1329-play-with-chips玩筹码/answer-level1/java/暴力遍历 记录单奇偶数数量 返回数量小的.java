![image.png](https://pic.leetcode-cn.com/0d38a4b1a645aaefc374ae1727bcedc7d2eed887174f4d08ea70c7de6fc2586c-image.png)

```
class Solution {
    public int minCostToMoveChips(int[] chips) {
        Arrays.sort(chips);
        int singleNum = 0;
        int doubleNum = 0;
        for (int i = 0; i < chips.length; i++) {
            if (chips[i] % 2 == 0) {
                doubleNum++;
            } else {
                singleNum++;
            }
        }
        return Math.min(singleNum, doubleNum);
    }
}
```
