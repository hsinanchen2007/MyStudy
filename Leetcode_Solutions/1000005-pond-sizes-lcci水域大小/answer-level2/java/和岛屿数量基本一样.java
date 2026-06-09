### 解题思路
和计算岛屿数量基本一样，差异在于对角线的情况，再加上对角线的情况即可。

### 代码

```java
class Solution {
    public int[] pondSizes(int[][] land) {
        int count = 0;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < land.length; i++) {
            for (int j = 0; j < land[i].length; j++) {
                if (land[i][j] == 0) {
                    count = dfs(land, i, j);
                    list.add(count);
                }
            }
        }
        Collections.sort(list);
        int[] result = new int[list.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = list.get(i);
        }
        return result;
    }

    private int dfs(int[][] land, int i, int j) {
        if (i < 0 || j < 0 || i >= land.length || j >= land[i].length || land[i][j] != 0){
            return 0;
        }
        land[i][j] = -1;
        int count = 1;
        count += dfs(land, i + 1, j);
        count += dfs(land, i, j + 1);
        count += dfs(land, i - 1, j);
        count += dfs(land, i, j - 1);
        count += dfs(land, i + 1, j + 1);
        count += dfs(land, i + 1, j - 1);
        count += dfs(land, i - 1, j + 1);
        count += dfs(land, i - 1, j - 1);
        return count;
    }
}
```