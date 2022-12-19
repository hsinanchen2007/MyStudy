执行用时 :1 ms, 在所有 Java 提交中击败了99.74%的用户
内存消耗 :39.1 MB, 在所有 Java 提交中击败了97.18%的用户

### 解题思路
通过观察,点与点之间走的距离是x1-x2和y1-y2中间的较大绝对值.
注意索引不要超出范围.

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int result = 0;
        for(int i = 0; i < points.length - 1;i++){
            int x = points[i+1][0] - points[i][0];
            int y = points[i+1][1] - points[i][1];
            x = x > 0 ? x:-x;
            y = y > 0 ? y:-y;
            result += Math.max(x,y);
        }
            return result;
    }
}
```