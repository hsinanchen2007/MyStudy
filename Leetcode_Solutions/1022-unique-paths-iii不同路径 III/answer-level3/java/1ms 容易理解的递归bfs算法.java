```
private final int[][] steps = new int[][]{{1, 0},{0, 1},{0, -1},{-1, 0}};
    public int uniquePathsIII(int[][] grid) {
        int[] src = new int[2];
        int[] dst = new int[2];
        int visit = 0;
        int col = grid[0].length;
        int row = grid.length;
        int validSteps = 0;
        for (int i = 0;i < grid.length;i++) {
            for (int j = 0;j < grid[0].length;j++) {
                switch (grid[i][j]) {
                    case 0:
                        validSteps++;
                        break;
                    case 1:
                        validSteps++;
                        src[0] = i;
                        src[1] = j;
                        break;
                    case -1:
                        visit = setVisit(visit, i, j, col);
                        break;
                    case 2:
                        visit = setVisit(visit, i, j, col);
                        dst[0] = i;
                        dst[1] = j;
                        break;
                }
            }
        }
        return findPath(visit, src[0], src[1], row, col, dst, 0, validSteps);
    }

    private boolean isVisit(int visit, int i, int j, int col) {
        return (visit & (0x01 << (i * col + j))) != 0;
    }

    private int setVisit(int visit, int i, int j, int col) {
        return (visit | (0x01 << (i * col + j)));
    }

    int findPath(int visit, int i, int j, int r, int c, int[] dst, int pathLen, int dstLen) {
        if (pathLen == dstLen) {
            if (i == dst[0] && j == dst[1]) {
                return 1;
            } else {
                return 0;
            }
        }
        if (i < 0 || j < 0 || i >= r || j >= c || isVisit(visit, i, j, c)) {
            return 0;
        }
        int newVisit = setVisit(visit, i, j, c);
        int sum = 0;
        for (int s = 0;s < steps.length;s++) {
            sum += findPath(newVisit, i + steps[s][0], j + steps[s][1], r, c, dst, pathLen+1, dstLen);
        }
        return sum;
    }
```
