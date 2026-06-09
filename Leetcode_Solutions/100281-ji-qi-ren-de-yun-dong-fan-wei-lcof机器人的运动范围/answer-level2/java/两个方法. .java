
![image.png](https://pic.leetcode-cn.com/e4ff22c8f03124073cc14d8117459934b5b3a0e1fe2bff7bc58411d5fae44ea3-image.png)

- 一图: 满足条件区域, 二图为可走到的区域
## 方法 1 


遍历.  m x n矩阵 都设置0 横着走遍历, 每走一步向下遍历所有点. 碰到不可达则break; 三层遍历  最外层向右,第二层向下,第三层向右; 暴力破解. 会有多走的地方. 不过不会累计. 将走过的地方设置1 最后累加和

```
public int movingCount(int m, int n, int k) {
        int[][] canReach = new int[m][n];
        for (int i = 0; i < m; i++) {
            boolean reachI = i / 10 + i % 10 <= k;
            if (!reachI) {
                break;
            }
            for (int j = 0; j < n; j++) {
                boolean reach = i / 10 + i % 10 + j / 10 + j % 10 <= k;
                if (reach) {
                    canReach[i][j] = 1;
                    for (int l = i; l < m; l++) {
                        boolean reachL = l / 10 + l % 10 + j / 10 + j % 10 <= k;
                        if (reachL) {
                            canReach[l][j] = 1;
                        } else {
                            break;
                        }
                    }
                } else {
                    break;
                }
            }

        }

        int c = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                c = c + canReach[i][j];
            }
        }
        return c;
    }
```
## 方法 2 递归;
没走一步则可向四个点再走. 用boolean矩阵代表是否可走. 走完后将走过的点设置为不可走.  每走一步则累计1;
```
    public int movingCount(int m, int n, int k) {
        boolean[][] reach = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                reach[i][j] = i / 10 + i % 10 + j / 10 + j % 10 <= k;
            }
        }
        return step(0, 0, reach);
    }

    private int step(int i, int j, boolean[][] reach) {
        if (i >= 0 && j >= 0 && i < reach.length && j < reach[0].length && reach[i][j]) {
            reach[i][j] = false;
            return 1 + step(i + 1, j, reach) + step(i - 1, j, reach) + step(i, j + 1, reach) + step(i, j - 1, reach);
        } else {
            return 0;
        }
    }
```


