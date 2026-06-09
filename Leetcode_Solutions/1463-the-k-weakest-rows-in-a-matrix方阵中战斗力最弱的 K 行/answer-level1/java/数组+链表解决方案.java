### 解题思路
m行n列的矩阵，矩阵每个位置的值为1，也就是说，每行求和的值最多为n，要求和最小的k行，可以考虑用个n+1的数组，数组中的值是和为数组下标的矩阵行序号并从小到大有序排列。


### 代码

```java
/**
* 3ms 44.7MB
*/
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        LinkedList<Integer>[] lm = new LinkedList[n+1];
//        int[] sum = new int[m];
        for (int i = 0; i < m; i++) {
            int[] numArr = mat[i];
            int s = 0;
            for (int value : numArr) {
                s += value;
            }
//            sum[i] = s;
            putToList(lm, i, s);
        }
        int[] res = new int[k];
        int i = 0;
//      注意这里的循环终止条件 j<=n
        for (int j = 0; j <= n; j++) {
            LinkedList<Integer> l = lm[j];
//          注意这里的条件
            while (l != null && l.peek() != null && i < k) {
                int x = l.poll();
                res[i++] = x;
            }
            if (i >= k) {
                break;
            }
        }
        return res;
    }

    private void putToList(LinkedList<Integer>[] lm, int arrInx, int arrSum) {
        if (lm[arrSum] == null) {
            lm[arrSum] = new LinkedList<>();
        }
        lm[arrSum].add(arrInx);
    }
}
```
