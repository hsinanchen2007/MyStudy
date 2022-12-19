### 解题思路
仔细观察题目和所给例题，发现每一个对角线组都是从第一行的每一个元素和第一列每一个元素开始的，那么拿第一行第一个元素mat[0][0]来说，只要将它和mat[0+1][0+1](依次加一下去)加入临时数组temp，在调用排序函数对其排序，然后再从初始mat[0]0]开始依次加入temp即完成一个对角线组的递增排列。

### 代码

```java
class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int temp[] = new int[n];
            temp[count++] = mat[0][i];
            int j = 1, k = i + 1;
            while (j < m && k < n) {//将一个对角线的元素存入数组中
                temp[count++] = (mat[j][k]);
                j++;
                k++;
            }
            Arrays.sort(temp, 0, count);//对数组前count项进行排序
            int r = 0, l = i, count2 = 0;
            while (count > 0) {
                mat[r++][l++] = temp[count2++];//替换原先的对角线元素
                count--;
            }

        }
        for (int i = 0; i < m; i++) {
            int temp[] = new int[m];
            temp[count++] = mat[i][0];
            int j = i + 1, k = 1;
            while (j < m && k < n){
                temp[count++] = (mat[j][k]);
                j++;
                k++;
            }
            Arrays.sort(temp, 0, count);
            int r = i, l = 0, count2 = 0;
            while (count > 0) {
                mat[r++][l++] = temp[count2++];
                count--;
            }
        }
        return mat;
    }
}
```