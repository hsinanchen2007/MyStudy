设置两个boolean类型的数组buffer1和buffer2分别存储是否能够流到太平洋和大西洋。
采用广度优先搜索，以太平洋为例：
首先从太平洋岸边的位置matrix[i][j]开始(即matrix矩阵的第一排元素和第一列元素),这些位置肯定可以流向太平洋(buffer[i][j] = 1)。
然后判断四周位置matrix[i'][j']是否可以流向matrix[i][j]，如果可以流向matrix[i][j]，则buffer1[i'][j'] = 1 。
再从四周位置中可以流到matrix[i][j]的位置matrix[i'][j']递归判断其周围的位置是否可以流向它。
终止条件为matrix[i][j]四周的位置都无法流向它。
同理可得到buffer2。
最后buffer1和buffer2对应元素同为1的位置为本问题的解。
```
class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>> result = new ArrayList<>();
        if(matrix.length == 0 || matrix[0].length == 0){
            return result;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        boolean[][] buffer1 = new boolean[m][n];
        boolean[][] buffer2 = new boolean[m][n];
        for(int i = 0; i < m; ++i){
            buffer1[i][0] = true;
            traverse(matrix, buffer1, i, 0);()
        }
        for(int j = 0; j < n; ++j){
            buffer1[0][j] = true;
            traverse(matrix, buffer1, 0, j);
        }
        for(int i = 0; i < m; ++i){
            buffer2[i][n-1] = true;
            traverse(matrix, buffer2, i, n-1);
        }
        for(int j = 0; j < n; ++j){
            buffer2[m-1][j] = true;
            traverse(matrix, buffer2, m-1, j);
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(buffer1[i][j] && buffer2[i][j])
                    result.add(Arrays.asList(i, j));
            }
        }
        return result;
    }
    private void traverse(int[][] matrix, boolean[][] buffer, int i, int j){
        if(i > 0 && !buffer[i-1][j] && matrix[i-1][j] >= matrix[i][j]){
            buffer[i-1][j] = true;
            traverse(matrix, buffer, i-1, j);
        }
        if(j > 0 && !buffer[i][j-1] && matrix[i][j-1] >= matrix[i][j]){
            buffer[i][j-1] = true;
            traverse(matrix, buffer, i, j-1);
        }
        if(i < matrix.length - 1 && !buffer[i+1][j] && matrix[i+1][j] >= matrix[i][j]){
            buffer[i+1][j] = true;
            traverse(matrix, buffer, i+1, j);
        }
        if(j < matrix[0].length - 1 && !buffer[i][j+1] && matrix[i][j+1] >= matrix[i][j]){
            buffer[i][j+1] = true;
            traverse(matrix, buffer, i, j+1);
        }
    }
}
```
![捕获.PNG](https://pic.leetcode-cn.com/d87969cf175fb496fe3f462d2ac7e90a2e3b45e39b6612d3653d8a1c39bd6c66-%E6%8D%95%E8%8E%B7.PNG)
