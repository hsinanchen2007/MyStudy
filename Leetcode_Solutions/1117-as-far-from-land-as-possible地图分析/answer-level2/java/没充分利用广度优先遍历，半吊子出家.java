### 解题思路
此处撰写解题思路
题目要求找到每个海洋离陆地距离的最小值，再在所有的最小值中找到最大值。
所以可以分成好几步：
1. 找到所有的海洋
2. 遍历每一个海洋，去寻找离他最近的陆地距离，然后记录下来，有一个海洋就记录一个最近的距离
3. 在所有最近距离中，找到最大值（当然也可以在第二步中边遍历边寻找最大值），这个最大值就是我们要找的值
### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        // 寻找所有的海洋
        List<Integer[]> seaList = findSea(grid);
        int allpoint = grid.length * grid.length;
        // 全是陆地或者全是海洋，则返回-1
        if (seaList.isEmpty() || seaList.size() == allpoint) {
            return -1;
        }
        int max = 0;
        for (Integer[] sea : seaList) {
            // 遍历每一个海洋，找到离它最近的陆地的距离
            int dis = findMinLoad(sea, grid);
            // 寻找最大的距离
            if (dis > max) {
                max = dis;
            }
        }
        return max;
    }

    public int findMinLoad(Integer[] sea, int[][] grid) {
        int seaI = sea[0];
        int seaJ = sea[1];
        boolean find = false;
        // 寻找的步数，就是海洋到陆地的距离
        int step = 1;
        while (!find) {
            // 向上下左右扩散，（但是会包含角落，会重复扫描。
            // 距离不等于step的，矩阵越大，多扫描的点越多）
            for (int i = seaI - step; i <= seaI + step; i++) {
                if (find) {
                    break;
                }
                if (i < 0) {    // 最左边不能超限
                    continue;
                }
                if (i >= grid[0].length) {     // 最右边不能超限
                    break;
                }
                for (int j = seaJ - step; j <= seaJ + step; j++) {
                    if (j < 0) {
                        continue;
                    }
                    if (j >= grid.length) {
                        break;
                    }
                    // 寻找陆地，并且计算距离等于step的
                    if (grid[i][j] == 1 && calcDis(i, j, seaI, seaJ) == step) {
                        find = true;
                        break;
                    }
                }

            }
            if (find) {
                break;
            }
            // 如果没有找到，step加一，扩大寻找范围
            step++;

        }
        return step;
    }

    public int calcDis(int i, int j, int seaI, int seaJ) {
        return Math.abs(i - seaI) + Math.abs(j - seaJ);
    }

    public List<Integer[]> findSea(int[][] grid) {
        List<Integer[]> seaList = new ArrayList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 0) {
                    Integer[] pos = new Integer[]{i, j};
                    seaList.add(pos);
                }
            }
        }
        return seaList;
    }
}
```