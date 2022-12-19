```
class Solution {
    public int[] pondSizes(int[][] land) {
        List<Integer> list = new ArrayList<>();
        for (int i=0; i<land.length; i++)
            for (int j=0; j<land[0].length; j++)
                if (land[i][j] == 0) {
                    list.add(dfs(land, i, j));
                }
        int[] ans = new int[list.size()];
        for (int i=0; i<ans.length; i++)
            ans[i] = list.get(i);
        Arrays.sort(ans);
        return ans;
    }

    private int dfs(int[][] land, int x, int y) {
        if (x < 0 || x >= land.length || y < 0 || y >= land[0].length || land[x][y] != 0)
            return 0;
        land[x][y] = -1;
        int ans = 1;
        for (int i=-1; i<=1; i++)
            for (int j=-1; j<=1; j++) 
                if (i != 0 || j != 0)
                    ans += dfs(land, x+i, y+j);
        return ans;
    }
}
```