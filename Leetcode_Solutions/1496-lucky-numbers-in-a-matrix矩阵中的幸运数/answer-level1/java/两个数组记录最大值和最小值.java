min数组存放每行最小值;
man数组存放每列最大值;
循环比较得到每一行的最小值和每一列的最大值。
然后比较第i行最小值和第j列最大值是否为同一个数，即min[i] == max[j]
```
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] min = new int[m];
        int[] max = new int[n];
        Arrays.fill(min, Integer.MAX_VALUE);
        Arrays.fill(max, Integer.MIN_VALUE);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                min[i] = Math.min(min[i], matrix[i][j]);// 第i行最小值
                max[j] = Math.max(max[j], matrix[i][j]);// 每一列最大值与当前值比较
            }
        }

        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (min[i] == max[j])
                    list.add(min[i]);
            }
        }

        return list;
    }
}
```
