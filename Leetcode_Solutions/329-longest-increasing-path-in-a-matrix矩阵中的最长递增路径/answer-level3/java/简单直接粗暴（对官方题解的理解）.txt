    //坐标走的四个方向：{↑，→，↓，←}
    public static final int[][] directiont=new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
    public static int m,n;//m为行数，n为列数
    public static int longestIncreasingPath(int[][] matrix) {
        if (matrix.length == 0) {return 0;}
        int result=0;
        m = matrix.length;
        n = matrix[0].length;
        int[][] cache=new int[m][n];//保存从当前节点能走的最远距离。
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //从每一个结点开始，看看哪一个结点走的最远。
            result=Math.max(result,dfSearch(matrix,i,j,cache));
            }
        }
        return result;
    }
    public static int dfSearch(int[][] matrix,int i,int j,int[][] cache){
        //深度优先遍历
        if(cache[i][j] != 0){
            return cache[i][j];//如果当前节点在缓存里已经走过，直接返回当前节点的最远距离即可，不需要继续找了
        }
        for(int[] d:directiont){
            int x=i+d[0];
            int y=j+d[1];//选择一个方向；
            if(0<=x && x < m &&  0<=y && y <n && matrix[x][y] >matrix[i][j]){
                //满足边界条件，再满足下一步走的大于当前值，不满足则返回，另外找上一次没用过的方向
                //直到找到，并找出走的最远的那个步数。
                cache[i][j]=Math.max(cache[i][j],dfSearch(matrix, x, y,cache));
            }
        }
        return ++cache[i][j];//+1是因为当前进一步。
    }