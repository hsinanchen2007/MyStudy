![LeetCode1001.jpg](https://pic.leetcode-cn.com/72951758502f718ff5fc472497d8cf6d2525ef7c6b998ac9dd47be55e8e60fbb-LeetCode1001.jpg)

# 思路
每一盏灯会影响到四个方向（横、竖、两条对角线），横、竖比较简单，就是row相等或col相等。两条对角线的规律是处在同一左对角线上是row+col相等，处在同一右对角线上的是row-col相等。因此，这里就可以定义4个map，key分别是row，col，row+col, row-col, value为某网格被照亮的次数（即可能被灯1照亮，可能被灯2照亮，只要照亮次数>=1，那么当前网格就是亮的）。后面询问完，有灭灯的操作，就把相应的次数减一即可。至于灭灯操作其实也比较简单，即遍历一遍3*3网格，看对应网格是否有灯，有灯就灭掉。具体代码如下：

```java
    private static final long MAX_NUM = 1000000000L;

    private Map<Integer, Integer> rowMap = new HashMap<>();
    private Map<Integer, Integer> columnMap = new HashMap<>();
    private Map<Integer, Integer> sumMap = new HashMap<>();
    private Map<Integer, Integer> rowColDiffMap = new HashMap<>();

    // 标记某些位置是否有灯，1000000000L * row + col
    private Set<Long> lampSet = new HashSet<>();

    private void setFlagMap(Map<Integer, Integer> flagMap, int key) {
        if (flagMap.containsKey(key)) {
            flagMap.put(key, flagMap.get(key) + 1);
        } else {
            flagMap.put(key, 1);
        }
    }

    private void minusFlagMapCount(Map<Integer, Integer> flagMap, int key) {
        flagMap.put(key, flagMap.get(key) - 1);
    }

    private void closeNeighborLamp(int row, int col) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newRow = row + i;
                int newCol = col + j;
                if (newRow < 0 || newCol < 0) {
                    continue;
                }

                long lamp = MAX_NUM * newRow + newCol;
                if (lampSet.contains(lamp)) {
                    lampSet.remove(lamp);
                    minusFlagMapCount(rowMap, newRow);
                    minusFlagMapCount(columnMap, newCol);
                    minusFlagMapCount(sumMap, newRow + newCol);
                    minusFlagMapCount(rowColDiffMap, newRow - newCol);
                }
            }
        }
    }

    public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
        int queryCount = queries.length;
        if (queryCount == 0) {
            return new int[]{};
        }

        for (int[] lamp : lamps) {
            int row = lamp[0];
            int col = lamp[1];
            int sum = row + col;
            int rowColDiff = row - col;
            setFlagMap(rowMap, row);
            setFlagMap(columnMap, col);
            setFlagMap(sumMap, sum);
            setFlagMap(rowColDiffMap, rowColDiff);
            lampSet.add(MAX_NUM * row + col);
        }

        int[] ansArr = new int[queryCount];
        int count = 0;

        for (int[] query : queries) {
            int row = query[0];
            int col = query[1];
            int sum = row + col;
            int rowColDiff = row - col;

            if (rowMap.containsKey(row) && rowMap.get(row) >= 1 ||
                    columnMap.containsKey(col) && columnMap.get(col) >= 1 ||
                    sumMap.containsKey(sum) && sumMap.get(sum) >= 1 ||
                    rowColDiffMap.containsKey(rowColDiff) && rowColDiffMap.get(rowColDiff) >= 1
            ) {
                ansArr[count++] = 1;
            } else {
                ansArr[count++] = 0;
            }

            // 关掉当前询问位置和周围相邻8个位置的灯
            closeNeighborLamp(row ,col);
        }

        return ansArr;
    }

```
# 复杂度分析
假设灯的个数为N，询问次数为M，那么
时间复杂度为O(N+M)
空间复杂度为O(N+M)