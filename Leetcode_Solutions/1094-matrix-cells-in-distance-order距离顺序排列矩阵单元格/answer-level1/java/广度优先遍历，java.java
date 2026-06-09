### 解题思路
先说明下该题的涵义，假设下面的矩阵，给定的点是值为0的那一个点：
（1）那么离它最近的是它上下左右的4个点，即矩阵中的4个1.
（2）离它第二远的是矩阵中为2的点，即4个角加上直线距离为2的。
（3）可以发现离它第二远的点都在离它最近的点的上下左右。
（4）因此，可以用广度优先遍历的方法进行遍历。
（5）首先把根节点0放入先进先出队列，在出队，把它上下左右的点放入队列，并记录哪些已经放入过。
（6）出队放入结果中，并且把出队节点的上下左右继续入队。
4 3 2 3 4 
3 2 1 2 3 
2 1 0 1 2 
3 2 1 2 3 
4 3 2 3 4

### 代码

```java
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        LinkedList<int[]> queue = new LinkedList<>();
        queue.add(new int[]{r0, c0});
        //  记录是否已经遍历过
        boolean[][] check = new boolean[R][C];
        check[r0][c0] = true;
        // 存储结果
        int[][] ans = new int[R * C][2];
        int j = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] spot = queue.removeFirst();
                ans[j++] = spot;
                int posR = spot[0];
                int posC = spot[1];
                // 上
                if (posR + 1 >= 0 && !check[posR - 1][posC]) {
                    queue.add(new int[]{posR - 1, posC});
                    check[posR - 1][posC] = true;
                }
                // 下
                if (posR + 1 <= R - 1 && !check[posR + 1][posC]) {
                    queue.add(new int[]{posR + 1, posC});
                    check[posR + 1][posC] = true;
                }
                // 左
                if (posC - 1 >= 0 && !check[posR][posC - 1]) {
                    queue.add(new int[]{posR, posC - 1});
                    check[posR][posC - 1] = true;
                }
                //  右
                if (posC + 1 <= C - 1 && !check[posR][posC + 1]) {
                    queue.add(new int[]{posR, posC + 1});
                    check[posR][posC + 1] = true;
                }
            }
        }
        return ans;
    }
}
```