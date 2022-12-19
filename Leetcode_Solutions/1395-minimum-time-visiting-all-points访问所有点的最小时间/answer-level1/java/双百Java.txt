### 解题思路
题干比较长，用的的理论知识应该初高中水平，静下心来可以推演出来，用迭代搞定。
看了题解才知道这个理论的名称叫切比雪夫距离，对这个名词还是有印象的，瞬间回到十几年前，哈哈哈，以前学的都交给老师了。

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int result = 0;
        for (int i = 0; i < points.length - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];
            result += Math.max(Math.abs(x2 - x1), Math.abs(y2 - y1));
        }
        return result;
    }
}
```