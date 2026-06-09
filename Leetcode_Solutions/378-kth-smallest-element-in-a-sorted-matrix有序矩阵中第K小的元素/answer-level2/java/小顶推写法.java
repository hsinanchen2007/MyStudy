1、因为每一行都是有序的，所以每一行的最小值（最左边）中最小一个必定是矩阵的最小值。
2、于是取出这个最小值（即整个矩阵的最小值），同时使用这一行的下一个元素参与下一次比较，可以得到矩阵中下一个最小值（即第2、3、4、……小的元素）。
3、循环上述步骤直到取到第k个最小值。

```
    /**
     * 因为每一行都是有序的，所以每一行的最小值（最左边）中最小一个必定是矩阵的最小值。
     * 取出这个最小值（即整个矩阵的最小值），同时使用这一行的下一个元素参与下一次比较。
     * 循环上述步骤直到取到第k个最小值。
     * 执行用时 :65 ms, 在所有 Java 提交中击败了14.68%的用户
     * 内存消耗 :44 MB, 在所有 Java 提交中击败了92.68%的用户
     * @param matrix
     * @param k
     * @return
     */
    public static int kthSmallest(int[][] matrix, int k) {
        int row = matrix.length; // 行数
        int col = matrix[0].length; // 列数
        int[] countForRow = new int[row]; // 每一行的指针
        //维护一个最小堆,堆里记录行数，
        PriorityQueue<Integer> heap = new PriorityQueue<>(
                (i1, i2) -> matrix[i1][countForRow[i1]] - matrix[i2][countForRow[i2]]);
        for (int i = 0; i < row; i++) {
            heap.add(i);
        }
        int count = 1;
        while (count < k) {
            int post = heap.poll();
            countForRow[post]++;
            if (countForRow[post] < col) {
                heap.add(post);
            }
            count++;
        }
        return matrix[heap.peek()][countForRow[heap.peek()]];
    }
```
