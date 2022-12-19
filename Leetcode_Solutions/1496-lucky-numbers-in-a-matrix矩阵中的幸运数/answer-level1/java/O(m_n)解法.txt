用两个数组分别记录行最小和列最大值，然后再扫描下对比matrix[i][j]是否是行最小、列最大。

```
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int m = matrix.length;
        if(m == 0) return ans;
        int n = matrix[0].length;
        int[] minRow = new int[m];
        int[] maxCol = new int[n];
        
        for(int i=0;i<m;i++) {
            int min = matrix[i][0];
            for(int j=1;j<n;j++)
                min = Math.min(min, matrix[i][j]);
            minRow[i] = min;
        }
        
        for(int i=0;i<n;i++) {
            int max = matrix[0][i];
            for(int j=1;j<m;j++)
                max = Math.max(max, matrix[j][i]);
            maxCol[i] = max;
        }
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j])
                    ans.add(matrix[i][j]);
            }
        }
        return ans;
    }
}
```
