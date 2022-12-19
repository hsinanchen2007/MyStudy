
执行用时 :1 ms, 在所有 Java 提交中击败了99.67%的用户
内存消耗 :39.5 MB, 在所有 Java 提交中击败了74.12%的用户

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        //直接在原数组上操作，相对节省内存
        for (int row = 0; row < A.length; row++) {
            //遍历行
            int[] rowA = A[row];
            if (rowA.length == 1) {
                //一行一列 要单独处理
                rowA[0] = rowA[0] == 0 ? 1 : 0;
            }
            for (int i = 0; i < rowA.length / 2; i++) {
                //常规的对数组逆序，交换值的过程中把反转也顺便做了
                int tmp = rowA[i];
                rowA[i] = rowA[rowA.length - i - 1] == 0 ? 1 : 0;
                rowA[rowA.length - i - 1] = tmp == 0 ? 1 : 0;
                if (i == rowA.length/2-1 && rowA.length % 2 == 1) {
                    //如果该行数量是奇数，则要在for循环的最后一次执行中对最中间的数进行反转
                    rowA[rowA.length / 2] = rowA[rowA.length / 2] == 0 ? 1 : 0;
                }
            }
        }
        return A;
    }
}
```
