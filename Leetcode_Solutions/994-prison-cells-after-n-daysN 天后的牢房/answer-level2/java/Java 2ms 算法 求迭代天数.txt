
只需和第一天比较，无需使用Set存下所有情况，因此用一个hashCode搞定
使用list存储之前的状态
```
    class Solution2 {

        int CELL_NUMS = 8;

        public int[] prisonAfterNDays(int[] cells, int N) {
            // D-1天内的牢房情况
            List<int[]> cellsStatusList = new ArrayList<>();
            // 存第一天的牢房情况
            int firstCellStatus = 0;

            for (int d = 0; d < N; d++) {
                cells = trans(cells);
                int hashCode = Arrays.hashCode(cells);
                // 如果是第一天，记录下情况即可
                if (d == 0) {
                    firstCellStatus = hashCode;
                    cellsStatusList.add(cells);
                    continue;
                }

                if (firstCellStatus != hashCode) {
                    // 如果hashCode不相等，说明未出现循环，将情况录入Map
                    cellsStatusList.add(cells);
                } else {
                    // 如果hashCode相等，说明循环出现，后面的数便不需要算了，直接从前面取结果即可
                    int repeatDay = d;
                    int index = N % repeatDay;
                    if (index == 0) {
                        index = repeatDay;
                    }
                    int[] ret = cellsStatusList.get(index - 1);
                    return ret;
                }
            }
            return cells;
        }

        /**
        * 转换函数
        * 复杂度为 O(1)
        *
        * @param cells
        * @return
        */
        public int[] trans(int[] cells) {
            int[] new_cells = new int[CELL_NUMS];
            for (int i = 0; i < CELL_NUMS; i++) {
                // 如果是左右两端，转换后定是0
                if (i == 0 || i == CELL_NUMS - 1) {
                    new_cells[i] = 0;
                    continue;
                }
                new_cells[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            }
            return new_cells;
        }

    }
```
