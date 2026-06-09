
这里我们利用一个方向矩阵来实现螺旋形运动 int[][] d = new int[][]{{0,1},{1,0},{0,-1},{-1,0}};这个矩阵就只是按照螺旋运动，利用step变量来操作；
当运动到边界时进行判断一个判断，为什么是一个。因为在先期的移动中出界后我把他已经移动回来了，这里只需要朝着下一个移动方向移动就可以了；还有就是设定一个布尔矩阵来记录这个点是否访问；
最后判断布尔矩阵全是true就退出；
```
//执行用时 :1 ms, 在所有 Java 提交中击败了92.06%的用户
    //内存消耗 :34 MB, 在所有 Java 提交中击败了88.57%的用户
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList();
        int h = matrix.length;
        if (h==0) return ans;
        int w = matrix[0].length;
        boolean[][] visited = new boolean[h][w];
        int[][] d = new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
        int x = 0;
        int y = 0;
        int step = 0;
        while (!all(visited)) {
            
            while (x>=0 && x<h && y>=0 && y<w && !visited[x][y]) {
                ans.add(matrix[x][y]);
                visited[x][y] = true;
                x += d[step][0];
                y += d[step][1];
            }
            //这里就是出界移动回来的位置
            x -= d[step][0];
            y -= d[step][1];
            step++;
            if (step>3) step=0;
            if (x>=0 && x<h && y>=0 && y<w){
                x+=d[step][0];
                y+=d[step][1];
            } 
            
        }
        return ans;
    }
    public boolean all(boolean[][] v) {
        for (int i = 0;i<v.length;i++) {
            for (int j=0;j<v[0].length;j++) {
                if (v[i][j]==false) return false;
            }
        }
        return true;
    }
```