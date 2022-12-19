### 解题思路
此处撰写解题思路
从边界开始向内搜索，只要满足条件就设为true，最后如果都能到达，则可以加入到结果集中。
### 代码

```java
class Solution {
    private int m,n;
    private int[][]a;
    private int[][]move={{0,1},{0,-1},{-1,0},{1,0}};
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>>ret=new ArrayList<>();
        if(matrix==null||matrix.length==0) return ret;
        m=matrix.length;
        n=matrix[0].length;
        a=matrix;
        
        boolean[][]reachP=new boolean[m][n];
        boolean[][]reachA=new boolean[m][n];
        for(int i=0;i<m;i++){
            dfs(i,0,reachP);
            dfs(i,n-1,reachA);
        }
        for(int i=0;i<n;i++){
            dfs(0,i,reachP);
            dfs(m-1,i,reachA);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(reachP[i][j]&&reachA[i][j]){
                    List<Integer>list=new ArrayList<>();
                    list.add(i);
                    list.add(j);
                    ret.add(list);
                }
            }
        }
        return ret;
    }
    private void dfs(int i,int j,boolean[][]reach){
        if(reach[i][j]) return;
        reach[i][j]=true;
        for(int k=0;k<4;k++){
            int ti=i+move[k][0];
            int tj=j+move[k][1];
            if(ti>=0&&ti<m&&tj>=0&&tj<n&&a[i][j]<=a[ti][tj])
            dfs(ti,tj,reach);
        }
    }
}
```