### 解题思路
题目要找的是连续递增的序列，且方向只能是上，下，左，右4个方向，**所以可以先从一个格子开始找，对比它4周的格子，有没有比它小的，如果有，比如有A，B，C三个格子都比它小，那么当前格子的最大连续递增长度就是这3个格子的最大连续递增长度中的最大值+1（有点绕，多读两遍应该就可以理解了）**，那么A，B，C的最大长度从哪里来呢，答案肯定是递归去找，直到找到一个比它四周都小的格子，当前格子长度就定为1，至此，整个思路就缕清了，需要用一个与matrix一样大小的数组来存放每一个格子的最大递增长度
时间复杂度：O(m*n)  需要将整个数组遍历一遍，由于有visited记录，不会重复遍历
空间复杂度：O(m*n)  需要一个与matrix同样大小的数组，记录已经访问过的格子

注意：由于题中是连续递增的，所以不会出现成环的情况
### 代码

```java
class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        if(matrix.length == 0){
            return 0;
        }
        //visited有两个作用：1.判断是否访问过，2.存储当前格子的最长递增长度
        int[][] visited = new int[matrix.length][matrix[0].length];
        int max = 0;
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[0].length; j++){
                if(visited[i][j] == 0){
                    //这里先做一次比较找出max，可以避免最后再去遍历一个visited数组
                    max = Math.max(max, dfs(i, j, matrix, visited));
                }
                max = Math.max(max, visited[i][j]);
                
            }
        }
        return max;
    }
    public int dfs(int i, int j, int[][] matrix, int[][] visited){
        if(i < 0 || i >= matrix.length || j < 0 || j >= matrix[0].length){
            return 0;
        }
        if(visited[i][j] > 0){
            return visited[i][j];
        }
        int max = 0;
        //这里分别去判断4周是否比当前数小，然后去递归遍历
        if(i - 1 >= 0 && matrix[i-1][j] < matrix[i][j]){
            max = Math.max(max, dfs(i-1, j, matrix, visited));
        }
        if(i + 1 < matrix.length && matrix[i+1][j] < matrix[i][j]){
            max = Math.max(max, dfs(i+1, j, matrix, visited));
        }
        if(j - 1 >= 0 && matrix[i][j-1] < matrix[i][j]){
            max = Math.max(max, dfs(i, j-1, matrix, visited));
        }
        if(j + 1 < matrix[0].length && matrix[i][j+1] < matrix[i][j]){
            max = Math.max(max, dfs(i, j+1, matrix, visited));
        }
        
        visited[i][j] = max+1;
        return max+1;

    }
}
```