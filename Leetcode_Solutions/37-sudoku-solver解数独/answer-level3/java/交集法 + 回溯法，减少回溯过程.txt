![5a7856c3c2a2185600b7cb5cd3fd50101281af7391a70a63293d82d62873aadd-36_boxes_2.png](https://pic.leetcode-cn.com/f45cefc57c1263ae6281eed4b45626e3f0aa8e8bec6a826a57a7f68943330f51-5a7856c3c2a2185600b7cb5cd3fd50101281af7391a70a63293d82d62873aadd-36_boxes_2.png)

题目求解思路不难，就是要用回溯法，但是回溯试错的成本太高，要找寻一些方法减少回溯试错的次数。

## 数独划分
首先，题目中的数独规则就将自身划分为了三个层面：9行、9列、9个大格子
我们假设行索引是`i`，列索引是`j`，大格子索引是`k`。
那么，大格子的索引计算方式为：
```
k = (i / 3) * 3 + j / 3
```

## 数独求解思路
给定一个数独，我们可以轻易看出：第`i`行的可选数字，第`j`列的可选数字，第`k`个大格子的可选数字。

##### 交集法（随便取的名字）
如果位置`(i,j,k)`可选数字的交集是唯一的，那么唯一的交集数字就是位置`(i,j,k)`的解。同时，第`i`行、第`j`列、第`k`个大格子，它们的可选数字都会减少一个。
运气好的话，不断的遍历数独，运用“交集法”可以很快求解出数独的解，遍历次数最多就是空白小格子的数量，不超过`9 * 9 = 81`次。
但是运气通常不会那么好，还有这样一种场景，每一个位置`(i,j,k)`交集数字都是多个，这种情况下交集法就歇菜了，因为没有唯一的确定解。

##### 回溯法
回溯，就是挨个尝试每个位置`(i,j,k)`的可能选择，直到求解出最终解。

##### 交集法 + 回溯法
单纯使用交集法，可以很快求解出某个位置`(i,j,k)`的解，但是有无法求解的可能。
单纯使用回溯法，每个位置不断的尝试，试错返回再继续的次数又太多了。
那么，就将两者结合起来使用：
1. 先用交集法快速求解出一些位置`(i,j,k)`的确定解，减少数独的空白小格子。
2. 交集法遇到无法求解的时候，就用回溯法假设一个位置`(i,j,k)`的解，然后继续用交集法求解。

解题的核心思路就是要减少回溯过程，而交集法就是选择之一。

## 代码技巧

主要就是利用二进制表示各种含义，定义数字`1~9`分别对应二进制数值：
```
1 = 1
2 = 10
3 = 100
4 = 1000
5 = 10000
6 = 100000
7 = 1000000
8 = 10000000
9 = 100000000
```

1、第`i`行的所有可选数字就可以用二进制数值相加的结果表示（第`j`列、第`k`个大格子同理），比如，可选数字有`1,3,4,8,9`
```
1 + 100 + 1000 + 10000000 + 100000000 = 110001101
```

2、位置`(i,j,k)`取交集数字就是三个二进制进行`&`操作，例如，第`i`行可选`1,2,3`、第`j`列可选`2,4`、第`k`个大格子可选`2,5`，那么：
```
111 & 1010 & 10010 = 10
```
位置`(i,j,k)`可选数字就是确定的`2`，如果交集结果中有多个`1`，说明位置`(i,j,k)`的可选数字不止一个，无法确定唯一解。

3、要去掉位置`(i,j,k)`的某个可选数字，减去该数字的二进制数值就可以了，比如从`1,2,3`中去掉`2`：
```
111 - 10 = 101
```

## 完整代码实现
```
public class Solution {

    // 数字对应二进制
    private static Map<Integer, Character> dict = new HashMap<Integer, Character>() {{
        put(1 << 0, '1');
        put(1 << 1, '2');
        put(1 << 2, '3');
        put(1 << 3, '4');
        put(1 << 4, '5');
        put(1 << 5, '6');
        put(1 << 6, '7');
        put(1 << 7, '8');
        put(1 << 8, '9');
    }};

    // 初始化数独结构
    private void init(char[][] board, int[] rows, int[] columns, int[] boxes, List<Integer[]> list) {
        Arrays.fill(rows, (1 << 9) - 1);
        Arrays.fill(columns, (1 << 9) - 1);
        Arrays.fill(boxes, (1 << 9) - 1);
        for (int i = 0; i < board.length; i++) {
            char[] chars = board[i];
            for (int j = 0; j < chars.length; j++) {
                int k = (i / 3) * 3 + j / 3;
                char ch = chars[j];
                if (ch != '.') {
                    int num = ch - 48 - 1;
                    rows[i] -= 1 << num;
                    columns[j] -= 1 << num;
                    boxes[k] -= 1 << num;
                } else {
                    list.add(new Integer[]{i, j, k});
                }
            }
        }
    }

    // board[i][j]有解以后，对应的i行j列k格就都能排除一个可选值
    private void setBoard(char[][] board, int i, int j, int k, char number, int[] rows, int[] columns, int[] boxes) {
        board[i][j] = number;
        int num = number - 48 - 1;
        rows[i] -= 1 << num;
        columns[j] -= 1 << num;
        boxes[k] -= 1 << num;
    }

    // 交集法
    private List<Integer[]> filling(char[][] board, int[] rows, int[] columns, int[] boxes, List<Integer[]> list) {
        while (true) {
            int size = list.size();
            Iterator<Integer[]> iterator = list.iterator();
            while (iterator.hasNext()) {
                Integer[] arr = iterator.next();
                int i = arr[0], j = arr[1], k = arr[2];
                int num = rows[i] & columns[j] & boxes[k];
                if (num == 0) return null;// 可以判定无解
                Character character = dict.get(num);
                if (character != null) {
                    setBoard(board, i, j, k, character, rows, columns, boxes);
                    iterator.remove();
                }
            }
            if (list.size() == size) return list;// size == 0 交集法解题完毕 || size > 0 交集法无解了
        }
    }

    // 回溯法
    private boolean recursion(char[][] board, int[] rows, int[] columns, int[] boxes, List<Integer[]> list) {
        List<Integer[]> integers = filling(board, rows, columns, boxes, list);
        if (integers == null) return false;// 无解
        if (integers.isEmpty()) return true;// 填充完毕
        // 选择尚未求解的一个位置，用回溯思想挨个尝试
        Integer[] target = integers.get(0);
        list.remove(target);
        int i = target[0], j = target[1], k = target[2];
        int num = rows[i] & columns[j] & boxes[k];
        for (char c = '1'; c <= '9' && num != 0; c++, num >>= 1) {
            if ((num & 1) == 1) {
                int[] cloneRows = rows.clone();
                int[] cloneColumns = columns.clone();
                int[] cloneBoxes = boxes.clone();
                List<Integer[]> cloneList = new LinkedList<>(list);
                setBoard(board, i, j, k, c, cloneRows, cloneColumns, cloneBoxes);
                if (recursion(board, cloneRows, cloneColumns, cloneBoxes, cloneList)) return true;
            }
        }
        return false;
    }

    public void solveSudoku(char[][] board) {
        int[] rows = new int[9];
        int[] columns = new int[9];
        int[] boxes = new int[9];
        List<Integer[]> list = new LinkedList<>();
        // 初始化
        init(board, rows, columns, boxes, list);
        // 交集法 + 回溯法
        recursion(board, rows, columns, boxes, list);
    }
}
```