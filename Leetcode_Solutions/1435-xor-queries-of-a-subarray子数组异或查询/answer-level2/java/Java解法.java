```
class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int m = queries[i][0];
            int n = queries[i][1];
            int s = arr[m];
            for (int j = m + 1; j <= n; j++) {
                s = s ^ arr[j];
            }
            result[i] = s;
        }
        return result;
    }
    
}
```
