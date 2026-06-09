### 解题思路
通过观察可知，两点之间最短距离就是，|x1-x2|和|y1-y2|中的最大值
最后相关即可

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int sum=0;
        for (int i=0;i<points.length-1;i++)
            sum +=countTwo(points[i], points[i+1]);
        return sum;
    }

    int countTwo(int[] from, int[] to){
        int row = from[0] - to[0];
        int col = from[1] - to[1];
        if (row < 0) row *= -1;
        if (col < 0) col *= -1;
        return row > col ? row : col;
    }
}
```