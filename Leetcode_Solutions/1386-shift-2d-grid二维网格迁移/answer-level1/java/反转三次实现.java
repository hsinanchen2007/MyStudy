### 解题思路
![屏幕快照 2020-02-09 12.39.16.png](https://pic.leetcode-cn.com/43df91dcf108bca1b1371f51b3383af38cabbad462fc5dce5bf2a595d80edd57-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-09%2012.39.16.png)


### 代码

```java
class Solution {
    // 通过二维与一维坐标互转进行三次反转实现
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        // 计算出总长度
        int len = m * n;
        // 控制越界情况
        k = k % len;
        List<List<Integer>> res = new ArrayList<>(m);
        // 第一次将所有数值进行反转
        swap(0, len - 1, grid, n);
        // 第二次将前k个元素反转
        swap(0, k - 1, grid, n);
        // 第三次将k以后的元素反转
        swap(k , len - 1, grid, n);

        // 拼装返回结构
        for (int i = 0; i < m; i++) {
            List<Integer> list = new ArrayList<>(n);
            for (int j = 0; j < n; j++) {
                list.add(grid[i][j]);
            }
            res.add(list);
        }
        return res;
    }
    // 进行反转
    private void swap(int l, int r, int[][] arr, int n) {
        while (l < r) {
            int lx = l / n;
            int ly = l % n;
            int rx = r / n;
            int ry = r % n;
            int s = arr[rx][ry];
            arr[rx][ry] = arr[lx][ly];
            arr[lx][ly] = s;
            l++;
            r--;
        }
    }
}
```