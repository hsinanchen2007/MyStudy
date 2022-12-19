### 解题思路
先把每一行军人数累加存到数组arr里；同时求出一行中最小和最大军人数min,max;
在arr中从min开始遍历到max，每找到一个arr[m]符合，就把m存进去,res结果集的idx就加1
找到k个以后结束。


### 代码

```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int arr[] = new int[mat.length];
        int min = mat[0].length + 1, max = -1;
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                arr[i] += mat[i][j];
            }
            min = Math.min(min, arr[i]);
            max = Math.max(max, arr[i]);
        }
        int res[] = new int[k];
        int minIdx = 0;
        OUTL: for (int v = min; v <= max; v++) { // 每一行军人人数min -> max
            for (int m = 0; m < mat.length; m++) {
                if (arr[m] == v){
                    res[minIdx++] = m;
                    if (minIdx == k) break OUTL;
                }
            }
        }
        return res;
    }
}
```