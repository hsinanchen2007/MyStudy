```
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int r = mat.length;
        int c = mat[0].length;
        ArrayList<Integer>[] memo = new ArrayList[c+1];
        for (int i=0; i<memo.length; i++)
            memo[i] = new ArrayList<>();
        for (int i=0; i<r; i++) {
            int j = 0;
            while (j < c && mat[i][j] == 1) j++;
            memo[j].add(i);
        }
        int[] ans = new int[k];
        int cnt = 0;
        for (int i=0; i<memo.length; i++) {
            for (int j=0; j<memo[i].size(); j++) {
                ans[cnt++] = memo[i].get(j);
                if (cnt == k) break;
            }
            if (cnt == k) break;
        }
        return ans;
    }
}
```