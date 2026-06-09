### 解题思路
![QQ截图20200408223140.png](https://pic.leetcode-cn.com/5afc67b8df6be3bfaf5945b5d5be8aae00977969a65924ce63c488a5ac0020c8-QQ%E6%88%AA%E5%9B%BE20200408223140.png)

算是入门DP题吧，因为状态转移规则就明摆在题目里，不用自己再猜了。
我这里又跑了一波递归输出的可行路径，和63题64题完全一个做法
https://leetcode-cn.com/problems/minimum-path-sum/solution/zhe-shi-wo-zuo-guo-de-zui-jian-dan-de-dong-tai-gui/

### 代码

```java
class Solution {
    List res=new ArrayList<ArrayList <Integer>>();//因为要递归，用全局变量免得递归函数传参了
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;
        int [][] dp_route=new int[m][n];//是怎么来到当前节点的
        //当前节点本身不是障碍物，且可以从上面或者左面走过来，才算能到达当前节点
        //dp[i][j]= -1:表示到不了i,j
        //        =0：表示从左面来可到i,j
        //        =1:表示从上面来可到i,j

        if(obstacleGrid[0][0]==1) return res;
        

        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==0&&dp_route[i-1][0]!=-1) dp_route[i][0]=1;//可以从上面来
            else dp_route[i][0]=-1;
        }
        for(int j=1;j<n;j++){
            if(obstacleGrid[0][j]==0&&dp_route[0][j-1]!=-1) dp_route[0][j]=0;//可以从左面来
            else dp_route[0][j]=-1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0) {//先保证当前节点不是障碍物
                    if(dp_route[i-1][j]!=-1) dp_route[i][j]=1;//可以从上面来，判断它在前表示优先选择上面，能从上面来尽量从上面来
                    else if(dp_route[i][j-1]!=-1) dp_route[i][j]=0;
                    else dp_route[i][j]=-1;
                }else{//当前节点是障碍物
                    dp_route[i][j]=-1;
                }
            }
        }
        if(dp_route[m-1][n-1]==-1) return res;//不可达，直接返回
        
        
        print_min_route(m-1,n-1,dp_route);


        return res;
    }
    void  print_min_route(int i,int j,int [][]dp_route){//0表示从左边来的，1表示从上边来的
        if(i==0&&j==0) {
            res.add(new int[]{0,0});
            return;
            }
        if(dp_route[i][j]==0)  {
            print_min_route(i,j-1,dp_route);
        }
        if(dp_route[i][j]==1)  {
            print_min_route(i-1,j,dp_route);
        }
        res.add(new int[]{i,j});
    }
}
```