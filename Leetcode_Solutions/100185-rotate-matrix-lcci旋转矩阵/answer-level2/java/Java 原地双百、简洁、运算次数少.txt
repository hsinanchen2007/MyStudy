### 思路
从最外圈往内一圈圈旋转即可。

```java
    public void rotate(int[][] grid) {
        // s代表当前圈的行或列的起始索引
        // e代表当前圈的行或列的终止索引
        // 当N为奇数的时候，从外圈往内，最终到达了中心点的时候s=e而跳出循环
        // 当N为偶数的时候，从外圈往内，最终全部都处理完之后s>e而跳出循环
        for (int s = 0, e = grid.length - 1; s < e; s++, e--) {
            for (int j = s; j < e; j++) {
                int tmp = grid[s][j];
                grid[s][j] = grid[e - (j - s)][s];
                grid[e - (j - s)][s] = grid[e][e - (j - s)];
                grid[e][e - (j - s)] = grid[j][e];
                grid[j][e] = tmp;
            }
        }
    }
```

### 复杂度分析
- 时间复杂度：$O(N*N)$
- 空间复杂度：$O(1)$
