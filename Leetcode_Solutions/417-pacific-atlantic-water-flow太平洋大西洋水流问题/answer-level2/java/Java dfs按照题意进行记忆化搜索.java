### 解题思路
代码应该比较通俗易懂，注释在代码中

### 代码

```java
class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>> lists = new ArrayList<List<Integer>>();
        int row = matrix.length;
        if(row<1) return lists;
        int col = matrix[0].length;
        if(col<1) return lists;
        /*
        * 判断这个节点(i,j)是否访问过,防止上下左右遍历时，进行重复遍历，
        * 例如(i,j)->(i-1,j)->(i,j)进行了简单的重复遍历
        */
        boolean[][] visit = new boolean[row][col];
        //记忆化处理，防止超时，对于前面已经求出的可以流入太平洋，大西洋的陆地进行记录
        int[][] memo = new int[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int res = dfs(i,j,row,col,matrix,visit,memo);
                if(res==12){
                    List<Integer> list = new ArrayList<Integer>();
                    list.add(i);
                    list.add(j);
                    lists.add(list);
                }
            }
        }
        return lists;
    }

    /*
    * r当前行下标
    * c当前列下标
    * row maxtrix数组的行数
    * col maxtrix数组的列数
    * visit 判断这个节点(i,j)是否访问过,防止上下左右遍历时，进行重复遍历
    * memo 记忆化处理，防止超时
    *       注意此处memo中的值，8代表可以流入太平洋，4代表可以流入大西洋，0代表既不能流入大西洋也不能流入太平洋
    *       8二进制(1000) 4(0100) 0(0000) 他们"或"起来为12,代表可以流入太平洋跟大西洋
    */
    public int dfs(int r, int c, int row, int col, int[][] matrix, boolean[][] visit, int[][] memo){
        if(memo[r][c]==12) return memo[r][c];
        if(r==0 && c==col-1){//左上角节点
            memo[r][c] = 12;
            return 12;//都能到达
        } 
        if(r==row-1 && c==0){//右下角节点
            memo[r][c] = 12;
            return 12;
        } 
        int up = 0;//往上搜索
        int down = 0;
        int left = 0;
        int right = 0;
        //边界条件处理
        if(r==0) up = 8;//太平洋
        if(r==row-1) down = 4;//大西洋
        if(c==0) left = 8;
        if(c==col-1) right = 4;

        if(r-1>=0 && matrix[r][c]>=matrix[r-1][c] && !visit[r-1][c]){//往上搜索
            visit[r][c] = true;
            up = dfs(r-1,c,row,col,matrix,visit,memo);
            visit[r][c] = false;
        }
        if(r+1<row && matrix[r][c]>=matrix[r+1][c] && !visit[r+1][c]){//往下搜索
            visit[r][c] = true;
            down = dfs(r+1,c,row,col,matrix,visit,memo);
            visit[r][c] = false;
        }
        if(c-1>=0 && matrix[r][c]>=matrix[r][c-1] && !visit[r][c-1]){//往左搜索
            visit[r][c] = true;
            left = dfs(r,c-1,row,col,matrix,visit,memo);
            visit[r][c] = false;
        }
        if(c+1<col && matrix[r][c]>=matrix[r][c+1] && !visit[r][c+1]){//往右搜索
            visit[r][c] = true;
            right = dfs(r,c+1,row,col,matrix,visit,memo);
            visit[r][c] = false;
        }
        int value = (up|down|left|right);//二进制‘或’起来
        memo[r][c] = value;
        return value;
    }
}
```