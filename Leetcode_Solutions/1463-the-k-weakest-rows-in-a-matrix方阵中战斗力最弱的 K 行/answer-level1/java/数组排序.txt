首先计算`mat`的每行的军人数量，用一个新数组记录每一行的下标和军人数量。然后对新数组排序，排序依据是首先根据军人数量升序排序，如果军人数量相同，则根据下标升序排序。排序后，返回前`k`行的下标。
```
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        if (mat == null || mat.length == 0 || mat[0].length == 0)
            return new int[0];
        int rows = mat.length, columns = mat[0].length;
        int[][] indexCount = new int[rows][2];
        for (int i = 0; i < rows; i++) {
            int rowCount = 0;
            for (int j = 0; j < columns; j++) {
                if (mat[i][j] == 1)
                    rowCount++;
            }
            indexCount[i][0] = i;
            indexCount[i][1] = rowCount;
        }
        Arrays.sort(indexCount, new Comparator<int[]>() {
            public int compare(int[] array1, int[] array2) {
                if (array1[1] != array2[1])
                    return array1[1] - array2[1];
                else
                    return array1[0] - array2[0];
            }
        });
        int[] kWeakest = new int[k];
        for (int i = 0; i < k; i++)
            kWeakest[i] = indexCount[i][0];
        return kWeakest;
    }
}
```
