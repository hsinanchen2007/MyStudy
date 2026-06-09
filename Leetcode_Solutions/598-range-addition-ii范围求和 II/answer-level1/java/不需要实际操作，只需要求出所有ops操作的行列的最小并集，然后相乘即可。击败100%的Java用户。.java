### 解题思路
仔细分析就可以发现，所谓ops操作就是把当前坐标的左上部分区域+1。
由此可以知道，所有ops操作都会涉及原始矩阵的最左上角的[0][0]这个元素，也就说最后的最大元素就是[0][0]。
那么现在需要求解的就是，最终会有多少元素会与[0][0]相同？这个很容易就可以知道，如果某个元素，在每次操作中都会涉及，那么它的值就会和[0][0]相同。
那么有多少元素，会在每次操作中都会被涉及？这就是所有ops操作的行列的最小并集，然后行列相乘即可。

### 代码

```java
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        int minRow = m;
        int minCol = n;
        for(int i = 0; i < ops.length; i++) {
            if (ops[i][0] < minRow) {
                minRow = ops[i][0];
            };
            if (ops[i][1] < minCol) {
                minCol = ops[i][1];
            };
        };
        return minRow * minCol;

    }
}
```