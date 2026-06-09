### 解题思路
深度优先遍历方法，同时使用blockGrid数组记录包含i、j的路径是否能继续向下寻找，当包含i、j的路径不能找到合适的完整径路时，直接放弃搜索。

- 当obstacleGrid[i][j] == 0 && i == xLen - 1 && j == yLen - 1时，找到路径递归结束，返回true，否则返回false；
- 当i + 1 < xLen && blockGrid[i + 1][j] != 1时，向下走nextStep(i + 1, j)；
- 当向下走寻路失败且j + 1 < yLen && blockGrid[i][j + 1] != 1时，向右走nextStep(i, j + 1)；
- 当向下走和向右走都失败时，令blockGrid[i][j] = 1，即包含i、j的路径不能找到合适的完整径路，并返回false；

### 代码

```java
class Solution {
    int xLen, yLen;
    int xTop = -1, yTop = -1;
    int[] xStack, yStack;
    int[][] obstacleGrid;
    int[][] blockGrid;

    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null || obstacleGrid.length == 0) {
            return new ArrayList<List<Integer>>();
        }

        this.obstacleGrid = obstacleGrid;
        int len = obstacleGrid.length + obstacleGrid[0].length - 1;
        xLen = obstacleGrid.length;
        yLen = obstacleGrid[0].length;
        this.blockGrid = new int[xLen][yLen];
        xStack = new int[len];
        yStack = new int[len];

        boolean b = nextStep(0, 0);

        List<List<Integer>> lists = new ArrayList<List<Integer>>();
        for (int i = 0; i < len && b; i++) {
            List<Integer> list = new ArrayList<Integer>();
            list.add(xStack[i]);
            list.add(yStack[i]);
            lists.add(list);
        }

        return lists;
    }

    public boolean nextStep(int i, int j) {
        boolean b = false;
        if (this.obstacleGrid[i][j] == 0) {
            if (this.blockGrid[i][j] != 1) {
                this.blockGrid[i][j] = 0;
            }

            xStack[++xTop] = i;
            yStack[++yTop] = j;
            if (i == xLen - 1 && j == yLen - 1) {
                return true;
            }

            if (i + 1 < xLen && this.blockGrid[i + 1][j] != 1) {
                b = nextStep(i + 1, j);
            }
            if (!b && j + 1 < yLen && this.blockGrid[i][j + 1] != 1) {
                b = nextStep(i, j + 1);
            }
            if (!b) {
                this.blockGrid[i][j] = 1;
                xTop--;
                yTop--;
            }
        }

        return b;
    }
}
```