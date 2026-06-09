### 解法一

#### 分析：

- 如果一个服务器$(i,j)$没有任何其他和其在同行或是同列的服务器，则它应从答案中剔除
- 统计每一行的服务器数量
- 统计每一列的服务器数量
- 若在一个部署了服务器的位置$(i,j)$，第$i$行只有一个服务器且第$j$列也只有一个服务器，则说明该服务器便是$(i,j)$本身，把其从结果集中剔除。

#### 代码实现

```java []
class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] row = new int[m]; // 统计某一行的服务器数量
        int[] col = new int[n]; // 统计某一列的服务器数量
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                row[i] += 1; // 第 i 行服务器数量+1
                col[j] += 1; // 第 j 列服务器数量+1
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue; 
                // 该行该列的服务器数量只有一个（即其自身）则它无法与任何其他服务器通信
                if (row[i] == 1 && col[j] == 1) continue; 
                ans++;
            }
        }
        return ans;
    }
}

```

#### 复杂度分析
- 时间复杂度 $O(M * N)$ 其中$M$为grid的行数，$N$为grid的列数
- 空间复杂度 $O(M + N)$ 开辟的row和col数组的总和