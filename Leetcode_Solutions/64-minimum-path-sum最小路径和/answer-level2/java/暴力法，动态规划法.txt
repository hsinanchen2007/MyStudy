//暴力法 
// class Solution {
//     int min = Integer.MAX_VALUE;
//     public int minPathSum(int[][] grid) {
        
//         int i = 0;
//         int j = 0;
        
//         int sum = 0;
        
//         backtrack(i,j,grid,sum);
        
//         return min;
        
//     }
    
//     public void backtrack(int i,int j,int[][] grid,int sum)
//     {
//         if(i==grid.length-1 && j==grid[0].length-1)
//         {
//             sum=sum+grid[i][j];
//             min=Math.min(min,sum);
//             System.out.println(sum);
//         }
//         else if(i>=grid.length || j>=grid[0].length)
//         {
            
//         }
//         else
//         {
//             sum=sum+grid[i][j];
//             backtrack(++i,j,grid,sum);
//             backtrack(--i,++j,grid,sum);
//         }
//     }
// }

//动态规划
// class Solution {
//     public int minPathSum(int[][] grid) {
        
//         int m = grid.length;
//         int n = grid[0].length;
        
//         int[][] dp = new int[m][n];
        
//         int sum = 0;
        
//         for(int i=0;i<m;i++)
//         {
//             sum=sum+grid[i][0];
//             dp[i][0]=sum;
//         }
        
//         sum=0;
//         for(int j=0;j<n;j++)
//         {
//             sum=sum+grid[0][j];
//             dp[0][j]=sum;
//         }
        
//         for(int i=1;i<m;i++)
//         {
//             for(int j=1;j<n;j++)
//             {
//                 dp[i][j]=Math.min(dp[i-1][j],dp[i][j-1])+grid[i][j];
//             }
//         }
        
//         return dp[m-1][n-1];
//     }
// }

//动态规划
class Solution {
    public int minPathSum(int[][] grid) {
        
        int m = grid.length;
        int n = grid[0].length;
        
        int sum = 0;
        
        int[] dp = new int[m];
        
        for(int i=0;i<m;i++)
        {
            sum=sum+grid[i][0];
            dp[i]=sum;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                {
                    dp[j]=dp[0]+grid[0][i];
                }
                else
                {
                    dp[j]=Math.min(dp[j],dp[j-1])+grid[j][i];
                }
            }
        }
        return dp[m-1];
    }
}