### 解题思路
![QQ截图20200314185043.png](https://pic.leetcode-cn.com/6907268d293d8748e0adfcef0b7f88ca7edc22654ca921bc0a60755e6bc751c2-QQ%E6%88%AA%E5%9B%BE20200314185043.png)

这题还用写动态规划方程吗？
m[i][j]表示从[0][0]到[i][j]的最短路径长
m[i][j]=min(m[i-1][j]+g[i][j],m[i][j-1]+g[i][j])

主要是只能往下和往右走，一下子就限制住了可能的走法，走到[i][j]时，只有两种可能：要么是从左边来的，要么是从上边来的
开辟一块dp_route存走法，一波递归跑出来，走的最短路径就打印出来辣

这波啊，这波是肉蛋葱鸡！
### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
          int m=grid.length;//m行
        int n=grid[0].length;//n列
        int [][] dp_min=new int[m][n];
        dp_min[0][0]=grid[0][0];//初始化
        int [][] dp_route=new int[m][n];//dp_route[i][j]描述到这一步的最短路径是怎么来的，0表示从左边来的，1表示从上边来的
        dp_route[0][0]=0;

        for(int i=1;i<m;i++){//首列，只能从上边来
            dp_min[i][0]=dp_min[i-1][0]+grid[i][0];
            dp_route[i][0]=1;
        }
        for(int j=1;j<n;j++){//首行，只能从左边来
            dp_min[0][j]=dp_min[0][j-1]+grid[0][j];
            dp_route[0][j]=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(dp_min[i-1][j]+grid[i][j]<dp_min[i][j-1]+grid[i][j]){//来自上边
                    dp_min[i][j]=dp_min[i-1][j]+grid[i][j];
                    dp_route[i][j]=1;
                }else{//来自左边
                    dp_min[i][j]=dp_min[i][j-1]+grid[i][j];
                    dp_route[i][j]=0;
                }
            }
        }
        //打印最短路径
        String route=print_min_route(m-1,n-1,grid,dp_route);
        route=route.substring(0,route.length()-2);
        System.out.println(route);



        return dp_min[m-1][n-1];

    }
    String print_min_route(int i,int j,int [][] grid,int [][]dp_route){//0表示从左边来的，1表示从上边来的
        if(i==0&&j==0) return grid[i][j]+"->";
        if(dp_route[i][j]==0) return print_min_route(i,j-1,grid,dp_route)+grid[i][j]+"->";
        if(dp_route[i][j]==1) return print_min_route(i-1,j,grid,dp_route)+grid[i][j]+"->";
        else{//不可能执行到else
            System.out.println("error");
            return "";
        }


    }
}
```