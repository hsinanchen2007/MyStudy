![360截图20200329181626931.jpg](https://pic.leetcode-cn.com/45100c077845f4d0832c5fdc33cc646c0f720d9fa9cb99a7b2522bcadfaac540-360%E6%88%AA%E5%9B%BE20200329181626931.jpg)

```
class Solution {
    boolean[][][] canArrive;
    boolean[][] visited;
    int[][] direct = new int[][]{{1,0},{-1,0},{0,1},{0,-1}};
    List<List<Integer>> ret = new ArrayList<>();
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        if(matrix==null || matrix.length==0 || matrix[0].length==0) return ret;
        visited=new boolean[matrix.length][matrix[0].length];
        canArrive=new boolean[matrix.length][matrix[0].length][2];
        for(int i=0;i<matrix.length;++i){
            for(int j=0;j<matrix[0].length;++j){
                if(canArrive[i][j][0] && canArrive[i][j][1]) continue;
                canArrive[i][j][0] = canArrive[i][j][0] || (i==0 || j==0);
                canArrive[i][j][1] = canArrive[i][j][1] || (i==matrix.length-1 || j==matrix[0].length-1);
                visited[i][j]=true;
                DFS(matrix,i,j);
                visited[i][j]=false;
            }
        }
        for(int i=0;i<matrix.length;++i){
            for(int j=0;j<matrix[0].length;++j){
                if(canArrive[i][j][0] && canArrive[i][j][1]) {
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(i);  tmp.add(j);
                    ret.add(tmp);
                }
            }
        }
        return ret;
    }
    boolean DFS(int[][] matrix,int i, int j){
        if(canArrive[i][j][0] && canArrive[i][j][1]){
            return true;
        }
        for(int[] d:direct){
            int ni = i+d[0];
            int nj=j+d[1];
            if(ni<0||ni>matrix.length-1|| nj<0 || nj>matrix[0].length-1 || visited[ni][nj] || matrix[i][j]<matrix[ni][nj]) continue;

            canArrive[ni][nj][0] = canArrive[ni][nj][0] || (ni==0 || nj==0);
            canArrive[ni][nj][1] = canArrive[ni][nj][1] || (ni==matrix.length-1 || nj==matrix[0].length-1);
            visited[ni][nj]=true;
            boolean ret = DFS(matrix,ni,nj);
            visited[ni][nj]=false;
            canArrive[i][j][0] = canArrive[i][j][0] || canArrive[ni][nj][0];
            canArrive[i][j][1] = canArrive[i][j][1] || canArrive[ni][nj][1];

            if(ret || canArrive[i][j][0] && canArrive[i][j][1]) return true;
        }
        return false;
    }
}

```
