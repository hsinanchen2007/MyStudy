具体参考螺旋矩阵I的解法 如下

[力扣](https://leetcode-cn.com/problems/spiral-matrix/solution/javati-mu-xiang-jie-jian-dan-ming-liao-by-percy-6/)
https://leetcode-cn.com/problems/spiral-matrix/solution/javati-mu-xiang-jie-jian-dan-ming-liao-by-percy-6/
这里我们不需要visited矩阵，外层判断就是数字是否填写到最大值；内层判断把visited[x][y]改为ans[x][y]==0;
```
public int[][] generateMatrix(int n) {
        //List<Integer> ans = new ArrayList();
        int[][] ans = new int[n][n];
        //int h = n;
        if (n==0) return ans;
        //int w = n;
        boolean[][] visited = new boolean[n][n];
        int[][] d = new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
        int x = 0;
        int y = 0;
        int step = 0;
        int num = 1;
        while (num<=n*n) {
            
            while (x>=0 && x<n && y>=0 && y<n && ans[x][y]==0) {
                ans[x][y] = num++;
                //visited[x][y] = true;
                x += d[step][0];
                y += d[step][1];
            }
            x -= d[step][0];
            y -= d[step][1];
            step++;
            if (step>3) step=0;
            if (x>=0 && x<n && y>=0 && y<n){
                x+=d[step][0];
                y+=d[step][1];
            } 
            
        }
        return ans;
    }
```