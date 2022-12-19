
```java

    /**
     * 解题思路：
     * 首先必须理解有效数独的定义
     * 要知道是否满足数独的要求，肯定所有的点都得遍历到，所以得双重遍历
     * 在双重遍历中得匹配之前的遍历结果，看是否有重复的数字，考虑用hashmap报错遍历结果
     * hashmap中存储的key是有三种：行的index+数字、列的index+数字、3*3宫格的index+数字
     *
     * 提交结果：
     * 执行用时 : 16 ms, 在Valid Sudoku的Java提交中击败了62.19% 的用户
     * 内存消耗 : 42.4 MB, 在Valid Sudoku的Java提交中击败了81.42% 的用户
     * 结果并不是很出色，看了其他优秀解法，发现他们存储是固定大小三个数组，
     * 仔细想想也是，HashMap虽然查找是O(1)，但是扩容的时候是有时间消耗的,对于这种固定大小的可以考虑用数组进行优化
     * 官方解题，是分了三个HashMap，估计也是为了减少扩容的时间消耗吧
     *
     * @param board
     * @return
     */
    public boolean isValidSudoku(char[][] board) {
        HashMap<String, Boolean> map = new HashMap<>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                char num = board[i][j];
                if (num == '.') continue;
                String rowKey = i + "row" + num;
                String colKey = j + "col" + num;
                int groupIndex = i / 3 + j / 3 * 3;
                String groupKey = groupIndex + "group" + num;
                //寻找是否有重复的数字
                if (map.getOrDefault(rowKey, false)
                        || map.getOrDefault(colKey, false)
                        || map.getOrDefault(groupKey, false)) {
                    return false;
                }
                //更新遍历记录
                map.put(rowKey, true);
                map.put(colKey, true);
                map.put(groupKey, true);
            }
        }
        return true;
    }
```