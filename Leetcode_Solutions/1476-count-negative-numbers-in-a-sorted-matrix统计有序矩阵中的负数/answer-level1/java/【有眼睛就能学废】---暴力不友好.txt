### 解题思路
最直接的暴力解题方法。
遍历数组中的每一个元素，如果元素是负数，则统计数量加一。
数组遍历完毕，最后得出统计结果。


### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        if(grid == null|| grid.length == 0) {
            return 0;
        }
        int count = 0;
        for (int[] sub : grid) {
            if (sub.length == 0) {
                continue;
            }
            for (int num : sub) {
                if (num < 0) {
                    count++;
                }
            }
        }
        return count;
    }
}
```