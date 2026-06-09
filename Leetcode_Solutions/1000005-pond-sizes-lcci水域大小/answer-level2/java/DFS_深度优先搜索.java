如果一个点是水域，那么，我们尝试往这个点邻接的八个方向尝试去走，如果刚好也是水域的话，那么继续递归，否则递归结束。
这里提供一个排序算法是：希尔排序。
```
class Solution {
    public int[] pondSizes(int[][] land) {
        if (land.length == 0 || land[0].length == 0)
            return new int[0];
        List<Integer> list = new ArrayList<>();
        int rows = land.length, cols = land[0].length;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (land[row][col] == 0) {
                    list.add(dfs(land, row, col));
                }
            }
        }
        
        int[] ans = new int[list.size()];
        for (int i = 0; i < list.size(); ++i) {
            ans[i] = list.get(i);
        }
        
        shellSort(ans);
        
        return ans;
    }
    
    private int dfs(int[][] land, int x, int y) {
        if (x < 0 || x >= land.length || y < 0 || y >= land[0].length || land[x][y] != 0)
            return 0;
        int sum = 1;
        land[x][y] = 1;
        sum += dfs(land, x, y + 1);
        sum += dfs(land, x, y - 1);
        sum += dfs(land, x - 1, y + 1);
        sum += dfs(land, x - 1, y - 1);
        sum += dfs(land, x + 1, y + 1);
        sum += dfs(land, x + 1, y - 1);
        sum += dfs(land, x + 1, y);
        sum += dfs(land, x - 1, y);
        
        return sum;
    }
    
    
    private void shellSort(int[] nums) {
        int len = nums.length;
        int gap = len >> 1;
        while (gap > 0) {
            for (int i = gap; i < len; i++) {
                int insertNum = nums[i], preIndex = i - gap;
                while (preIndex >= 0 && nums[preIndex] > insertNum) {
                    nums[preIndex + gap] = nums[preIndex];
                    preIndex -= gap;
                }
                nums[preIndex + gap] = insertNum;
            }
            gap >>= 1;
        }
    }
}
```
